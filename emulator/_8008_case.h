case 0x00: /*** halt ***/
    cycles = cycles + 4;halt = 1;;break;
case 0x01: /*** halt ***/
    cycles = cycles + 4;halt = 1;;break;
case 0x02: /*** rlc ***/
    cycles = cycles + 5;a = ((a << 1) | (a >> 7)) & 0xFF;carry = a & 1;;break;
case 0x03: /*** rnc ***/
    cycles = cycles + 5;if (carry == 0) { pull(); };;break;
case 0x04: /*** adi %1 ***/
    cycles = cycles + 8;fetch();carry = 0;add8bit();;break;
case 0x05: /*** rst 00 ***/
    cycles = cycles + 5;t16 = 0x00;push();branch();;break;
case 0x06: /*** mvi a,%1 ***/
    cycles = cycles + 8;fetch();a = mbr;;break;
case 0x07: /*** ret ***/
    cycles = cycles + 5;pull();;break;
case 0x08: /*** inr b ***/
    cycles = cycles + 5;b = (b + 0x01) & 0xFF;pszv = b;;break;
case 0x09: /*** dcr b ***/
    cycles = cycles + 5;b = (b + 0xFF) & 0xFF;pszv = b;;break;
case 0x0a: /*** rrc ***/
    cycles = cycles + 5;carry = a & 1;a = (a >> 1) | (carry << 7);;break;
case 0x0b: /*** rnz ***/
    cycles = cycles + 5;if (pszv != 0) { pull(); };;break;
case 0x0c: /*** aci %1 ***/
    cycles = cycles + 8;fetch();add8bit();;break;
case 0x0d: /*** rst 08 ***/
    cycles = cycles + 5;t16 = 0x08;push();branch();;break;
case 0x0e: /*** mvi b,%1 ***/
    cycles = cycles + 8;fetch();b = mbr;;break;
case 0x0f: /*** ret ***/
    cycles = cycles + 5;pull();;break;
case 0x10: /*** inr c ***/
    cycles = cycles + 5;c = (c + 0x01) & 0xFF;pszv = c;;break;
case 0x11: /*** dcr c ***/
    cycles = cycles + 5;c = (c + 0xFF) & 0xFF;pszv = c;;break;
case 0x12: /*** ral ***/
    cycles = cycles + 5;mar = (a << 1) | carry;a = mar & 0xFF;carry = (mar >> 8) & 1;;break;
case 0x13: /*** rp ***/
    cycles = cycles + 5;if ((pszv & 0x80) == 0) { pull(); };;break;
case 0x14: /*** sui %1 ***/
    cycles = cycles + 8;fetch();carry = 0;sub8bit();a = pszv;;break;
case 0x15: /*** rst 10 ***/
    cycles = cycles + 5;t16 = 0x10;push();branch();;break;
case 0x16: /*** mvi c,%1 ***/
    cycles = cycles + 8;fetch();c = mbr;;break;
case 0x17: /*** ret ***/
    cycles = cycles + 5;pull();;break;
case 0x18: /*** inr d ***/
    cycles = cycles + 5;d = (d + 0x01) & 0xFF;pszv = d;;break;
case 0x19: /*** dcr d ***/
    cycles = cycles + 5;d = (d + 0xFF) & 0xFF;pszv = d;;break;
case 0x1a: /*** rar ***/
    cycles = cycles + 5;mar = a | (carry << 8);a = (mar >> 1) & 0xFF;carry = mar & 1;;break;
case 0x1b: /*** rpo ***/
    cycles = cycles + 5;if (parityeven(pszv) == 0) { pull(); };;break;
case 0x1c: /*** sbi %1 ***/
    cycles = cycles + 8;fetch();sub8bit();a = pszv;;break;
case 0x1d: /*** rst 18 ***/
    cycles = cycles + 5;t16 = 0x18;push();branch();;break;
case 0x1e: /*** mvi d,%1 ***/
    cycles = cycles + 8;fetch();d = mbr;;break;
case 0x1f: /*** ret ***/
    cycles = cycles + 5;pull();;break;
case 0x20: /*** inr e ***/
    cycles = cycles + 5;e = (e + 0x01) & 0xFF;pszv = e;;break;
