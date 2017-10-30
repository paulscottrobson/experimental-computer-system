// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		sys_debug_8008.cpp
//		Purpose:	Debugger Code (System Dependent)
//		Created:	29th June 2016
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gfx.h"
#include "sys_processor.h"
#include "sys_debug_system.h"
#include "debugger.h"

static const char *_mnemonics[] = 
#include "_8008_newMnemonics.h"														// 8008 new style mnemonics

#define DBGC_ADDRESS 	(0x0F0)														// Colour scheme.
#define DBGC_DATA 		(0x0FF)														// (Background is in main.c)
#define DBGC_HIGHLIGHT 	(0xFF0)

// *******************************************************************************************************************************
//												Reset the 8008
// *******************************************************************************************************************************

void DBGXReset(void) {
	CPUReset();
}

// *******************************************************************************************************************************
//											This renders the debug screen
// *******************************************************************************************************************************

void DBGXRender(int *address,int showDisplay) {
	int n;
	char buffer[32];
	GFXSetCharacterSize(32,27);

	CPUSTATUS *s = CPUGetStatus();													// Get the CPU Status

	const char *labels[] = { "A","B","C","D","E","H","L","M","C","Z","S","P","H","IE","HL","BP","CY",NULL };
	n = 0;
	while (labels[n] != NULL) {
		GFXString(GRID(15,n+1),labels[n],GRIDSIZE,DBGC_ADDRESS,-1);
		n++;
	}
	const char *labels2[] = { "PC","ST",NULL };
	n = 0;
	while (labels2[n] != NULL) {
		GFXString(GRID(25,n+1),labels2[n],GRIDSIZE,DBGC_ADDRESS,-1);
		n++;
	}

	n = address[1];																	// Dump memory.
	for (int row = 19;row < 26;row++) {
		GFXNumber(GRID(1,row),n & 0x3FFF,16,4,GRIDSIZE,DBGC_ADDRESS,-1);			// Head of line
		GFXCharacter(GRID(6,row),':',GRIDSIZE,DBGC_HIGHLIGHT,-1);
		for (int col = 0;col < 8;col++) {											// Data on line
			GFXNumber(GRID(8+col*3,row),CPURead(n & 0x3FFF),16,2,GRIDSIZE,DBGC_DATA,-1);
			n++;
		}
	}
																					// Output text labels.																					// Macros to simplify dump drawing.
	#define DD(value,width)	GFXNumber(GRID(18,n++),value,16,width,GRIDSIZE,DBGC_DATA,-1)
	#define DDC(value) GFXNumber(GRID(18,n++),value,16,1,GRIDSIZE,DBGC_DATA,-1)

	n = 1;																			// Draw the registers
	DD(s->a,2);DD(s->b,2);DD(s->c,2);DD(s->d,2);DD(s->e,2);DD(s->h,2);DD(s->l,2);DD(s->m,2);
	DDC(s->cFlag);DDC(s->zFlag);DDC(s->sFlag);DDC(s->pFlag);DDC(s->hFlag);			// Draw the flags
	DDC(s->interruptEnabled);
	DD(s->hl,4);DD(address[3],4);DD(s->cycles,4);									// The rest.

	n = 1;																			// PCTR
	GFXNumber(GRID(28,n),s->pc,16,4,GRIDSIZE,DBGC_DATA,-1);
	n++;
	GFXString(GRID(28,n++),"----",GRIDSIZE,DBGC_DATA,-1);							// Translated stack.
	for (int i = 0;i < s->stackDepth;i++) 
		GFXNumber(GRID(28,n++),s->stack[i],16,4,GRIDSIZE,DBGC_DATA,-1);

	//if (showCPU == 0) return;

	n = address[0]; 																// Dump code.
	for (int row = 1;row < 18;row++) {
		int isPC = (n & 0x3FFF) == (s->pc);											// Check for breakpoint and being at PC
		int isBrk = ((n & 0x3FFF) == address[3]);
		GFXNumber(GRID(0,row),n & 0x3FFF,16,4,GRIDSIZE,isPC ? DBGC_HIGHLIGHT : DBGC_ADDRESS,isBrk ? 0xF00 : -1);
		strcpy(buffer,_mnemonics[CPURead(n & 0x3FFF)]);							// Get mnemonic
		n++;
		if (buffer[strlen(buffer)-2] == '%') {										// Replace @1 @2 with 1/2 byte operands
			switch(buffer[strlen(buffer)-1]) {
				case '1':
					sprintf(buffer+strlen(buffer)-2,"%02x",CPURead((n) & 0x3FFF));
					n++;
					break;
				case '2':
					sprintf(buffer+strlen(buffer)-2,"%02x%02x",(CPURead((n+1) & 0x3FFF)) & 0x3F,CPURead((n) & 0x3FFF));
					n += 2;
					break;
			}
		}
		GFXString(GRID(5,row),buffer,GRIDSIZE,isPC ? DBGC_HIGHLIGHT : DBGC_DATA,-1);
	}

	if (showDisplay == 0) return;
}	
