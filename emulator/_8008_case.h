case 0x00: /*** halt ***/
    CYCLES = CYCLES + 4; HALT = 1;;break;
case 0x01: /*** halt ***/
    CYCLES = CYCLES + 4; HALT = 1;;break;
case 0x02: /*** rlc ***/
    CYCLES = CYCLES + 5; A = ((A << 1) | (A >> 7)) & 0xFF; CARRY = A & 1;;break;
case 0x03: /*** rnc ***/
    CYCLES = CYCLES + 5; if (CARRY == 0) { STACKIX = (STACKIX-1) & 7; };;break;
case 0x04: /*** adi #%1 ***/
    CYCLES = CYCLES + 8; CARRY = 0; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x05: /*** rst 00 ***/
    CYCLES = CYCLES + 5; T16 = 0x00; STACKIX = (STACKIX+1) & 7; STACK[STACKIX] = T16 & 0x3FFF;;break;
case 0x06: /*** mvi a,#%1 ***/
    CYCLES = CYCLES + 8; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); A = MBR;;break;
case 0x07: /*** ret ***/
    CYCLES = CYCLES + 5; STACKIX = (STACKIX-1) & 7;;break;
case 0x08: /*** inr b ***/
    CYCLES = CYCLES + 5; B = (B + 1) & 0xFF; PSZV = B;;break;
case 0x09: /*** dcr b ***/
    CYCLES = CYCLES + 5; B = (B + 0xFF) & 0xFF; PSZV = B;;break;
case 0x0a: /*** rrc ***/
    CYCLES = CYCLES + 5; CARRY = A & 1; A = (A >> 1) | (CARRY << 7);;break;
case 0x0b: /*** rnz ***/
    CYCLES = CYCLES + 5; if (PSZV != 0) { STACKIX = (STACKIX-1) & 7; };;break;
case 0x0c: /*** aci #%1 ***/
    CYCLES = CYCLES + 8; CARRY = 0; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x0d: /*** rst 08 ***/
    CYCLES = CYCLES + 5; T16 = 0x08; STACKIX = (STACKIX+1) & 7; STACK[STACKIX] = T16 & 0x3FFF;;break;
case 0x0e: /*** mvi b,#%1 ***/
    CYCLES = CYCLES + 8; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); B = MBR;;break;
case 0x0f: /*** ret ***/
    CYCLES = CYCLES + 5; STACKIX = (STACKIX-1) & 7;;break;
case 0x10: /*** inr c ***/
    CYCLES = CYCLES + 5; C = (C + 1) & 0xFF; PSZV = C;;break;
case 0x11: /*** dcr c ***/
    CYCLES = CYCLES + 5; C = (C + 0xFF) & 0xFF; PSZV = C;;break;
case 0x12: /*** ral ***/
    CYCLES = CYCLES + 5; MAR = (A << 1) | CARRY; A = MAR & 0xFF; CARRY = (MAR >> 8) & 1;;break;
case 0x13: /*** rp ***/
    CYCLES = CYCLES + 5; if ((PSZV & 0x80) == 0) { STACKIX = (STACKIX-1) & 7; };;break;
case 0x14: /*** sui #%1 ***/
    CYCLES = CYCLES + 8; CARRY = 0; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x15: /*** rst 10 ***/
    CYCLES = CYCLES + 5; T16 = 0x10; STACKIX = (STACKIX+1) & 7; STACK[STACKIX] = T16 & 0x3FFF;;break;
case 0x16: /*** mvi c,#%1 ***/
    CYCLES = CYCLES + 8; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); C = MBR;;break;
case 0x17: /*** ret ***/
    CYCLES = CYCLES + 5; STACKIX = (STACKIX-1) & 7;;break;
case 0x18: /*** inr d ***/
    CYCLES = CYCLES + 5; D = (D + 1) & 0xFF; PSZV = D;;break;
case 0x19: /*** dcr d ***/
    CYCLES = CYCLES + 5; D = (D + 0xFF) & 0xFF; PSZV = D;;break;