case 0x21: /*** dcr e ***/
    cycles = cycles + 5;e = (e + 0xFF) & 0xFF;pszv = e;;break;
case 0x22: /*** db 22 ***/
    ;break;
case 0x23: /*** rc ***/
    cycles = cycles + 5;if (carry != 0) { pull(); };;break;
case 0x24: /*** ani %1 ***/
    cycles = cycles + 8;fetch();carry = 0;a = a & mbr;pszv = a;;break;
case 0x25: /*** rst 20 ***/
    cycles = cycles + 5;t16 = 0x20;push();branch();;break;
case 0x26: /*** mvi e,%1 ***/
    cycles = cycles + 8;fetch();e = mbr;;break;
case 0x27: /*** ret ***/
    cycles = cycles + 5;pull();;break;
case 0x28: /*** inr h ***/
    cycles = cycles + 5;h = (h + 0x01) & 0xFF;pszv = h;;break;
case 0x29: /*** dcr h ***/
    cycles = cycles + 5;h = (h + 0xFF) & 0xFF;pszv = h;;break;
case 0x2a: /*** db 2a ***/
    ;break;
case 0x2b: /*** rz ***/
    cycles = cycles + 5;if (pszv == 0) { pull(); };;break;
case 0x2c: /*** xri %1 ***/
    cycles = cycles + 8;fetch();carry = 0;a = a ^ mbr;pszv = a;;break;
case 0x2d: /*** rst 28 ***/
    cycles = cycles + 5;t16 = 0x28;push();branch();;break;
case 0x2e: /*** mvi h,%1 ***/
    cycles = cycles + 8;fetch();h = mbr;;break;
case 0x2f: /*** ret ***/
    cycles = cycles + 5;pull();;break;
case 0x30: /*** inr l ***/
    cycles = cycles + 5;l = (l + 0x01) & 0xFF;pszv = l;;break;
case 0x31: /*** dcr l ***/
    cycles = cycles + 5;l = (l + 0xFF) & 0xFF;pszv = l;;break;
case 0x32: /*** db 32 ***/
    ;break;
case 0x33: /*** rm ***/
    cycles = cycles + 5;if ((pszv & 0x80) != 0) { pull(); };;break;
case 0x34: /*** ori %1 ***/
    cycles = cycles + 8;fetch();carry = 0;a = a | mbr;pszv = a;;break;
case 0x35: /*** rst 30 ***/
    cycles = cycles + 5;t16 = 0x30;push();branch();;break;
case 0x36: /*** mvi l,%1 ***/
    cycles = cycles + 8;fetch();l = mbr;;break;
case 0x37: /*** ret ***/
    cycles = cycles + 5;pull();;break;
case 0x38: /*** db 38 ***/
    ;break;
case 0x39: /*** db 39 ***/
    ;break;
case 0x3a: /*** db 3a ***/
    ;break;
case 0x3b: /*** rpe ***/
    cycles = cycles + 5;if (parityeven(pszv) != 0) { pull(); };;break;
case 0x3c: /*** cpi %1 ***/
    cycles = cycles + 8;fetch();carry = 0;sub8bit();;break;
case 0x3d: /*** rst 38 ***/
    cycles = cycles + 5;t16 = 0x38;push();branch();;break;
case 0x3e: /*** mvi m,%1 ***/
    cycles = cycles + 9;fetch();mar = ((h << 8) | l);write();;break;
case 0x3f: /*** ret ***/
    cycles = cycles + 5;pull();;break;
case 0x40: /*** jnc %2 ***/
    cycles = cycles + 10;fetch16();if (carry == 0) { branch(); };;break;
case 0x41: /*** in 00 ***/
    cycles = cycles + 8;a = input00();;break;
case 0x42: /*** cnc %2 ***/
    cycles = cycles + 10;fetch16();if (carry == 0) { push();branch(); };;break;
case 0x43: /*** in 01 ***/
    cycles = cycles + 8;a = input01();;break;
case 0x44: /*** jmp %2 ***/
    cycles = cycles + 11;fetch16();branch();;break;
case 0x45: /*** in 02 ***/
    cycles = cycles + 8;a = input02();;break;
