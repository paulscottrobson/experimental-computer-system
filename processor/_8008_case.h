case 0x00: /*** halt ***/
    HALT = 1;break;
case 0x01: /*** halt ***/
    HALT = 1;break;
case 0x02: /*** rlc ***/
    CARRY = (A >> 7) & 1;A = ((A << 1) | CARRY) & 0xFF;break;
case 0x03: /*** rnc ***/
    if (CARRY == 0) { SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;};break;
case 0x04: /*** adi %1 ***/
    PSZVALUE = A = ADD(FETCH(),0);break;
case 0x05: /*** rst 00 ***/
    STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = 0x00;break;
case 0x06: /*** nop ***/
    ;;break;
case 0x07: /*** ret ***/
    SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;break;
case 0x08: /*** inr a ***/
    PSZVALUE = A = (A+1) & 255;break;
case 0x09: /*** dcr b ***/
    PSZVALUE = A = (B-1) & 255;break;
case 0x0a: /*** rrc ***/
    CARRY = A & 1;A = (A >> 1) | (CARRY << 7);break;
case 0x0b: /*** rnz ***/
    if (PSZVALUE != 0) { SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;};break;
case 0x0c: /*** aci %1 ***/
    PSZVALUE = A = ADD(FETCH(),CARRY);break;
case 0x0d: /*** rst 08 ***/
    STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = 0x08;break;
case 0x0e: /*** nop ***/
    ;;break;
case 0x0f: /*** ret ***/
    SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;break;
case 0x10: /*** inr a ***/
    PSZVALUE = A = (A+1) & 255;break;
case 0x11: /*** dcr b ***/
    PSZVALUE = A = (B-1) & 255;break;
case 0x12: /*** ral ***/
    T16 = (A << 1)|CARRY;CARRY = (T16 >> 8) & 1 ;A = T16 & 0xFF;break;
case 0x13: /*** rp ***/
    if ((PSZVALUE & 0x80) == 0) { SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;};break;
case 0x14: /*** sui %1 ***/
    PSZVALUE = A = SUB(FETCH(),0);break;
case 0x15: /*** rst 10 ***/
    STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = 0x10;break;
case 0x16: /*** nop ***/
    ;;break;
case 0x17: /*** ret ***/
    SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;break;
case 0x18: /*** inr a ***/
    PSZVALUE = A = (A+1) & 255;break;
case 0x19: /*** dcr b ***/
    PSZVALUE = A = (B-1) & 255;break;
case 0x1a: /*** rar ***/
    T16 = (CARRY << 8)|A;CARRY = A & 1;A = (T16 >> 1) & 0xFF;break;
case 0x1b: /*** rpo ***/
    if (PARITYEVEN(PSZVALUE) == 0) { SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;};break;
case 0x1c: /*** sbi %1 ***/
    PSZVALUE = A = SUB(FETCH(),CARRY);break;
case 0x1d: /*** rst 18 ***/
    STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = 0x18;break;
case 0x1e: /*** nop ***/
    ;;break;
case 0x1f: /*** ret ***/
    SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;break;
case 0x20: /*** inr a ***/
    PSZVALUE = A = (A+1) & 255;break;
case 0x21: /*** dcr b ***/
    PSZVALUE = A = (B-1) & 255;break;
case 0x22: /*** nop ***/
    ;;break;
case 0x23: /*** rc ***/
    if (CARRY != 0) { SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;};break;
case 0x24: /*** ani %1 ***/
    PSZVALUE = A = A & FETCH();CARRY = 0;break;
case 0x25: /*** rst 20 ***/
    STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = 0x20;break;
case 0x26: /*** nop ***/
    ;;break;
case 0x27: /*** ret ***/
    SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;break;
case 0x28: /*** inr a ***/
    PSZVALUE = A = (A+1) & 255;break;
case 0x29: /*** dcr b ***/
    PSZVALUE = A = (B-1) & 255;break;
case 0x2a: /*** nop ***/
    ;;break;
case 0x2b: /*** rz ***/
    if (PSZVALUE == 0) { SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;};break;
case 0x2c: /*** xri %1 ***/
    PSZVALUE = A = A ^ FETCH();CARRY = 0;break;
case 0x2d: /*** rst 28 ***/
    STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = 0x28;break;
case 0x2e: /*** nop ***/
    ;;break;
case 0x2f: /*** ret ***/
    SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;break;
case 0x30: /*** inr a ***/
    PSZVALUE = A = (A+1) & 255;break;
case 0x31: /*** dcr b ***/
    PSZVALUE = A = (B-1) & 255;break;
case 0x32: /*** nop ***/
    ;;break;