case 0x1a: /*** rar ***/
    CYCLES = CYCLES + 5; MAR = A | (CARRY << 8); A = (MAR >> 1) & 0xFF; CARRY = MAR & 1;;break;
case 0x1b: /*** rpo ***/
    CYCLES = CYCLES + 5; if (parityeven(PSZV) == 0) { STACKIX = (STACKIX-1) & 7; };;break;
case 0x1c: /*** sbi #%1 ***/
    CYCLES = CYCLES + 8; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x1d: /*** rst 18 ***/
    CYCLES = CYCLES + 5; T16 = 0x18; STACKIX = (STACKIX+1) & 7; STACK[STACKIX] = T16 & 0x3FFF;;break;
case 0x1e: /*** mvi d,#%1 ***/
    CYCLES = CYCLES + 8; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); D = MBR;;break;
case 0x1f: /*** ret ***/
    CYCLES = CYCLES + 5; STACKIX = (STACKIX-1) & 7;;break;
case 0x20: /*** inr e ***/
    CYCLES = CYCLES + 5; E = (E + 1) & 0xFF; PSZV = E;;break;
case 0x21: /*** dcr e ***/
    CYCLES = CYCLES + 5; E = (E + 0xFF) & 0xFF; PSZV = E;;break;
case 0x22: /*** db 22 ***/
    ;break;
case 0x23: /*** rc ***/
    CYCLES = CYCLES + 5; if (CARRY != 0) { STACKIX = (STACKIX-1) & 7; };;break;
case 0x24: /*** ani #%1 ***/
    CYCLES = CYCLES + 8; CARRY = 0; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); A = A & MBR ; PSZV = A;;break;
case 0x25: /*** rst 20 ***/
    CYCLES = CYCLES + 5; T16 = 0x20; STACKIX = (STACKIX+1) & 7; STACK[STACKIX] = T16 & 0x3FFF;;break;
case 0x26: /*** mvi e,#%1 ***/
    CYCLES = CYCLES + 8; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); E = MBR;;break;
case 0x27: /*** ret ***/
    CYCLES = CYCLES + 5; STACKIX = (STACKIX-1) & 7;;break;
case 0x28: /*** inr h ***/
    CYCLES = CYCLES + 5; H = (H + 1) & 0xFF; PSZV = H;;break;
case 0x29: /*** dcr h ***/
    CYCLES = CYCLES + 5; H = (H + 0xFF) & 0xFF; PSZV = H;;break;
case 0x2a: /*** db 2a ***/
    ;break;
case 0x2b: /*** rz ***/
    CYCLES = CYCLES + 5; if (PSZV == 0) { STACKIX = (STACKIX-1) & 7; };;break;
case 0x2c: /*** xri #%1 ***/
    CYCLES = CYCLES + 8; CARRY = 0; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); A = A ^ MBR ; PSZV = A;;break;
case 0x2d: /*** rst 28 ***/
    CYCLES = CYCLES + 5; T16 = 0x28; STACKIX = (STACKIX+1) & 7; STACK[STACKIX] = T16 & 0x3FFF;;break;
case 0x2e: /*** mvi h,#%1 ***/
    CYCLES = CYCLES + 8; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); H = MBR;;break;
case 0x2f: /*** ret ***/
    CYCLES = CYCLES + 5; STACKIX = (STACKIX-1) & 7;;break;
case 0x30: /*** inr l ***/
    CYCLES = CYCLES + 5; L = (L + 1) & 0xFF; PSZV = L;;break;
case 0x31: /*** dcr l ***/
    CYCLES = CYCLES + 5; L = (L + 0xFF) & 0xFF; PSZV = L;;break;
case 0x32: /*** db 32 ***/
    ;break;
case 0x33: /*** rm ***/
    CYCLES = CYCLES + 5; if ((PSZV & 0x80) != 0) { STACKIX = (STACKIX-1) & 7; };;break;