case 0x46: /*** call %2 ***/
    cycles = cycles + 11;fetch16();push();branch();;break;
case 0x47: /*** in 03 ***/
    cycles = cycles + 8;a = input03();;break;
case 0x48: /*** jnz %2 ***/
    cycles = cycles + 10;fetch16();if (pszv != 0) { branch(); };;break;
case 0x49: /*** in 04 ***/
    cycles = cycles + 8;a = input04();;break;
case 0x4a: /*** cnz %2 ***/
    cycles = cycles + 10;fetch16();if (pszv != 0) { push();branch(); };;break;
case 0x4b: /*** in 05 ***/
    cycles = cycles + 8;a = input05();;break;
case 0x4c: /*** jmp %2 ***/
    cycles = cycles + 11;fetch16();branch();;break;
case 0x4d: /*** in 06 ***/
    cycles = cycles + 8;a = input06();;break;
case 0x4e: /*** call %2 ***/
    cycles = cycles + 11;fetch16();push();branch();;break;
case 0x4f: /*** in 07 ***/
    cycles = cycles + 8;a = input07();;break;
case 0x50: /*** jp %2 ***/
    cycles = cycles + 10;fetch16();if ((pszv & 0x80) == 0) { branch(); };;break;
case 0x51: /*** out 08 ***/
    cycles = cycles + 6;output08(a);;break;
case 0x52: /*** cp %2 ***/
    cycles = cycles + 10;fetch16();if ((pszv & 0x80) == 0) { push();branch(); };;break;
case 0x53: /*** out 09 ***/
    cycles = cycles + 6;output09(a);;break;
case 0x54: /*** jmp %2 ***/
    cycles = cycles + 11;fetch16();branch();;break;
case 0x55: /*** out 0a ***/
    cycles = cycles + 6;output0a(a);;break;
case 0x56: /*** call %2 ***/
    cycles = cycles + 11;fetch16();push();branch();;break;
case 0x57: /*** out 0b ***/
    cycles = cycles + 6;output0b(a);;break;
case 0x58: /*** jpo %2 ***/
    cycles = cycles + 10;fetch16();if (parityeven(pszv) == 0) { branch(); };;break;
case 0x59: /*** out 0c ***/
    cycles = cycles + 6;output0c(a);;break;
case 0x5a: /*** cpo %2 ***/
    cycles = cycles + 10;fetch16();if (parityeven(pszv) == 0) { push();branch(); };;break;
case 0x5b: /*** out 0d ***/
    cycles = cycles + 6;output0d(a);;break;
case 0x5c: /*** jmp %2 ***/
    cycles = cycles + 11;fetch16();branch();;break;
case 0x5d: /*** out 0e ***/
    cycles = cycles + 6;output0e(a);;break;
case 0x5e: /*** call %2 ***/
    cycles = cycles + 11;fetch16();push();branch();;break;
case 0x5f: /*** out 0f ***/
    cycles = cycles + 6;output0f(a);;break;
case 0x60: /*** jc %2 ***/
    cycles = cycles + 10;fetch16();if (carry != 0) { branch(); };;break;
case 0x61: /*** out 10 ***/
    cycles = cycles + 6;output10(a);;break;
case 0x62: /*** cc %2 ***/
    cycles = cycles + 10;fetch16();if (carry != 0) { push();branch(); };;break;
case 0x63: /*** out 11 ***/
    cycles = cycles + 6;output11(a);;break;
case 0x64: /*** jmp %2 ***/
    cycles = cycles + 11;fetch16();branch();;break;
case 0x65: /*** out 12 ***/
    cycles = cycles + 6;output12(a);;break;
case 0x66: /*** call %2 ***/
    cycles = cycles + 11;fetch16();push();branch();;break;
case 0x67: /*** out 13 ***/
    cycles = cycles + 6;output13(a);;break;
case 0x68: /*** jz %2 ***/
    cycles = cycles + 10;fetch16();if (pszv == 0) { branch(); };;break;
case 0x69: /*** out 14 ***/
    cycles = cycles + 6;output14(a);;break;
case 0x6a: /*** cz %2 ***/
    cycles = cycles + 10;fetch16();if (pszv == 0) { push();branch(); };;break;