case 0x33: /*** rm ***/
    if ((PSZVALUE & 0x80) != 0) { SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;};break;
case 0x34: /*** ori %1 ***/
    PSZVALUE = A = A | FETCH();CARRY = 0;break;
case 0x35: /*** rst 30 ***/
    STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = 0x30;break;
case 0x36: /*** nop ***/
    ;;break;
case 0x37: /*** ret ***/
    SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;break;
case 0x38: /*** nop ***/
    ;;break;
case 0x39: /*** nop ***/
    ;;break;
case 0x3a: /*** nop ***/
    ;;break;
case 0x3b: /*** rpe ***/
    if (PARITYEVEN(PSZVALUE) != 0) { SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;};break;
case 0x3c: /*** cpi %1 ***/
    PSZVALUE = SUB(FETCH(),0);break;
case 0x3d: /*** rst 38 ***/
    STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = 0x38;break;
case 0x3e: /*** nop ***/
    ;;break;
case 0x3f: /*** ret ***/
    SPTR = (SPTR-1) & 7;PC = STACK[SPTR];;break;
case 0x40: /*** jnc %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if (CARRY == 0) { PC = T16; };break;
case 0x41: /*** in 00 ***/
    A = INPUT(0x00);break;
case 0x42: /*** cnc %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if (CARRY == 0) { STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16; };break;
case 0x43: /*** in 01 ***/
    A = INPUT(0x01);break;
case 0x44: /*** jmp %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;PC = T16;break;
case 0x45: /*** in 02 ***/
    A = INPUT(0x02);break;
case 0x46: /*** cal %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16;break;
case 0x47: /*** in 03 ***/
    A = INPUT(0x03);break;
case 0x48: /*** jnz %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if (PSZVALUE != 0) { PC = T16; };break;
case 0x49: /*** in 04 ***/
    A = INPUT(0x04);break;
case 0x4a: /*** cnz %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if (PSZVALUE != 0) { STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16; };break;
case 0x4b: /*** in 05 ***/
    A = INPUT(0x05);break;
case 0x4c: /*** jmp %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;PC = T16;break;
case 0x4d: /*** in 06 ***/
    A = INPUT(0x06);break;
case 0x4e: /*** cal %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16;break;
case 0x4f: /*** in 07 ***/
    A = INPUT(0x07);break;
case 0x50: /*** jp %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if ((PSZVALUE & 0x80) == 0) { PC = T16; };break;
case 0x51: /*** out 08 ***/
    OUTPUT(0x08,A);break;
case 0x52: /*** cp %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if ((PSZVALUE & 0x80) == 0) { STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16; };break;
case 0x53: /*** out 09 ***/
    OUTPUT(0x09,A);break;
case 0x54: /*** jmp %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;PC = T16;break;
case 0x55: /*** out 0a ***/
    OUTPUT(0x0A,A);break;
case 0x56: /*** cal %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16;break;
case 0x57: /*** out 0b ***/
    OUTPUT(0x0B,A);break;
case 0x58: /*** jpo %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if (PARITYEVEN(PSZVALUE) == 0) { PC = T16; };break;
case 0x59: /*** out 0c ***/
    OUTPUT(0x0C,A);break;
case 0x5a: /*** cpo %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if (PARITYEVEN(PSZVALUE) == 0) { STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16; };break;
case 0x5b: /*** out 0d ***/
    OUTPUT(0x0D,A);break;
case 0x5c: /*** jmp %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;PC = T16;break;
case 0x5d: /*** out 0e ***/
    OUTPUT(0x0E,A);break;
case 0x5e: /*** cal %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16;break;
case 0x5f: /*** out 0f ***/
    OUTPUT(0x0F,A);break;
case 0x60: /*** jc %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if (CARRY != 0) { PC = T16; };break;
case 0x61: /*** out 10 ***/
    OUTPUT(0x10,A);break;
case 0x62: /*** cc %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if (CARRY != 0) { STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16; };break;
case 0x63: /*** out 11 ***/
    OUTPUT(0x11,A);break;
case 0x64: /*** jmp %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;PC = T16;break;
case 0x65: /*** out 12 ***/
    OUTPUT(0x12,A);break;
case 0x66: /*** cal %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16;break;
case 0x67: /*** out 13 ***/
    OUTPUT(0x13,A);break;
case 0x68: /*** jz %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if (PSZVALUE == 0) { PC = T16; };break;
case 0x69: /*** out 14 ***/
    OUTPUT(0x14,A);break;
case 0x6a: /*** cz %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if (PSZVALUE == 0) { STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16; };break;
case 0x6b: /*** out 15 ***/
    OUTPUT(0x15,A);break;
