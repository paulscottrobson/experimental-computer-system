// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		hardware.cpp
//		Purpose:	Hardware Interface
//		Date:		1st October 2017
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "sys_processor.h"
#include "hardware.h"
#include "gfx.h"																

// *******************************************************************************************************************************
//										Hardware Reset
// *******************************************************************************************************************************

void HWIReset(void) {

}

// *******************************************************************************************************************************
//											End of frame code.
// *******************************************************************************************************************************

void HWIEndFrame() {
}


// *******************************************************************************************************************************
//										Intercept keyboard processing
// *******************************************************************************************************************************

int HWIProcessKey(int key,int runMode) {
	
	BYTE8 asciiKey = GFXToASCII(key,1);
	if (asciiKey != 0) 	HWIECSKeyMap(asciiKey);

	return key;
}

// *******************************************************************************************************************************
//											Convert ASCII to ECS code.
//
//								< and > return Shift [ and ] ? returns shift #
// *******************************************************************************************************************************

static const char *ECSMapString = "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_ ! #$%&'()*+,-./0123456789:;<=>?";

BYTE8 HWIECSKeyMap(BYTE8 asciiKey) {
	BYTE8 isShift = 0;
	BYTE8 isControl = 0;

	if (asciiKey == 0) return 0xFF; 							// No key pressed

	isShift = isControl = 0; 									// Determined from character code.

	BYTE8 key = asciiKey;
	if (key >= 'a' && key <= 'z') { 							// Lower case back to upper.
		key = key - 32;
		isShift = 1;
	}
	if (key == '<' || key == '>') { 							// Remap < and > onto Shift []
		key = (key == '<') ? '[':']';
		isControl = 1;
	}
	if (key == '?') { 											// Mark ? onto shift #
		key = '#';
		isShift = 1;
	}
	if (key == 13) { 											// CR maps onto >
		key = '>';
	}
	if (key >= 0 and key <= 26) { 								// Bring Ctrl A-Z back.
		key = key + 64;
		isControl = 1;
		isShift = 0;
	}
	if (key != 34) { 											// Look up key in ECS string
		char *pos = strchr((char *)ECSMapString,key);
		if (pos == NULL) return 0xFF;							// Don't recognise it.
		key = pos - ECSMapString; 								// Get position in string.
	}

	key = key | 0xC0; 											// Set upper 2 bits.
	if (isControl) key = key & 0x7F;							// Adjust byte for shift/ctrl
	if (isShift) key = key & 0xBF;								

	//printf("%x %d %d %d\n",key,key,isShift,isControl);
	return key;
}