case 0x6b: /*** out 15 ***/
    cycles = cycles + 6;output15(a);;break;
case 0x6c: /*** jmp %2 ***/
    cycles = cycles + 11;fetch16();branch();;break;
case 0x6d: /*** out 16 ***/
    cycles = cycles + 6;output16(a);;break;
case 0x6e: /*** call %2 ***/
    cycles = cycles + 11;fetch16();push();branch();;break;
case 0x6f: /*** out 17 ***/
    cycles = cycles + 6;output17(a);;break;
case 0x70: /*** jm %2 ***/
    cycles = cycles + 10;fetch16();if ((pszv & 0x80) != 0) { branch(); };;break;
case 0x71: /*** out 18 ***/
    cycles = cycles + 6;output18(a);;break;
case 0x72: /*** cm %2 ***/
    cycles = cycles + 10;fetch16();if ((pszv & 0x80) != 0) { push();branch(); };;break;
case 0x73: /*** out 19 ***/
    cycles = cycles + 6;output19(a);;break;
case 0x74: /*** jmp %2 ***/
    cycles = cycles + 11;fetch16();branch();;break;
case 0x75: /*** out 1a ***/
    cycles = cycles + 6;output1a(a);;break;
case 0x76: /*** call %2 ***/
    cycles = cycles + 11;fetch16();push();branch();;break;
case 0x77: /*** out 1b ***/
    cycles = cycles + 6;output1b(a);;break;
case 0x78: /*** jpe %2 ***/
    cycles = cycles + 10;fetch16();if (parityeven(pszv) != 0) { branch(); };;break;
case 0x79: /*** out 1c ***/
    cycles = cycles + 6;output1c(a);;break;
case 0x7a: /*** cpe %2 ***/
    cycles = cycles + 10;fetch16();if (parityeven(pszv) != 0) { push();branch(); };;break;
case 0x7b: /*** out 1d ***/
    cycles = cycles + 6;output1d(a);;break;
case 0x7c: /*** jmp %2 ***/
    cycles = cycles + 11;fetch16();branch();;break;
case 0x7d: /*** out 1e ***/
    cycles = cycles + 6;output1e(a);;break;
case 0x7e: /*** call %2 ***/
    cycles = cycles + 11;fetch16();push();branch();;break;
case 0x7f: /*** out 1f ***/
    cycles = cycles + 6;output1f(a);;break;
case 0x80: /*** add a ***/
    cycles = cycles + 5;mbr = a;carry = 0;add8bit();;break;
case 0x81: /*** add b ***/
    cycles = cycles + 5;mbr = b;carry = 0;add8bit();;break;
case 0x82: /*** add c ***/
    cycles = cycles + 5;mbr = c;carry = 0;add8bit();;break;
case 0x83: /*** add d ***/
    cycles = cycles + 5;mbr = d;carry = 0;add8bit();;break;
case 0x84: /*** add e ***/
    cycles = cycles + 5;mbr = e;carry = 0;add8bit();;break;
case 0x85: /*** add h ***/
    cycles = cycles + 5;mbr = h;carry = 0;add8bit();;break;
case 0x86: /*** add l ***/
    cycles = cycles + 5;mbr = l;carry = 0;add8bit();;break;
case 0x87: /*** add m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);carry = 0;read();add8bit();;break;
case 0x88: /*** adc a ***/
    cycles = cycles + 5;mbr = a;add8bit();;break;
case 0x89: /*** adc b ***/
    cycles = cycles + 5;mbr = b;add8bit();;break;
case 0x8a: /*** adc c ***/
    cycles = cycles + 5;mbr = c;add8bit();;break;
case 0x8b: /*** adc d ***/
    cycles = cycles + 5;mbr = d;add8bit();;break;
case 0x8c: /*** adc e ***/
    cycles = cycles + 5;mbr = e;add8bit();;break;
case 0x8d: /*** adc h ***/
    cycles = cycles + 5;mbr = h;add8bit();;break;
case 0x8e: /*** adc l ***/
    cycles = cycles + 5;mbr = l;add8bit();;break;