case 0x6c: /*** jmp %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;PC = T16;break;
case 0x6d: /*** out 16 ***/
    OUTPUT(0x16,A);break;
case 0x6e: /*** cal %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16;break;
case 0x6f: /*** out 17 ***/
    OUTPUT(0x17,A);break;
case 0x70: /*** jm %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if ((PSZVALUE & 0x80) != 0) { PC = T16; };break;
case 0x71: /*** out 18 ***/
    OUTPUT(0x18,A);break;
case 0x72: /*** cm %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if ((PSZVALUE & 0x80) != 0) { STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16; };break;
case 0x73: /*** out 19 ***/
    OUTPUT(0x19,A);break;
case 0x74: /*** jmp %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;PC = T16;break;
case 0x75: /*** out 1a ***/
    OUTPUT(0x1A,A);break;
case 0x76: /*** cal %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16;break;
case 0x77: /*** out 1b ***/
    OUTPUT(0x1B,A);break;
case 0x78: /*** jpe %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if (PARITYEVEN(PSZVALUE) != 0) { PC = T16; };break;
case 0x79: /*** out 1c ***/
    OUTPUT(0x1C,A);break;
case 0x7a: /*** cpe %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;if (PARITYEVEN(PSZVALUE) != 0) { STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16; };break;
case 0x7b: /*** out 1d ***/
    OUTPUT(0x1D,A);break;
case 0x7c: /*** jmp %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;PC = T16;break;
case 0x7d: /*** out 1e ***/
    OUTPUT(0x1E,A);break;
case 0x7e: /*** cal %2 ***/
    T16 = FETCH();T16 = (T16 | (FETCH() << 8)) & 0x3FFF;STACK[SPTR] = PC;SPTR = (SPTR+1) & 7;PC = T16;break;
case 0x7f: /*** out 1f ***/
    OUTPUT(0x1F,A);break;
case 0x80: /*** add a ***/
    PSZVALUE = A = ADD(A,0);break;
case 0x81: /*** add b ***/
    PSZVALUE = A = ADD(B,0);break;
case 0x82: /*** add c ***/
    PSZVALUE = A = ADD(C,0);break;
case 0x83: /*** add d ***/
    PSZVALUE = A = ADD(D,0);break;
case 0x84: /*** add e ***/
    PSZVALUE = A = ADD(E,0);break;
case 0x85: /*** add h ***/
    PSZVALUE = A = ADD(H,0);break;
case 0x86: /*** add l ***/
    PSZVALUE = A = ADD(L,0);break;
case 0x87: /*** add m ***/
    PSZVALUE = A = ADD(READ((((H << 8)|L) & 0x3FFF)),0);break;
case 0x88: /*** adc a ***/
    PSZVALUE = A = ADD(A,CARRY);break;
case 0x89: /*** adc b ***/
    PSZVALUE = A = ADD(B,CARRY);break;
case 0x8a: /*** adc c ***/
    PSZVALUE = A = ADD(C,CARRY);break;
case 0x8b: /*** adc d ***/
    PSZVALUE = A = ADD(D,CARRY);break;
case 0x8c: /*** adc e ***/
    PSZVALUE = A = ADD(E,CARRY);break;
case 0x8d: /*** adc h ***/
    PSZVALUE = A = ADD(H,CARRY);break;
case 0x8e: /*** adc l ***/
    PSZVALUE = A = ADD(L,CARRY);break;
case 0x8f: /*** adc m ***/
    PSZVALUE = A = ADD(READ((((H << 8)|L) & 0x3FFF)),CARRY);break;
case 0x90: /*** sub a ***/
    PSZVALUE = A = SUB(A,0);break;
case 0x91: /*** sub b ***/
    PSZVALUE = A = SUB(B,0);break;
case 0x92: /*** sub c ***/
    PSZVALUE = A = SUB(C,0);break;
case 0x93: /*** sub d ***/
    PSZVALUE = A = SUB(D,0);break;
case 0x94: /*** sub e ***/
    PSZVALUE = A = SUB(E,0);break;
case 0x95: /*** sub h ***/
    PSZVALUE = A = SUB(H,0);break;
case 0x96: /*** sub l ***/
    PSZVALUE = A = SUB(L,0);break;
case 0x97: /*** sub m ***/
    PSZVALUE = A = SUB(READ((((H << 8)|L) & 0x3FFF)),0);break;
case 0x98: /*** sbb a ***/
    PSZVALUE = A = SUB(A,CARRY);break;
case 0x99: /*** sbb b ***/
    PSZVALUE = A = SUB(B,CARRY);break;
