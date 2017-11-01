// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		sys_processor.cpp
//		Purpose:	Processor Emulation.
//		Created:	26th October 2015
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#ifdef WINDOWS
#include <stdio.h>
#endif
#include "sys_processor.h"
#include "hardware.h"

// *******************************************************************************************************************************
//														Main Memory/CPU
// *******************************************************************************************************************************

static BYTE8 ramMemory[RAMSIZE];													// RAM memory
static BYTE8 interruptEnabled,interruptRequest;

static BYTE8 A,B,C,D,E,H,L,HALT,CARRY,PSZV,STIX,MBR;
static WORD16 MAR,CYCLES,T16,STACK[8];

// *******************************************************************************************************************************
//													Memory read and write macros.
// *******************************************************************************************************************************

#define READ(a) 	ramMemory[(a) & MEMORYMASK]
#define WRITE(a,d) 	ramMemory[(a) & MEMORYMASK] = (d)

#define PCTR 		STACK[STIX]

// *******************************************************************************************************************************
//														I/O Port connections
// *******************************************************************************************************************************

#include "_8008_ports.h"

// *******************************************************************************************************************************
//													  Port interfaces
// *******************************************************************************************************************************

void CPUReset(void) {
	A = B = C = D = E = H = L = HALT = 0;
	CARRY = PSZV = CYCLES = STIX = 0;
	interruptRequest = 0;interruptEnabled = 0;
	HWIReset();

	WRITE(0x00,0x46);
	WRITE(0x01,0x80);
	WRITE(0x02,0x01);
	WRITE(0x03,0x2C);
	WRITE(0x04,0x44);
	WRITE(0x180,0x46);
	WRITE(0x181,0x82);
	WRITE(0x182,0x03);
}

// *******************************************************************************************************************************
//										 Arithmetic
// *******************************************************************************************************************************

static BYTE8 parityeven(BYTE8 n) {
	BYTE8 parity = 0;
	while (n != 0) {
		if ((n & 1) != 0) parity++;
		n = n >> 1;
	}
	return (parity & 1) == 0;
}


// *******************************************************************************************************************************
//												    Request an interrupt
// *******************************************************************************************************************************

void CPUInterruptRequest(void) {
	interruptRequest = 1;
}

// *******************************************************************************************************************************
//													 Execute a single phase.
// *******************************************************************************************************************************

#include <stdlib.h>
#include <stdio.h>

BYTE8 CPUExecuteInstruction(void) {
	if (interruptRequest != 0) {													// Interrupted.
		interruptRequest = 0;														// Clear IRQ flag
		if (interruptEnabled != 0) {												// Is interrupt enabled.
			HALT = 0;																// Clear Halt flag.
			// TODO: What do we do ?
			return 0;
		}
	}
	if (HALT == 0) {																// CPU is running (not halt)
		BYTE8 opcode = READ(PCTR);
		PCTR = (PCTR+1) & 0x3FFF;
		switch(opcode) {															// Do the selected opcode and phase.
			#include "_8008_case.h"
		}
	}	
	if (HALT == 0 && CYCLES < CYCLES_PER_FRAME) return 0;							// Frame in progress, return 0.
	CYCLES -= CYCLES_PER_FRAME;														// Adjust cycle counter
	if (HALT != 0) CYCLES = 0;														// Fix up for HALT.
	HWIEndFrame();																	// Hardware stuff.
	return FRAME_RATE;																// Return the frame rate for sync speed.
}

#ifdef INCLUDE_DEBUGGING_SUPPORT

// *******************************************************************************************************************************
//										 Get the step over breakpoint value
// *******************************************************************************************************************************

WORD16 CPUGetStepOverBreakpoint(void) {
	BYTE8 opcode = CPURead(PCTR);											// Read opcode.
	if ((opcode & 0xC7) == 0x07) return ((PCTR+1) & 0x3FFF);				// RST xx
	if ((opcode & 0xC3) == 0x42) return ((PCTR+3) & 0x3FFF);				// CALL xxxx (various calls)
	return 0xFFFF;
}

// *******************************************************************************************************************************
//										Run continuously till breakpoints / Halt.
// *******************************************************************************************************************************

BYTE8 CPUExecute(WORD16 break1,WORD16 break2) {
	BYTE8 rate = 0;
	while(1) {
		rate = CPUExecuteInstruction();												// Execute one instruction phase.
		if (rate != 0) {															// If end of frame, return rate.
			return rate;													
		}
		if (PCTR == break1 || PCTR == break2) return 0;
	} 																				// Until hit a breakpoint or HLT.
}

// *******************************************************************************************************************************
//												Load a binary file into RAM
// *******************************************************************************************************************************

void CPULoadBinary(char *fileName) {
	FILE *f = fopen(fileName,"rb");
	fread(ramMemory,RAMSIZE,1,f);
	fclose(f);
}

// *******************************************************************************************************************************
//												Gets a pointer to RAM memory
// *******************************************************************************************************************************
	
BYTE8 CPURead(WORD16 address) {
	return READ(address);
}

// *******************************************************************************************************************************
//											Retrieve a snapshot of the processor
// *******************************************************************************************************************************

static CPUSTATUS s;																	// Status area

CPUSTATUS *CPUGetStatus(void) {
	s.a = A;s.b = B;s.c = C;s.d = D;s.e = E;s.h = H;s.l = L;						// 8 bit registers
	s.zFlag = (PSZV == 0);s.cFlag = (CARRY != 0);s.hFlag = (HALT != 0);				// Flags
	s.pFlag = (parityeven(PSZV) == 0);s.sFlag = ((PSZV & 0x80) != 0);
	s.interruptEnabled = interruptEnabled;
	s.cycles = CYCLES;																// Number of cycles.
	s.pc = PCTR;
	s.hl = (s.h << 8) | s.l;s.m = CPURead(s.hl & 0x3FFF);							// Helpers
	s.stackDepth = 0;
	for (int s1 = 0;s1 < STIX;s1++) {
		s.stack[s.stackDepth++] = STACK[STIX-s1-1	];
	}
	return &s;
}
#endif