case 0x8f: /*** adc m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);read();add8bit();;break;
case 0x90: /*** sub a ***/
    cycles = cycles + 5;mbr = a;carry = 0;sub8bit();a = pszv;;break;
case 0x91: /*** sub b ***/
    cycles = cycles + 5;mbr = b;carry = 0;sub8bit();a = pszv;;break;
case 0x92: /*** sub c ***/
    cycles = cycles + 5;mbr = c;carry = 0;sub8bit();a = pszv;;break;
case 0x93: /*** sub d ***/
    cycles = cycles + 5;mbr = d;carry = 0;sub8bit();a = pszv;;break;
case 0x94: /*** sub e ***/
    cycles = cycles + 5;mbr = e;carry = 0;sub8bit();a = pszv;;break;
case 0x95: /*** sub h ***/
    cycles = cycles + 5;mbr = h;carry = 0;sub8bit();a = pszv;;break;
case 0x96: /*** sub l ***/
    cycles = cycles + 5;mbr = l;carry = 0;sub8bit();a = pszv;;break;
case 0x97: /*** sub m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);carry = 0;read();sub8bit();a = pszv;;break;
case 0x98: /*** sbb a ***/
    cycles = cycles + 5;mbr = a;sub8bit();a = pszv;;break;
case 0x99: /*** sbb b ***/
    cycles = cycles + 5;mbr = b;sub8bit();a = pszv;;break;
case 0x9a: /*** sbb c ***/
    cycles = cycles + 5;mbr = c;sub8bit();a = pszv;;break;
case 0x9b: /*** sbb d ***/
    cycles = cycles + 5;mbr = d;sub8bit();a = pszv;;break;
case 0x9c: /*** sbb e ***/
    cycles = cycles + 5;mbr = e;sub8bit();a = pszv;;break;
case 0x9d: /*** sbb h ***/
    cycles = cycles + 5;mbr = h;sub8bit();a = pszv;;break;
case 0x9e: /*** sbb l ***/
    cycles = cycles + 5;mbr = l;sub8bit();a = pszv;;break;
case 0x9f: /*** sbb m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);read();sub8bit();a = pszv;;break;
case 0xa0: /*** and a ***/
    cycles = cycles + 5;carry = 0;a = a & a;pszv = a;;break;
case 0xa1: /*** and b ***/
    cycles = cycles + 5;carry = 0;a = a & b;pszv = a;;break;
case 0xa2: /*** and c ***/
    cycles = cycles + 5;carry = 0;a = a & c;pszv = a;;break;
case 0xa3: /*** and d ***/
    cycles = cycles + 5;carry = 0;a = a & d;pszv = a;;break;
case 0xa4: /*** and e ***/
    cycles = cycles + 5;carry = 0;a = a & e;pszv = a;;break;
case 0xa5: /*** and h ***/
    cycles = cycles + 5;carry = 0;a = a & h;pszv = a;;break;
case 0xa6: /*** and l ***/
    cycles = cycles + 5;carry = 0;a = a & l;pszv = a;;break;
case 0xa7: /*** and m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);read();carry = 0;a = a & mbr;pszv = a;;break;
case 0xa8: /*** xor a ***/
    cycles = cycles + 5;carry = 0;a = a ^ a;pszv = a;;break;
case 0xa9: /*** xor b ***/
    cycles = cycles + 5;carry = 0;a = a ^ b;pszv = a;;break;
case 0xaa: /*** xor c ***/
    cycles = cycles + 5;carry = 0;a = a ^ c;pszv = a;;break;
case 0xab: /*** xor d ***/
    cycles = cycles + 5;carry = 0;a = a ^ d;pszv = a;;break;
case 0xac: /*** xor e ***/
    cycles = cycles + 5;carry = 0;a = a ^ e;pszv = a;;break;
case 0xad: /*** xor h ***/
    cycles = cycles + 5;carry = 0;a = a ^ h;pszv = a;;break;
case 0xae: /*** xor l ***/
    cycles = cycles + 5;carry = 0;a = a ^ l;pszv = a;;break;
case 0xaf: /*** xor m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);read();carry = 0;a = a ^ mbr;pszv = a;;break;
case 0xb0: /*** or a ***/
    cycles = cycles + 5;carry = 0;a = a | a;pszv = a;;break;