case 0x9a: /*** sbb c ***/
    PSZVALUE = A = SUB(C,CARRY);break;
case 0x9b: /*** sbb d ***/
    PSZVALUE = A = SUB(D,CARRY);break;
case 0x9c: /*** sbb e ***/
    PSZVALUE = A = SUB(E,CARRY);break;
case 0x9d: /*** sbb h ***/
    PSZVALUE = A = SUB(H,CARRY);break;
case 0x9e: /*** sbb l ***/
    PSZVALUE = A = SUB(L,CARRY);break;
case 0x9f: /*** sbb m ***/
    PSZVALUE = A = SUB(READ((((H << 8)|L) & 0x3FFF)),CARRY);break;
case 0xa0: /*** ana a ***/
    PSZVALUE = A = A & A;CARRY = 0;break;
case 0xa1: /*** ana b ***/
    PSZVALUE = A = A & B;CARRY = 0;break;
case 0xa2: /*** ana c ***/
    PSZVALUE = A = A & C;CARRY = 0;break;
case 0xa3: /*** ana d ***/
    PSZVALUE = A = A & D;CARRY = 0;break;
case 0xa4: /*** ana e ***/
    PSZVALUE = A = A & E;CARRY = 0;break;
case 0xa5: /*** ana h ***/
    PSZVALUE = A = A & H;CARRY = 0;break;
case 0xa6: /*** ana l ***/
    PSZVALUE = A = A & L;CARRY = 0;break;
case 0xa7: /*** ana m ***/
    PSZVALUE = A = A & READ((((H << 8)|L) & 0x3FFF));CARRY = 0;break;
case 0xa8: /*** xra a ***/
    PSZVALUE = A = A ^ A;CARRY = 0;break;
case 0xa9: /*** xra b ***/
    PSZVALUE = A = A ^ B;CARRY = 0;break;
case 0xaa: /*** xra c ***/
    PSZVALUE = A = A ^ C;CARRY = 0;break;
case 0xab: /*** xra d ***/
    PSZVALUE = A = A ^ D;CARRY = 0;break;
case 0xac: /*** xra e ***/
    PSZVALUE = A = A ^ E;CARRY = 0;break;
case 0xad: /*** xra h ***/
    PSZVALUE = A = A ^ H;CARRY = 0;break;
case 0xae: /*** xra l ***/
    PSZVALUE = A = A ^ L;CARRY = 0;break;
case 0xaf: /*** xra m ***/
    PSZVALUE = A = A ^ READ((((H << 8)|L) & 0x3FFF));CARRY = 0;break;
case 0xb0: /*** ora a ***/
    PSZVALUE = A = A | A;CARRY = 0;break;
case 0xb1: /*** ora b ***/
    PSZVALUE = A = A | B;CARRY = 0;break;
case 0xb2: /*** ora c ***/
    PSZVALUE = A = A | C;CARRY = 0;break;
case 0xb3: /*** ora d ***/
    PSZVALUE = A = A | D;CARRY = 0;break;
case 0xb4: /*** ora e ***/
    PSZVALUE = A = A | E;CARRY = 0;break;
case 0xb5: /*** ora h ***/
    PSZVALUE = A = A | H;CARRY = 0;break;
case 0xb6: /*** ora l ***/
    PSZVALUE = A = A | L;CARRY = 0;break;
case 0xb7: /*** ora m ***/
    PSZVALUE = A = A | READ((((H << 8)|L) & 0x3FFF));CARRY = 0;break;
case 0xb8: /*** cmp a ***/
    PSZVALUE = SUB(A,0);break;
case 0xb9: /*** cmp b ***/
    PSZVALUE = SUB(B,0);break;
case 0xba: /*** cmp c ***/
    PSZVALUE = SUB(C,0);break;
case 0xbb: /*** cmp d ***/
    PSZVALUE = SUB(D,0);break;
case 0xbc: /*** cmp e ***/
    PSZVALUE = SUB(E,0);break;
case 0xbd: /*** cmp h ***/
    PSZVALUE = SUB(H,0);break;
case 0xbe: /*** cmp l ***/
    PSZVALUE = SUB(L,0);break;
case 0xbf: /*** cmp m ***/
    PSZVALUE = SUB(READ((((H << 8)|L) & 0x3FFF)),0);break;
case 0xc0: /*** mov a,a ***/
    A = A;break;
case 0xc1: /*** mov a,b ***/
    A = B;break;
case 0xc2: /*** mov a,c ***/
    A = C;break;
case 0xc3: /*** mov a,d ***/
    A = D;break;
case 0xc4: /*** mov a,e ***/
    A = E;break;
case 0xc5: /*** mov a,h ***/
    A = H;break;