case 0x34: /*** ori #%1 ***/
    CYCLES = CYCLES + 8; CARRY = 0; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); A = A | MBR ; PSZV = A;;break;
case 0x35: /*** rst 30 ***/
    CYCLES = CYCLES + 5; T16 = 0x30; STACKIX = (STACKIX+1) & 7; STACK[STACKIX] = T16 & 0x3FFF;;break;
case 0x36: /*** mvi l,#%1 ***/
    CYCLES = CYCLES + 8; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); L = MBR;;break;
case 0x37: /*** ret ***/
    CYCLES = CYCLES + 5; STACKIX = (STACKIX-1) & 7;;break;
case 0x38: /*** db 38 ***/
    ;break;
case 0x39: /*** db 39 ***/
    ;break;
case 0x3a: /*** db 3a ***/
    ;break;
case 0x3b: /*** rpe ***/
    CYCLES = CYCLES + 5; if (parityeven(PSZV) != 0) { STACKIX = (STACKIX-1) & 7; };;break;
case 0x3c: /*** cpi #%1 ***/
    CYCLES = CYCLES + 8; CARRY = 0; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; PSZV = MBR;;break;
case 0x3d: /*** rst 38 ***/
    CYCLES = CYCLES + 5; T16 = 0x38; STACKIX = (STACKIX+1) & 7; STACK[STACKIX] = T16 & 0x3FFF;;break;
case 0x3e: /*** mvi m,#%1 ***/
    CYCLES = CYCLES + 9; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR); MAR = ((H << 8)|L); WRITE(MAR,MBR);;break;
case 0x3f: /*** ret ***/
    CYCLES = CYCLES + 5; STACKIX = (STACKIX-1) & 7;;break;
case 0x40: /*** jnc %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if (CARRY == 0) { STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x41: /*** db 41 ***/
    ;break;
case 0x42: /*** cnc %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if (CARRY == 0) { STACKix = (STACKix+1) & 7;STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x43: /*** db 43 ***/
    ;break;
case 0x44: /*** jmp %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x45: /*** db 45 ***/
    ;break;
case 0x46: /*** call %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACKix = (STACKix+1) & 7; STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x47: /*** db 47 ***/
    ;break;
case 0x48: /*** jnz %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if (PSZV != 0) { STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x49: /*** db 49 ***/
    ;break;
case 0x4a: /*** cnz %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if (PSZV != 0) { STACKix = (STACKix+1) & 7;STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x4b: /*** db 4b ***/
    ;break;
case 0x4c: /*** jmp %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x4d: /*** db 4d ***/
    ;break;
case 0x4e: /*** call %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACKix = (STACKix+1) & 7; STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x4f: /*** db 4f ***/
    ;break;
case 0x50: /*** jp %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if ((PSZV & 0x80) == 0) { STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x51: /*** db 51 ***/
    ;break;
case 0x52: /*** cp %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if ((PSZV & 0x80) == 0) { STACKix = (STACKix+1) & 7;STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x53: /*** db 53 ***/
    ;break;
case 0x54: /*** jmp %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x55: /*** db 55 ***/
    ;break;
case 0x56: /*** call %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACKix = (STACKix+1) & 7; STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x57: /*** db 57 ***/
    ;break;
case 0x58: /*** jpo %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if (parityeven(PSZV) == 0) { STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x59: /*** db 59 ***/
    ;break;
case 0x5a: /*** cpo %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if (parityeven(PSZV) == 0) { STACKix = (STACKix+1) & 7;STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x5b: /*** db 5b ***/
    ;break;
case 0x5c: /*** jmp %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x5d: /*** db 5d ***/
    ;break;
case 0x5e: /*** call %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACKix = (STACKix+1) & 7; STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x5f: /*** db 5f ***/
    ;break;
case 0x60: /*** jc %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if (CARRY != 0) { STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x61: /*** db 61 ***/
    ;break;