case 0xb1: /*** or b ***/
    cycles = cycles + 5;carry = 0;a = a | b;pszv = a;;break;
case 0xb2: /*** or c ***/
    cycles = cycles + 5;carry = 0;a = a | c;pszv = a;;break;
case 0xb3: /*** or d ***/
    cycles = cycles + 5;carry = 0;a = a | d;pszv = a;;break;
case 0xb4: /*** or e ***/
    cycles = cycles + 5;carry = 0;a = a | e;pszv = a;;break;
case 0xb5: /*** or h ***/
    cycles = cycles + 5;carry = 0;a = a | h;pszv = a;;break;
case 0xb6: /*** or l ***/
    cycles = cycles + 5;carry = 0;a = a | l;pszv = a;;break;
case 0xb7: /*** or m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);read();carry = 0;a = a | mbr;pszv = a;;break;
case 0xb8: /*** cmp a ***/
    cycles = cycles + 5;mbr = a;carry = 0;sub8bit();;break;
case 0xb9: /*** cmp b ***/
    cycles = cycles + 5;mbr = b;carry = 0;sub8bit();;break;
case 0xba: /*** cmp c ***/
    cycles = cycles + 5;mbr = c;carry = 0;sub8bit();;break;
case 0xbb: /*** cmp d ***/
    cycles = cycles + 5;mbr = d;carry = 0;sub8bit();;break;
case 0xbc: /*** cmp e ***/
    cycles = cycles + 5;mbr = e;carry = 0;sub8bit();;break;
case 0xbd: /*** cmp h ***/
    cycles = cycles + 5;mbr = h;carry = 0;sub8bit();;break;
case 0xbe: /*** cmp l ***/
    cycles = cycles + 5;mbr = l;carry = 0;sub8bit();;break;
case 0xbf: /*** cmp m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);carry = 0;read();sub8bit();;break;
case 0xc0: /*** mov a,a ***/
    cycles = cycles + 5;a = a;;break;
case 0xc1: /*** mov a,b ***/
    cycles = cycles + 5;a = b;;break;
case 0xc2: /*** mov a,c ***/
    cycles = cycles + 5;a = c;;break;
case 0xc3: /*** mov a,d ***/
    cycles = cycles + 5;a = d;;break;
case 0xc4: /*** mov a,e ***/
    cycles = cycles + 5;a = e;;break;
case 0xc5: /*** mov a,h ***/
    cycles = cycles + 5;a = h;;break;
case 0xc6: /*** mov a,l ***/
    cycles = cycles + 5;a = l;;break;
case 0xc7: /*** mov a,m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);read();a = mbr;;break;
case 0xc8: /*** mov b,a ***/
    cycles = cycles + 5;b = a;;break;
case 0xc9: /*** mov b,b ***/
    cycles = cycles + 5;b = b;;break;
case 0xca: /*** mov b,c ***/
    cycles = cycles + 5;b = c;;break;
case 0xcb: /*** mov b,d ***/
    cycles = cycles + 5;b = d;;break;
case 0xcc: /*** mov b,e ***/
    cycles = cycles + 5;b = e;;break;
case 0xcd: /*** mov b,h ***/
    cycles = cycles + 5;b = h;;break;
case 0xce: /*** mov b,l ***/
    cycles = cycles + 5;b = l;;break;
case 0xcf: /*** mov b,m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);read();b = mbr;;break;
case 0xd0: /*** mov c,a ***/
    cycles = cycles + 5;c = a;;break;
case 0xd1: /*** mov c,b ***/
    cycles = cycles + 5;c = b;;break;
case 0xd2: /*** mov c,c ***/
    cycles = cycles + 5;c = c;;break;
case 0xd3: /*** mov c,d ***/
    cycles = cycles + 5;c = d;;break;
case 0xd4: /*** mov c,e ***/
    cycles = cycles + 5;c = e;;break;
case 0xd5: /*** mov c,h ***/
    cycles = cycles + 5;c = h;;break;
case 0xd6: /*** mov c,l ***/
    cycles = cycles + 5;c = l;;break;