case 0xc6: /*** mov a,l ***/
    A = L;break;
case 0xc7: /*** mov a,m ***/
    A = READ((((H << 8)|L) & 0x3FFF));break;
case 0xc8: /*** mov b,a ***/
    B = A;break;
case 0xc9: /*** mov b,b ***/
    B = B;break;
case 0xca: /*** mov b,c ***/
    B = C;break;
case 0xcb: /*** mov b,d ***/
    B = D;break;
case 0xcc: /*** mov b,e ***/
    B = E;break;
case 0xcd: /*** mov b,h ***/
    B = H;break;
case 0xce: /*** mov b,l ***/
    B = L;break;
case 0xcf: /*** mov b,m ***/
    B = READ((((H << 8)|L) & 0x3FFF));break;
case 0xd0: /*** mov c,a ***/
    C = A;break;
case 0xd1: /*** mov c,b ***/
    C = B;break;
case 0xd2: /*** mov c,c ***/
    C = C;break;
case 0xd3: /*** mov c,d ***/
    C = D;break;
case 0xd4: /*** mov c,e ***/
    C = E;break;
case 0xd5: /*** mov c,h ***/
    C = H;break;
case 0xd6: /*** mov c,l ***/
    C = L;break;
case 0xd7: /*** mov c,m ***/
    C = READ((((H << 8)|L) & 0x3FFF));break;
case 0xd8: /*** mov d,a ***/
    D = A;break;
case 0xd9: /*** mov d,b ***/
    D = B;break;
case 0xda: /*** mov d,c ***/
    D = C;break;
case 0xdb: /*** mov d,d ***/
    D = D;break;
case 0xdc: /*** mov d,e ***/
    D = E;break;
case 0xdd: /*** mov d,h ***/
    D = H;break;
case 0xde: /*** mov d,l ***/
    D = L;break;
case 0xdf: /*** mov d,m ***/
    D = READ((((H << 8)|L) & 0x3FFF));break;
case 0xe0: /*** mov e,a ***/
    E = A;break;
case 0xe1: /*** mov e,b ***/
    E = B;break;
case 0xe2: /*** mov e,c ***/
    E = C;break;
case 0xe3: /*** mov e,d ***/
    E = D;break;
case 0xe4: /*** mov e,e ***/
    E = E;break;
case 0xe5: /*** mov e,h ***/
    E = H;break;
case 0xe6: /*** mov e,l ***/
    E = L;break;
case 0xe7: /*** mov e,m ***/
    E = READ((((H << 8)|L) & 0x3FFF));break;
case 0xe8: /*** mov h,a ***/
    H = A;break;
case 0xe9: /*** mov h,b ***/
    H = B;break;
case 0xea: /*** mov h,c ***/
    H = C;break;
case 0xeb: /*** mov h,d ***/
    H = D;break;
case 0xec: /*** mov h,e ***/
    H = E;break;
case 0xed: /*** mov h,h ***/
    H = H;break;
case 0xee: /*** mov h,l ***/
    H = L;break;
case 0xef: /*** mov h,m ***/
    H = READ((((H << 8)|L) & 0x3FFF));break;
case 0xf0: /*** mov l,a ***/
    L = A;break;
case 0xf1: /*** mov l,b ***/
    L = B;break;
case 0xf2: /*** mov l,c ***/
    L = C;break;
case 0xf3: /*** mov l,d ***/
    L = D;break;
case 0xf4: /*** mov l,e ***/
    L = E;break;
case 0xf5: /*** mov l,h ***/
    L = H;break;
case 0xf6: /*** mov l,l ***/
    L = L;break;
case 0xf7: /*** mov l,m ***/
    L = READ((((H << 8)|L) & 0x3FFF));break;
case 0xf8: /*** mov m,a ***/
    WRITE((((H << 8)|L) & 0x3FFF),A);break;
case 0xf9: /*** mov m,b ***/
    WRITE((((H << 8)|L) & 0x3FFF),B);break;
case 0xfa: /*** mov m,c ***/
    WRITE((((H << 8)|L) & 0x3FFF),C);break;
case 0xfb: /*** mov m,d ***/
    WRITE((((H << 8)|L) & 0x3FFF),D);break;
case 0xfc: /*** mov m,e ***/
    WRITE((((H << 8)|L) & 0x3FFF),E);break;
case 0xfd: /*** mov m,h ***/
    WRITE((((H << 8)|L) & 0x3FFF),H);break;
case 0xfe: /*** mov m,l ***/
    WRITE((((H << 8)|L) & 0x3FFF),L);break;
case 0xff: /*** halt ***/
    HALT = 1;break;