case 0x62: /*** cc %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if (CARRY != 0) { STACKix = (STACKix+1) & 7;STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x63: /*** db 63 ***/
    ;break;
case 0x64: /*** jmp %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x65: /*** db 65 ***/
    ;break;
case 0x66: /*** call %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACKix = (STACKix+1) & 7; STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x67: /*** db 67 ***/
    ;break;
case 0x68: /*** jz %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if (PSZV == 0) { STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x69: /*** db 69 ***/
    ;break;
case 0x6a: /*** cz %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if (PSZV == 0) { STACKix = (STACKix+1) & 7;STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x6b: /*** db 6b ***/
    ;break;
case 0x6c: /*** jmp %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x6d: /*** db 6d ***/
    ;break;
case 0x6e: /*** call %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACKix = (STACKix+1) & 7; STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x6f: /*** db 6f ***/
    ;break;
case 0x70: /*** jm %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if ((PSZV & 0x80) != 0) { STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x71: /*** db 71 ***/
    ;break;
case 0x72: /*** cm %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if ((PSZV & 0x80) != 0) { STACKix = (STACKix+1) & 7;STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x73: /*** db 73 ***/
    ;break;
case 0x74: /*** jmp %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x75: /*** db 75 ***/
    ;break;
case 0x76: /*** call %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACKix = (STACKix+1) & 7; STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x77: /*** db 77 ***/
    ;break;
case 0x78: /*** jpe %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if (parityeven(PSZV) != 0) { STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x79: /*** db 79 ***/
    ;break;
case 0x7a: /*** cpe %2 ***/
    CYCLES = CYCLES + 10; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); if (parityeven(PSZV) != 0) { STACKix = (STACKix+1) & 7;STACK[STACKix] = T16 & 0x3FFF; };;break;
case 0x7b: /*** db 7b ***/
    ;break;
case 0x7c: /*** jmp %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x7d: /*** db 7d ***/
    ;break;
case 0x7e: /*** call %2 ***/
    CYCLES = CYCLES + 11; MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = MBR;MAR = STACK[STACKix];STACK[STACKix] = (MAR + 1) & 0x3FFF;MBR = READ(MAR);T16 = T16 | (MBR << 8); STACKix = (STACKix+1) & 7; STACK[STACKix] = T16 & 0x3FFF;;break;
case 0x7f: /*** db 7f ***/
    ;break;
case 0x80: /*** add a ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x81: /*** add b ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x82: /*** add c ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x83: /*** add d ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x84: /*** add e ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x85: /*** add h ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x86: /*** add l ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x87: /*** sub m ***/
    CYCLES = CYCLES + 8; CARRY = 0; MAR = ((H << 8)|L); MBR = READ(MAR); MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x88: /*** adc a ***/
    CYCLES = CYCLES + 5; MBR = R; MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x89: /*** adc b ***/
    CYCLES = CYCLES + 5; MBR = R; MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x8a: /*** adc c ***/
    CYCLES = CYCLES + 5; MBR = R; MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x8b: /*** adc d ***/
    CYCLES = CYCLES + 5; MBR = R; MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x8c: /*** adc e ***/
    CYCLES = CYCLES + 5; MBR = R; MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x8d: /*** adc h ***/
    CYCLES = CYCLES + 5; MBR = R; MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x8e: /*** adc l ***/
    CYCLES = CYCLES + 5; MBR = R; MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x8f: /*** adc m ***/
    CYCLES = CYCLES + 8; MAR = ((H << 8)|L); MBR = READ(MAR); MAR = A + MBR + CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x90: /*** sub a ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x91: /*** sub b ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x92: /*** sub c ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x93: /*** sub d ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x94: /*** sub e ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x95: /*** sub h ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x96: /*** sub l ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x97: /*** db 97 ***/
    ;break;