case 0xd7: /*** mov c,m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);read();c = mbr;;break;
case 0xd8: /*** mov d,a ***/
    cycles = cycles + 5;d = a;;break;
case 0xd9: /*** mov d,b ***/
    cycles = cycles + 5;d = b;;break;
case 0xda: /*** mov d,c ***/
    cycles = cycles + 5;d = c;;break;
case 0xdb: /*** mov d,d ***/
    cycles = cycles + 5;d = d;;break;
case 0xdc: /*** mov d,e ***/
    cycles = cycles + 5;d = e;;break;
case 0xdd: /*** mov d,h ***/
    cycles = cycles + 5;d = h;;break;
case 0xde: /*** mov d,l ***/
    cycles = cycles + 5;d = l;;break;
case 0xdf: /*** mov d,m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);read();d = mbr;;break;
case 0xe0: /*** mov e,a ***/
    cycles = cycles + 5;e = a;;break;
case 0xe1: /*** mov e,b ***/
    cycles = cycles + 5;e = b;;break;
case 0xe2: /*** mov e,c ***/
    cycles = cycles + 5;e = c;;break;
case 0xe3: /*** mov e,d ***/
    cycles = cycles + 5;e = d;;break;
case 0xe4: /*** mov e,e ***/
    cycles = cycles + 5;e = e;;break;
case 0xe5: /*** mov e,h ***/
    cycles = cycles + 5;e = h;;break;
case 0xe6: /*** mov e,l ***/
    cycles = cycles + 5;e = l;;break;
case 0xe7: /*** mov e,m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);read();e = mbr;;break;
case 0xe8: /*** mov h,a ***/
    cycles = cycles + 5;h = a;;break;
case 0xe9: /*** mov h,b ***/
    cycles = cycles + 5;h = b;;break;
case 0xea: /*** mov h,c ***/
    cycles = cycles + 5;h = c;;break;
case 0xeb: /*** mov h,d ***/
    cycles = cycles + 5;h = d;;break;
case 0xec: /*** mov h,e ***/
    cycles = cycles + 5;h = e;;break;
case 0xed: /*** mov h,h ***/
    cycles = cycles + 5;h = h;;break;
case 0xee: /*** mov h,l ***/
    cycles = cycles + 5;h = l;;break;
case 0xef: /*** mov h,m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);read();h = mbr;;break;
case 0xf0: /*** mov l,a ***/
    cycles = cycles + 5;l = a;;break;
case 0xf1: /*** mov l,b ***/
    cycles = cycles + 5;l = b;;break;
case 0xf2: /*** mov l,c ***/
    cycles = cycles + 5;l = c;;break;
case 0xf3: /*** mov l,d ***/
    cycles = cycles + 5;l = d;;break;
case 0xf4: /*** mov l,e ***/
    cycles = cycles + 5;l = e;;break;
case 0xf5: /*** mov l,h ***/
    cycles = cycles + 5;l = h;;break;
case 0xf6: /*** mov l,l ***/
    cycles = cycles + 5;l = l;;break;
case 0xf7: /*** mov l,m ***/
    cycles = cycles + 8;mar = ((h << 8) | l);read();l = mbr;;break;
case 0xf8: /*** mov m,a ***/
    cycles = cycles + 7;mar = ((h << 8) | l);mbr = a;write();;break;
case 0xf9: /*** mov m,b ***/
    cycles = cycles + 7;mar = ((h << 8) | l);mbr = b;write();;break;
case 0xfa: /*** mov m,c ***/
    cycles = cycles + 7;mar = ((h << 8) | l);mbr = c;write();;break;
case 0xfb: /*** mov m,d ***/
    cycles = cycles + 7;mar = ((h << 8) | l);mbr = d;write();;break;
case 0xfc: /*** mov m,e ***/
    cycles = cycles + 7;mar = ((h << 8) | l);mbr = e;write();;break;
case 0xfd: /*** mov m,h ***/
    cycles = cycles + 7;mar = ((h << 8) | l);mbr = h;write();;break;
case 0xfe: /*** mov m,l ***/
    cycles = cycles + 7;mar = ((h << 8) | l);mbr = l;write();;break;
case 0xff: /*** halt ***/
    cycles = cycles + 4;halt = 1;;break;