case 0x98: /*** sbb a ***/
    CYCLES = CYCLES + 5; MBR; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x99: /*** sbb b ***/
    CYCLES = CYCLES + 5; MBR; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x9a: /*** sbb c ***/
    CYCLES = CYCLES + 5; MBR; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x9b: /*** sbb d ***/
    CYCLES = CYCLES + 5; MBR; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x9c: /*** sbb e ***/
    CYCLES = CYCLES + 5; MBR; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x9d: /*** sbb h ***/
    CYCLES = CYCLES + 5; MBR; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x9e: /*** sbb l ***/
    CYCLES = CYCLES + 5; MBR; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0x9f: /*** sbb m ***/
    CYCLES = CYCLES + 8; MAR = ((H << 8)|L); MBR = READ(MAR); MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; A = MBR ; PSZV = MBR;;break;
case 0xa0: /*** and a ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A & A ; PSZV = A;;break;
case 0xa1: /*** and b ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A & B ; PSZV = A;;break;
case 0xa2: /*** and c ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A & C ; PSZV = A;;break;
case 0xa3: /*** and d ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A & D ; PSZV = A;;break;
case 0xa4: /*** and e ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A & E ; PSZV = A;;break;
case 0xa5: /*** and h ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A & H ; PSZV = A;;break;
case 0xa6: /*** and l ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A & L ; PSZV = A;;break;
case 0xa7: /*** and m ***/
    CYCLES = CYCLES + 8; CARRY = 0; MAR = ((H << 8)|L); MBR = READ(MAR); A = A & MBR ; PSZV = A;;break;
case 0xa8: /*** xor a ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A ^ A ; PSZV = A;;break;
case 0xa9: /*** xor b ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A ^ B ; PSZV = A;;break;
case 0xaa: /*** xor c ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A ^ C ; PSZV = A;;break;
case 0xab: /*** xor d ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A ^ D ; PSZV = A;;break;
case 0xac: /*** xor e ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A ^ E ; PSZV = A;;break;
case 0xad: /*** xor h ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A ^ H ; PSZV = A;;break;
case 0xae: /*** xor l ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A ^ L ; PSZV = A;;break;
case 0xaf: /*** xor m ***/
    CYCLES = CYCLES + 8; CARRY = 0; MAR = ((H << 8)|L); MBR = READ(MAR); A = A ^ MBR ; PSZV = A;;break;
case 0xb0: /*** or a ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A | A ; PSZV = A;;break;
case 0xb1: /*** or b ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A | B ; PSZV = A;;break;
case 0xb2: /*** or c ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A | C ; PSZV = A;;break;
case 0xb3: /*** or d ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A | D ; PSZV = A;;break;
case 0xb4: /*** or e ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A | E ; PSZV = A;;break;
case 0xb5: /*** or h ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A | H ; PSZV = A;;break;
case 0xb6: /*** or l ***/
    CYCLES = CYCLES + 5; CARRY = 0; A = A | L ; PSZV = A;;break;
case 0xb7: /*** or m ***/
    CYCLES = CYCLES + 8; CARRY = 0; MAR = ((H << 8)|L); MBR = READ(MAR); A = A | MBR ; PSZV = A;;break;
case 0xb8: /*** cmp a ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; PSZV = MBR;;break;
case 0xb9: /*** cmp b ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; PSZV = MBR;;break;
case 0xba: /*** cmp c ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; PSZV = MBR;;break;
case 0xbb: /*** cmp d ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; PSZV = MBR;;break;
case 0xbc: /*** cmp e ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; PSZV = MBR;;break;
case 0xbd: /*** cmp h ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; PSZV = MBR;;break;
case 0xbe: /*** cmp l ***/
    CYCLES = CYCLES + 5; CARRY = 0; MBR = R; MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; PSZV = MBR;;break;
case 0xbf: /*** cmp m ***/
    CYCLES = CYCLES + 8; CARRY = 0; MAR = ((H << 8)|L); MBR = READ(MAR); MAR = A - MBR - CARRY;A = (MAR & 0xFF);CARRY = (MAR >> 8) & 1; PSZV = MBR;;break;
case 0xc0: /*** mov a,a ***/
    CYCLES = CYCLES + 5; A = A;;break;
case 0xc1: /*** mov a,b ***/
    CYCLES = CYCLES + 5; A = B;;break;
case 0xc2: /*** mov a,c ***/
    CYCLES = CYCLES + 5; A = C;;break;
case 0xc3: /*** mov a,d ***/
    CYCLES = CYCLES + 5; A = D;;break;
case 0xc4: /*** mov a,e ***/
    CYCLES = CYCLES + 5; A = E;;break;
case 0xc5: /*** mov a,h ***/
    CYCLES = CYCLES + 5; A = H;;break;
case 0xc6: /*** mov a,l ***/
    CYCLES = CYCLES + 5; A = L;;break;
case 0xc7: /*** mov a,m ***/
    CYCLES = CYCLES + 8; MAR = ((H << 8)|L); MBR = READ(MAR); A = MBR;;break;
case 0xc8: /*** mov b,a ***/
    CYCLES = CYCLES + 5; B = A;;break;
case 0xc9: /*** mov b,b ***/
    CYCLES = CYCLES + 5; B = B;;break;
case 0xca: /*** mov b,c ***/
    CYCLES = CYCLES + 5; B = C;;break;
case 0xcb: /*** mov b,d ***/
    CYCLES = CYCLES + 5; B = D;;break;
case 0xcc: /*** mov b,e ***/
    CYCLES = CYCLES + 5; B = E;;break;
case 0xcd: /*** mov b,h ***/
    CYCLES = CYCLES + 5; B = H;;break;
case 0xce: /*** mov b,l ***/
    CYCLES = CYCLES + 5; B = L;;break;
case 0xcf: /*** mov b,m ***/
    CYCLES = CYCLES + 8; MAR = ((H << 8)|L); MBR = READ(MAR); B = MBR;;break;
case 0xd0: /*** mov c,a ***/
    CYCLES = CYCLES + 5; C = A;;break;
case 0xd1: /*** mov c,b ***/
    CYCLES = CYCLES + 5; C = B;;break;
case 0xd2: /*** mov c,c ***/
    CYCLES = CYCLES + 5; C = C;;break;
case 0xd3: /*** mov c,d ***/
    CYCLES = CYCLES + 5; C = D;;break;
case 0xd4: /*** mov c,e ***/
    CYCLES = CYCLES + 5; C = E;;break;
case 0xd5: /*** mov c,h ***/
    CYCLES = CYCLES + 5; C = H;;break;
case 0xd6: /*** mov c,l ***/
    CYCLES = CYCLES + 5; C = L;;break;
case 0xd7: /*** mov c,m ***/
    CYCLES = CYCLES + 8; MAR = ((H << 8)|L); MBR = READ(MAR); C = MBR;;break;
case 0xd8: /*** mov d,a ***/
    CYCLES = CYCLES + 5; D = A;;break;
case 0xd9: /*** mov d,b ***/
    CYCLES = CYCLES + 5; D = B;;break;
case 0xda: /*** mov d,c ***/
    CYCLES = CYCLES + 5; D = C;;break;
case 0xdb: /*** mov d,d ***/
    CYCLES = CYCLES + 5; D = D;;break;
case 0xdc: /*** mov d,e ***/
    CYCLES = CYCLES + 5; D = E;;break;
case 0xdd: /*** mov d,h ***/
    CYCLES = CYCLES + 5; D = H;;break;
case 0xde: /*** mov d,l ***/
    CYCLES = CYCLES + 5; D = L;;break;
case 0xdf: /*** mov d,m ***/
    CYCLES = CYCLES + 8; MAR = ((H << 8)|L); MBR = READ(MAR); D = MBR;;break;
case 0xe0: /*** mov e,a ***/
    CYCLES = CYCLES + 5; E = A;;break;
case 0xe1: /*** mov e,b ***/
    CYCLES = CYCLES + 5; E = B;;break;
case 0xe2: /*** mov e,c ***/
    CYCLES = CYCLES + 5; E = C;;break;
case 0xe3: /*** mov e,d ***/
    CYCLES = CYCLES + 5; E = D;;break;
case 0xe4: /*** mov e,e ***/
    CYCLES = CYCLES + 5; E = E;;break;
case 0xe5: /*** mov e,h ***/
    CYCLES = CYCLES + 5; E = H;;break;
case 0xe6: /*** mov e,l ***/
    CYCLES = CYCLES + 5; E = L;;break;
case 0xe7: /*** mov e,m ***/
    CYCLES = CYCLES + 8; MAR = ((H << 8)|L); MBR = READ(MAR); E = MBR;;break;
case 0xe8: /*** mov h,a ***/
    CYCLES = CYCLES + 5; H = A;;break;
case 0xe9: /*** mov h,b ***/
    CYCLES = CYCLES + 5; H = B;;break;
case 0xea: /*** mov h,c ***/
    CYCLES = CYCLES + 5; H = C;;break;
case 0xeb: /*** mov h,d ***/
    CYCLES = CYCLES + 5; H = D;;break;
case 0xec: /*** mov h,e ***/
    CYCLES = CYCLES + 5; H = E;;break;
case 0xed: /*** mov h,h ***/
    CYCLES = CYCLES + 5; H = H;;break;
case 0xee: /*** mov h,l ***/
    CYCLES = CYCLES + 5; H = L;;break;
case 0xef: /*** mov h,m ***/
    CYCLES = CYCLES + 8; MAR = ((H << 8)|L); MBR = READ(MAR); H = MBR;;break;
case 0xf0: /*** mov l,a ***/
    CYCLES = CYCLES + 5; L = A;;break;
case 0xf1: /*** mov l,b ***/
    CYCLES = CYCLES + 5; L = B;;break;
case 0xf2: /*** mov l,c ***/
    CYCLES = CYCLES + 5; L = C;;break;
case 0xf3: /*** mov l,d ***/
    CYCLES = CYCLES + 5; L = D;;break;
case 0xf4: /*** mov l,e ***/
    CYCLES = CYCLES + 5; L = E;;break;
case 0xf5: /*** mov l,h ***/
    CYCLES = CYCLES + 5; L = H;;break;
case 0xf6: /*** mov l,l ***/
    CYCLES = CYCLES + 5; L = L;;break;
case 0xf7: /*** mov l,m ***/
    CYCLES = CYCLES + 8; MAR = ((H << 8)|L); MBR = READ(MAR); L = MBR;;break;
case 0xf8: /*** mov m,a ***/
    CYCLES = CYCLES + 7; MAR = ((H << 8)|L); MBR = A; WRITE(MAR,MBR);;break;
case 0xf9: /*** mov m,b ***/
    CYCLES = CYCLES + 7; MAR = ((H << 8)|L); MBR = B; WRITE(MAR,MBR);;break;
case 0xfa: /*** mov m,c ***/
    CYCLES = CYCLES + 7; MAR = ((H << 8)|L); MBR = C; WRITE(MAR,MBR);;break;
case 0xfb: /*** mov m,d ***/
    CYCLES = CYCLES + 7; MAR = ((H << 8)|L); MBR = D; WRITE(MAR,MBR);;break;
case 0xfc: /*** mov m,e ***/
    CYCLES = CYCLES + 7; MAR = ((H << 8)|L); MBR = E; WRITE(MAR,MBR);;break;
case 0xfd: /*** mov m,h ***/
    CYCLES = CYCLES + 7; MAR = ((H << 8)|L); MBR = H; WRITE(MAR,MBR);;break;
case 0xfe: /*** mov m,l ***/
    CYCLES = CYCLES + 7; MAR = ((H << 8)|L); MBR = L; WRITE(MAR,MBR);;break;
case 0xff: /*** halt ***/
    CYCLES = CYCLES + 4; HALT = 1;;break;
