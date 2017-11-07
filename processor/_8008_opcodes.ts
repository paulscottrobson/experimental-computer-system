class CPU8008_Opcodes extends CPU8008_Base {

private this.add8bit() : void {
 this.t16 = this.a + this.mbr + this.carry;
 this.a = (this.t16 & 0xFF);
 this.carry = (this.t16 >> 8) & 1;
 this.pszv = this.a;
}
private this.sub8bit() : void {
 this.t16 = this.a - this.mbr - this.carry;
 this.pszv = (this.t16 & 0xFF);
 this.carry = (this.t16 >> 8) & 1;
}
private this.fetch() : void {
 this.mar = this.stack[this.stix];
 this.read();
 this.stack[this.stix] = (this.mar + 1) & 0x3FFF;
}
private this.fetch16() : void {
 this.fetch();
 this.t16 = this.mbr;
 this.fetch();
 this.t16 = (this.t16 | (this.mbr << 8)) & 0x3FFF;
}
private this.push() : void {
   this.stix = (this.stix + 1) & 7 ;
}
private this.pull() : void {
   this.stix = (this.stix - 1) & 7 ;
}
private this.branch() : void {
 this.stack[this.stix] = this.t16;
}public getOpcodeList():Function[] {
    opcode_00(),opcode_01(),opcode_02(),opcode_03(),opcode_04(),opcode_05(),opcode_06(),opcode_07(),opcode_08(),opcode_09(),opcode_0a(),opcode_0b(),opcode_0c(),opcode_0d(),opcode_0e(),opcode_0f(),opcode_10(),opcode_11(),opcode_12(),opcode_13(),opcode_14(),opcode_15(),opcode_16(),opcode_17(),opcode_18(),opcode_19(),opcode_1a(),opcode_1b(),opcode_1c(),opcode_1d(),opcode_1e(),opcode_1f(),opcode_20(),opcode_21(),opcode_22(),opcode_23(),opcode_24(),opcode_25(),opcode_26(),opcode_27(),opcode_28(),opcode_29(),opcode_2a(),opcode_2b(),opcode_2c(),opcode_2d(),opcode_2e(),opcode_2f(),opcode_30(),opcode_31(),opcode_32(),opcode_33(),opcode_34(),opcode_35(),opcode_36(),opcode_37(),opcode_38(),opcode_39(),opcode_3a(),opcode_3b(),opcode_3c(),opcode_3d(),opcode_3e(),opcode_3f(),opcode_40(),opcode_41(),opcode_42(),opcode_43(),opcode_44(),opcode_45(),opcode_46(),opcode_47(),opcode_48(),opcode_49(),opcode_4a(),opcode_4b(),opcode_4c(),opcode_4d(),opcode_4e(),opcode_4f(),opcode_50(),opcode_51(),opcode_52(),opcode_53(),opcode_54(),opcode_55(),opcode_56(),opcode_57(),opcode_58(),opcode_59(),opcode_5a(),opcode_5b(),opcode_5c(),opcode_5d(),opcode_5e(),opcode_5f(),opcode_60(),opcode_61(),opcode_62(),opcode_63(),opcode_64(),opcode_65(),opcode_66(),opcode_67(),opcode_68(),opcode_69(),opcode_6a(),opcode_6b(),opcode_6c(),opcode_6d(),opcode_6e(),opcode_6f(),opcode_70(),opcode_71(),opcode_72(),opcode_73(),opcode_74(),opcode_75(),opcode_76(),opcode_77(),opcode_78(),opcode_79(),opcode_7a(),opcode_7b(),opcode_7c(),opcode_7d(),opcode_7e(),opcode_7f(),opcode_80(),opcode_81(),opcode_82(),opcode_83(),opcode_84(),opcode_85(),opcode_86(),opcode_87(),opcode_88(),opcode_89(),opcode_8a(),opcode_8b(),opcode_8c(),opcode_8d(),opcode_8e(),opcode_8f(),opcode_90(),opcode_91(),opcode_92(),opcode_93(),opcode_94(),opcode_95(),opcode_96(),opcode_97(),opcode_98(),opcode_99(),opcode_9a(),opcode_9b(),opcode_9c(),opcode_9d(),opcode_9e(),opcode_9f(),opcode_a0(),opcode_a1(),opcode_a2(),opcode_a3(),opcode_a4(),opcode_a5(),opcode_a6(),opcode_a7(),opcode_a8(),opcode_a9(),opcode_aa(),opcode_ab(),opcode_ac(),opcode_ad(),opcode_ae(),opcode_af(),opcode_b0(),opcode_b1(),opcode_b2(),opcode_b3(),opcode_b4(),opcode_b5(),opcode_b6(),opcode_b7(),opcode_b8(),opcode_b9(),opcode_ba(),opcode_bb(),opcode_bc(),opcode_bd(),opcode_be(),opcode_bf(),opcode_c0(),opcode_c1(),opcode_c2(),opcode_c3(),opcode_c4(),opcode_c5(),opcode_c6(),opcode_c7(),opcode_c8(),opcode_c9(),opcode_ca(),opcode_cb(),opcode_cc(),opcode_cd(),opcode_ce(),opcode_cf(),opcode_d0(),opcode_d1(),opcode_d2(),opcode_d3(),opcode_d4(),opcode_d5(),opcode_d6(),opcode_d7(),opcode_d8(),opcode_d9(),opcode_da(),opcode_db(),opcode_dc(),opcode_dd(),opcode_de(),opcode_df(),opcode_e0(),opcode_e1(),opcode_e2(),opcode_e3(),opcode_e4(),opcode_e5(),opcode_e6(),opcode_e7(),opcode_e8(),opcode_e9(),opcode_ea(),opcode_eb(),opcode_ec(),opcode_ed(),opcode_ee(),opcode_ef(),opcode_f0(),opcode_f1(),opcode_f2(),opcode_f3(),opcode_f4(),opcode_f5(),opcode_f6(),opcode_f7(),opcode_f8(),opcode_f9(),opcode_fa(),opcode_fb(),opcode_fc(),opcode_fd(),opcode_fe(),opcode_ff()
}

private opcode_00(): void { /*** halt ***/
this.cycles = this.cycles + 4;this.halt = 1;; }
private opcode_01(): void { /*** halt ***/
this.cycles = this.cycles + 4;this.halt = 1;; }
private opcode_02(): void { /*** rlc ***/
this.cycles = this.cycles + 5;this.a = ((this.a << 1) | (this.a >> 7)) & 0xFF;this.carry = this.a & 1;; }
private opcode_03(): void { /*** rnc ***/
this.cycles = this.cycles + 5;if (this.carry == 0) { this.pull(); };; }
private opcode_04(): void { /*** adi %1 ***/
this.cycles = this.cycles + 8;this.fetch();this.carry = 0;this.add8bit();; }
private opcode_05(): void { /*** rst 00 ***/
this.cycles = this.cycles + 5;this.t16 = 0x00;this.push();this.branch();; }
private opcode_06(): void { /*** mvi a,%1 ***/
this.cycles = this.cycles + 8;this.fetch();this.a = this.mbr;; }
private opcode_07(): void { /*** ret ***/
this.cycles = this.cycles + 5;this.pull();; }
private opcode_08(): void { /*** inr b ***/
this.cycles = this.cycles + 5;this.b = (this.b + 0x01) & 0xFF;this.pszv = this.b;; }
private opcode_09(): void { /*** dcr b ***/
this.cycles = this.cycles + 5;this.b = (this.b + 0xFF) & 0xFF;this.pszv = this.b;; }
private opcode_0a(): void { /*** rrc ***/
this.cycles = this.cycles + 5;this.carry = this.a & 1;this.a = (this.a >> 1) | (this.carry << 7);; }
private opcode_0b(): void { /*** rnz ***/
this.cycles = this.cycles + 5;if (this.pszv != 0) { this.pull(); };; }
private opcode_0c(): void { /*** aci %1 ***/
this.cycles = this.cycles + 8;this.fetch();this.add8bit();; }
private opcode_0d(): void { /*** rst 08 ***/
this.cycles = this.cycles + 5;this.t16 = 0x08;this.push();this.branch();; }
private opcode_0e(): void { /*** mvi b,%1 ***/
this.cycles = this.cycles + 8;this.fetch();this.b = this.mbr;; }
private opcode_0f(): void { /*** ret ***/
this.cycles = this.cycles + 5;this.pull();; }
private opcode_10(): void { /*** inr c ***/
this.cycles = this.cycles + 5;this.c = (this.c + 0x01) & 0xFF;this.pszv = this.c;; }
private opcode_11(): void { /*** dcr c ***/
this.cycles = this.cycles + 5;this.c = (this.c + 0xFF) & 0xFF;this.pszv = this.c;; }
private opcode_12(): void { /*** ral ***/
this.cycles = this.cycles + 5;this.mar = (this.a << 1) | this.carry;this.a = this.mar & 0xFF;this.carry = (this.mar >> 8) & 1;; }
private opcode_13(): void { /*** rp ***/
this.cycles = this.cycles + 5;if ((this.pszv & 0x80) == 0) { this.pull(); };; }
private opcode_14(): void { /*** sui %1 ***/
this.cycles = this.cycles + 8;this.fetch();this.carry = 0;this.sub8bit();this.a = this.pszv;; }
private opcode_15(): void { /*** rst 10 ***/
this.cycles = this.cycles + 5;this.t16 = 0x10;this.push();this.branch();; }
private opcode_16(): void { /*** mvi c,%1 ***/
this.cycles = this.cycles + 8;this.fetch();this.c = this.mbr;; }
private opcode_17(): void { /*** ret ***/
this.cycles = this.cycles + 5;this.pull();; }
private opcode_18(): void { /*** inr d ***/
this.cycles = this.cycles + 5;this.d = (this.d + 0x01) & 0xFF;this.pszv = this.d;; }
private opcode_19(): void { /*** dcr d ***/
this.cycles = this.cycles + 5;this.d = (this.d + 0xFF) & 0xFF;this.pszv = this.d;; }
private opcode_1a(): void { /*** rar ***/
this.cycles = this.cycles + 5;this.mar = this.a | (this.carry << 8);this.a = (this.mar >> 1) & 0xFF;this.carry = this.mar & 1;; }
private opcode_1b(): void { /*** rpo ***/
this.cycles = this.cycles + 5;if (this.parityeven(this.pszv) == 0) { this.pull(); };; }
private opcode_1c(): void { /*** sbi %1 ***/
this.cycles = this.cycles + 8;this.fetch();this.sub8bit();this.a = this.pszv;; }
private opcode_1d(): void { /*** rst 18 ***/
this.cycles = this.cycles + 5;this.t16 = 0x18;this.push();this.branch();; }
private opcode_1e(): void { /*** mvi d,%1 ***/
this.cycles = this.cycles + 8;this.fetch();this.d = this.mbr;; }
private opcode_1f(): void { /*** ret ***/
this.cycles = this.cycles + 5;this.pull();; }
private opcode_20(): void { /*** inr e ***/
this.cycles = this.cycles + 5;this.e = (this.e + 0x01) & 0xFF;this.pszv = this.e;; }
private opcode_21(): void { /*** dcr e ***/
this.cycles = this.cycles + 5;this.e = (this.e + 0xFF) & 0xFF;this.pszv = this.e;; }
private opcode_22(): void { /*** db 22 ***/
; }
private opcode_23(): void { /*** rc ***/
this.cycles = this.cycles + 5;if (this.carry != 0) { this.pull(); };; }
private opcode_24(): void { /*** ani %1 ***/
this.cycles = this.cycles + 8;this.fetch();this.carry = 0;this.a = this.a & this.mbr;this.pszv = this.a;; }
private opcode_25(): void { /*** rst 20 ***/
this.cycles = this.cycles + 5;this.t16 = 0x20;this.push();this.branch();; }
private opcode_26(): void { /*** mvi e,%1 ***/
this.cycles = this.cycles + 8;this.fetch();this.e = this.mbr;; }
private opcode_27(): void { /*** ret ***/
this.cycles = this.cycles + 5;this.pull();; }
private opcode_28(): void { /*** inr h ***/
this.cycles = this.cycles + 5;this.h = (this.h + 0x01) & 0xFF;this.pszv = this.h;; }
private opcode_29(): void { /*** dcr h ***/
this.cycles = this.cycles + 5;this.h = (this.h + 0xFF) & 0xFF;this.pszv = this.h;; }
private opcode_2a(): void { /*** db 2a ***/
; }
private opcode_2b(): void { /*** rz ***/
this.cycles = this.cycles + 5;if (this.pszv == 0) { this.pull(); };; }
private opcode_2c(): void { /*** xri %1 ***/
this.cycles = this.cycles + 8;this.fetch();this.carry = 0;this.a = this.a ^ this.mbr;this.pszv = this.a;; }
private opcode_2d(): void { /*** rst 28 ***/
this.cycles = this.cycles + 5;this.t16 = 0x28;this.push();this.branch();; }
private opcode_2e(): void { /*** mvi h,%1 ***/
this.cycles = this.cycles + 8;this.fetch();this.h = this.mbr;; }
private opcode_2f(): void { /*** ret ***/
this.cycles = this.cycles + 5;this.pull();; }
private opcode_30(): void { /*** inr l ***/
this.cycles = this.cycles + 5;this.l = (this.l + 0x01) & 0xFF;this.pszv = this.l;; }
private opcode_31(): void { /*** dcr l ***/
this.cycles = this.cycles + 5;this.l = (this.l + 0xFF) & 0xFF;this.pszv = this.l;; }
private opcode_32(): void { /*** db 32 ***/
; }
private opcode_33(): void { /*** rm ***/
this.cycles = this.cycles + 5;if ((this.pszv & 0x80) != 0) { this.pull(); };; }
private opcode_34(): void { /*** ori %1 ***/
this.cycles = this.cycles + 8;this.fetch();this.carry = 0;this.a = this.a | this.mbr;this.pszv = this.a;; }
private opcode_35(): void { /*** rst 30 ***/
this.cycles = this.cycles + 5;this.t16 = 0x30;this.push();this.branch();; }
private opcode_36(): void { /*** mvi l,%1 ***/
this.cycles = this.cycles + 8;this.fetch();this.l = this.mbr;; }
private opcode_37(): void { /*** ret ***/
this.cycles = this.cycles + 5;this.pull();; }
private opcode_38(): void { /*** db 38 ***/
; }
private opcode_39(): void { /*** db 39 ***/
; }
private opcode_3a(): void { /*** db 3a ***/
; }
private opcode_3b(): void { /*** rpe ***/
this.cycles = this.cycles + 5;if (this.parityeven(this.pszv) != 0) { this.pull(); };; }
private opcode_3c(): void { /*** cpi %1 ***/
this.cycles = this.cycles + 8;this.fetch();this.carry = 0;this.sub8bit();; }
private opcode_3d(): void { /*** rst 38 ***/
this.cycles = this.cycles + 5;this.t16 = 0x38;this.push();this.branch();; }
private opcode_3e(): void { /*** mvi m,%1 ***/
this.cycles = this.cycles + 9;this.fetch();this.mar = ((this.h << 8) | this.l);this.write();; }
private opcode_3f(): void { /*** ret ***/
this.cycles = this.cycles + 5;this.pull();; }
private opcode_40(): void { /*** jnc %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if (this.carry == 0) { this.branch(); };; }
private opcode_41(): void { /*** in 00 ***/
this.cycles = this.cycles + 8;this.a = this.input00();; }
private opcode_42(): void { /*** cnc %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if (this.carry == 0) { this.push();this.branch(); };; }
private opcode_43(): void { /*** in 01 ***/
this.cycles = this.cycles + 8;this.a = this.input01();; }
private opcode_44(): void { /*** jmp %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.branch();; }
private opcode_45(): void { /*** in 02 ***/
this.cycles = this.cycles + 8;this.a = this.input02();; }
private opcode_46(): void { /*** call %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.push();this.branch();; }
private opcode_47(): void { /*** in 03 ***/
this.cycles = this.cycles + 8;this.a = this.input03();; }
private opcode_48(): void { /*** jnz %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if (this.pszv != 0) { this.branch(); };; }
private opcode_49(): void { /*** in 04 ***/
this.cycles = this.cycles + 8;this.a = this.input04();; }
private opcode_4a(): void { /*** cnz %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if (this.pszv != 0) { this.push();this.branch(); };; }
private opcode_4b(): void { /*** in 05 ***/
this.cycles = this.cycles + 8;this.a = this.input05();; }
private opcode_4c(): void { /*** jmp %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.branch();; }
private opcode_4d(): void { /*** in 06 ***/
this.cycles = this.cycles + 8;this.a = this.input06();; }
private opcode_4e(): void { /*** call %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.push();this.branch();; }
private opcode_4f(): void { /*** in 07 ***/
this.cycles = this.cycles + 8;this.a = this.input07();; }
private opcode_50(): void { /*** jp %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if ((this.pszv & 0x80) == 0) { this.branch(); };; }
private opcode_51(): void { /*** out 08 ***/
this.cycles = this.cycles + 6;this.output08(this.a);; }
private opcode_52(): void { /*** cp %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if ((this.pszv & 0x80) == 0) { this.push();this.branch(); };; }
private opcode_53(): void { /*** out 09 ***/
this.cycles = this.cycles + 6;this.output09(this.a);; }
private opcode_54(): void { /*** jmp %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.branch();; }
private opcode_55(): void { /*** out 0a ***/
this.cycles = this.cycles + 6;this.output0a(this.a);; }
private opcode_56(): void { /*** call %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.push();this.branch();; }
private opcode_57(): void { /*** out 0b ***/
this.cycles = this.cycles + 6;this.output0b(this.a);; }
private opcode_58(): void { /*** jpo %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if (this.parityeven(this.pszv) == 0) { this.branch(); };; }
private opcode_59(): void { /*** out 0c ***/
this.cycles = this.cycles + 6;this.output0c(this.a);; }
private opcode_5a(): void { /*** cpo %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if (this.parityeven(this.pszv) == 0) { this.push();this.branch(); };; }
private opcode_5b(): void { /*** out 0d ***/
this.cycles = this.cycles + 6;this.output0d(this.a);; }
private opcode_5c(): void { /*** jmp %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.branch();; }
private opcode_5d(): void { /*** out 0e ***/
this.cycles = this.cycles + 6;this.output0e(this.a);; }
private opcode_5e(): void { /*** call %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.push();this.branch();; }
private opcode_5f(): void { /*** out 0f ***/
this.cycles = this.cycles + 6;this.output0f(this.a);; }
private opcode_60(): void { /*** jc %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if (this.carry != 0) { this.branch(); };; }
private opcode_61(): void { /*** out 10 ***/
this.cycles = this.cycles + 6;this.output10(this.a);; }
private opcode_62(): void { /*** cc %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if (this.carry != 0) { this.push();this.branch(); };; }
private opcode_63(): void { /*** out 11 ***/
this.cycles = this.cycles + 6;this.output11(this.a);; }
private opcode_64(): void { /*** jmp %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.branch();; }
private opcode_65(): void { /*** out 12 ***/
this.cycles = this.cycles + 6;this.output12(this.a);; }
private opcode_66(): void { /*** call %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.push();this.branch();; }
private opcode_67(): void { /*** out 13 ***/
this.cycles = this.cycles + 6;this.output13(this.a);; }
private opcode_68(): void { /*** jz %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if (this.pszv == 0) { this.branch(); };; }
private opcode_69(): void { /*** out 14 ***/
this.cycles = this.cycles + 6;this.output14(this.a);; }
private opcode_6a(): void { /*** cz %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if (this.pszv == 0) { this.push();this.branch(); };; }
private opcode_6b(): void { /*** out 15 ***/
this.cycles = this.cycles + 6;this.output15(this.a);; }
private opcode_6c(): void { /*** jmp %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.branch();; }
private opcode_6d(): void { /*** out 16 ***/
this.cycles = this.cycles + 6;this.output16(this.a);; }
private opcode_6e(): void { /*** call %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.push();this.branch();; }
private opcode_6f(): void { /*** out 17 ***/
this.cycles = this.cycles + 6;this.output17(this.a);; }
private opcode_70(): void { /*** jm %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if ((this.pszv & 0x80) != 0) { this.branch(); };; }
private opcode_71(): void { /*** out 18 ***/
this.cycles = this.cycles + 6;this.output18(this.a);; }
private opcode_72(): void { /*** cm %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if ((this.pszv & 0x80) != 0) { this.push();this.branch(); };; }
private opcode_73(): void { /*** out 19 ***/
this.cycles = this.cycles + 6;this.output19(this.a);; }
private opcode_74(): void { /*** jmp %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.branch();; }
private opcode_75(): void { /*** out 1a ***/
this.cycles = this.cycles + 6;this.output1a(this.a);; }
private opcode_76(): void { /*** call %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.push();this.branch();; }
private opcode_77(): void { /*** out 1b ***/
this.cycles = this.cycles + 6;this.output1b(this.a);; }
private opcode_78(): void { /*** jpe %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if (this.parityeven(this.pszv) != 0) { this.branch(); };; }
private opcode_79(): void { /*** out 1c ***/
this.cycles = this.cycles + 6;this.output1c(this.a);; }
private opcode_7a(): void { /*** cpe %2 ***/
this.cycles = this.cycles + 10;this.fetch16();if (this.parityeven(this.pszv) != 0) { this.push();this.branch(); };; }
private opcode_7b(): void { /*** out 1d ***/
this.cycles = this.cycles + 6;this.output1d(this.a);; }
private opcode_7c(): void { /*** jmp %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.branch();; }
private opcode_7d(): void { /*** out 1e ***/
this.cycles = this.cycles + 6;this.output1e(this.a);; }
private opcode_7e(): void { /*** call %2 ***/
this.cycles = this.cycles + 11;this.fetch16();this.push();this.branch();; }
private opcode_7f(): void { /*** out 1f ***/
this.cycles = this.cycles + 6;this.output1f(this.a);; }
private opcode_80(): void { /*** add a ***/
this.cycles = this.cycles + 5;this.mbr = this.a;this.carry = 0;this.add8bit();; }
private opcode_81(): void { /*** add b ***/
this.cycles = this.cycles + 5;this.mbr = this.b;this.carry = 0;this.add8bit();; }
private opcode_82(): void { /*** add c ***/
this.cycles = this.cycles + 5;this.mbr = this.c;this.carry = 0;this.add8bit();; }
private opcode_83(): void { /*** add d ***/
this.cycles = this.cycles + 5;this.mbr = this.d;this.carry = 0;this.add8bit();; }
private opcode_84(): void { /*** add e ***/
this.cycles = this.cycles + 5;this.mbr = this.e;this.carry = 0;this.add8bit();; }
private opcode_85(): void { /*** add h ***/
this.cycles = this.cycles + 5;this.mbr = this.h;this.carry = 0;this.add8bit();; }
private opcode_86(): void { /*** add l ***/
this.cycles = this.cycles + 5;this.mbr = this.l;this.carry = 0;this.add8bit();; }
private opcode_87(): void { /*** add m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.carry = 0;this.read();this.add8bit();; }
private opcode_88(): void { /*** adc a ***/
this.cycles = this.cycles + 5;this.mbr = this.a;this.add8bit();; }
private opcode_89(): void { /*** adc b ***/
this.cycles = this.cycles + 5;this.mbr = this.b;this.add8bit();; }
private opcode_8a(): void { /*** adc c ***/
this.cycles = this.cycles + 5;this.mbr = this.c;this.add8bit();; }
private opcode_8b(): void { /*** adc d ***/
this.cycles = this.cycles + 5;this.mbr = this.d;this.add8bit();; }
private opcode_8c(): void { /*** adc e ***/
this.cycles = this.cycles + 5;this.mbr = this.e;this.add8bit();; }
private opcode_8d(): void { /*** adc h ***/
this.cycles = this.cycles + 5;this.mbr = this.h;this.add8bit();; }
private opcode_8e(): void { /*** adc l ***/
this.cycles = this.cycles + 5;this.mbr = this.l;this.add8bit();; }
private opcode_8f(): void { /*** adc m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.read();this.add8bit();; }
private opcode_90(): void { /*** sub a ***/
this.cycles = this.cycles + 5;this.mbr = this.a;this.carry = 0;this.sub8bit();this.a = this.pszv;; }
private opcode_91(): void { /*** sub b ***/
this.cycles = this.cycles + 5;this.mbr = this.b;this.carry = 0;this.sub8bit();this.a = this.pszv;; }
private opcode_92(): void { /*** sub c ***/
this.cycles = this.cycles + 5;this.mbr = this.c;this.carry = 0;this.sub8bit();this.a = this.pszv;; }
private opcode_93(): void { /*** sub d ***/
this.cycles = this.cycles + 5;this.mbr = this.d;this.carry = 0;this.sub8bit();this.a = this.pszv;; }
private opcode_94(): void { /*** sub e ***/
this.cycles = this.cycles + 5;this.mbr = this.e;this.carry = 0;this.sub8bit();this.a = this.pszv;; }
private opcode_95(): void { /*** sub h ***/
this.cycles = this.cycles + 5;this.mbr = this.h;this.carry = 0;this.sub8bit();this.a = this.pszv;; }
private opcode_96(): void { /*** sub l ***/
this.cycles = this.cycles + 5;this.mbr = this.l;this.carry = 0;this.sub8bit();this.a = this.pszv;; }
private opcode_97(): void { /*** sub m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.carry = 0;this.read();this.sub8bit();this.a = this.pszv;; }
private opcode_98(): void { /*** sbb a ***/
this.cycles = this.cycles + 5;this.mbr = this.a;this.sub8bit();this.a = this.pszv;; }
private opcode_99(): void { /*** sbb b ***/
this.cycles = this.cycles + 5;this.mbr = this.b;this.sub8bit();this.a = this.pszv;; }
private opcode_9a(): void { /*** sbb c ***/
this.cycles = this.cycles + 5;this.mbr = this.c;this.sub8bit();this.a = this.pszv;; }
private opcode_9b(): void { /*** sbb d ***/
this.cycles = this.cycles + 5;this.mbr = this.d;this.sub8bit();this.a = this.pszv;; }
private opcode_9c(): void { /*** sbb e ***/
this.cycles = this.cycles + 5;this.mbr = this.e;this.sub8bit();this.a = this.pszv;; }
private opcode_9d(): void { /*** sbb h ***/
this.cycles = this.cycles + 5;this.mbr = this.h;this.sub8bit();this.a = this.pszv;; }
private opcode_9e(): void { /*** sbb l ***/
this.cycles = this.cycles + 5;this.mbr = this.l;this.sub8bit();this.a = this.pszv;; }
private opcode_9f(): void { /*** sbb m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.read();this.sub8bit();this.a = this.pszv;; }
private opcode_a0(): void { /*** and a ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a & this.a;this.pszv = this.a;; }
private opcode_a1(): void { /*** and b ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a & this.b;this.pszv = this.a;; }
private opcode_a2(): void { /*** and c ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a & this.c;this.pszv = this.a;; }
private opcode_a3(): void { /*** and d ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a & this.d;this.pszv = this.a;; }
private opcode_a4(): void { /*** and e ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a & this.e;this.pszv = this.a;; }
private opcode_a5(): void { /*** and h ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a & this.h;this.pszv = this.a;; }
private opcode_a6(): void { /*** and l ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a & this.l;this.pszv = this.a;; }
private opcode_a7(): void { /*** and m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.read();this.carry = 0;this.a = this.a & this.mbr;this.pszv = this.a;; }
private opcode_a8(): void { /*** xor a ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a ^ this.a;this.pszv = this.a;; }
private opcode_a9(): void { /*** xor b ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a ^ this.b;this.pszv = this.a;; }
private opcode_aa(): void { /*** xor c ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a ^ this.c;this.pszv = this.a;; }
private opcode_ab(): void { /*** xor d ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a ^ this.d;this.pszv = this.a;; }
private opcode_ac(): void { /*** xor e ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a ^ this.e;this.pszv = this.a;; }
private opcode_ad(): void { /*** xor h ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a ^ this.h;this.pszv = this.a;; }
private opcode_ae(): void { /*** xor l ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a ^ this.l;this.pszv = this.a;; }
private opcode_af(): void { /*** xor m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.read();this.carry = 0;this.a = this.a ^ this.mbr;this.pszv = this.a;; }
private opcode_b0(): void { /*** or a ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a | this.a;this.pszv = this.a;; }
private opcode_b1(): void { /*** or b ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a | this.b;this.pszv = this.a;; }
private opcode_b2(): void { /*** or c ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a | this.c;this.pszv = this.a;; }
private opcode_b3(): void { /*** or d ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a | this.d;this.pszv = this.a;; }
private opcode_b4(): void { /*** or e ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a | this.e;this.pszv = this.a;; }
private opcode_b5(): void { /*** or h ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a | this.h;this.pszv = this.a;; }
private opcode_b6(): void { /*** or l ***/
this.cycles = this.cycles + 5;this.carry = 0;this.a = this.a | this.l;this.pszv = this.a;; }
private opcode_b7(): void { /*** or m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.read();this.carry = 0;this.a = this.a | this.mbr;this.pszv = this.a;; }
private opcode_b8(): void { /*** cmp a ***/
this.cycles = this.cycles + 5;this.mbr = this.a;this.carry = 0;this.sub8bit();; }
private opcode_b9(): void { /*** cmp b ***/
this.cycles = this.cycles + 5;this.mbr = this.b;this.carry = 0;this.sub8bit();; }
private opcode_ba(): void { /*** cmp c ***/
this.cycles = this.cycles + 5;this.mbr = this.c;this.carry = 0;this.sub8bit();; }
private opcode_bb(): void { /*** cmp d ***/
this.cycles = this.cycles + 5;this.mbr = this.d;this.carry = 0;this.sub8bit();; }
private opcode_bc(): void { /*** cmp e ***/
this.cycles = this.cycles + 5;this.mbr = this.e;this.carry = 0;this.sub8bit();; }
private opcode_bd(): void { /*** cmp h ***/
this.cycles = this.cycles + 5;this.mbr = this.h;this.carry = 0;this.sub8bit();; }
private opcode_be(): void { /*** cmp l ***/
this.cycles = this.cycles + 5;this.mbr = this.l;this.carry = 0;this.sub8bit();; }
private opcode_bf(): void { /*** cmp m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.carry = 0;this.read();this.sub8bit();; }
private opcode_c0(): void { /*** mov a,a ***/
this.cycles = this.cycles + 5;this.a = this.a;; }
private opcode_c1(): void { /*** mov a,b ***/
this.cycles = this.cycles + 5;this.a = this.b;; }
private opcode_c2(): void { /*** mov a,c ***/
this.cycles = this.cycles + 5;this.a = this.c;; }
private opcode_c3(): void { /*** mov a,d ***/
this.cycles = this.cycles + 5;this.a = this.d;; }
private opcode_c4(): void { /*** mov a,e ***/
this.cycles = this.cycles + 5;this.a = this.e;; }
private opcode_c5(): void { /*** mov a,h ***/
this.cycles = this.cycles + 5;this.a = this.h;; }
private opcode_c6(): void { /*** mov a,l ***/
this.cycles = this.cycles + 5;this.a = this.l;; }
private opcode_c7(): void { /*** mov a,m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.read();this.a = this.mbr;; }
private opcode_c8(): void { /*** mov b,a ***/
this.cycles = this.cycles + 5;this.b = this.a;; }
private opcode_c9(): void { /*** mov b,b ***/
this.cycles = this.cycles + 5;this.b = this.b;; }
private opcode_ca(): void { /*** mov b,c ***/
this.cycles = this.cycles + 5;this.b = this.c;; }
private opcode_cb(): void { /*** mov b,d ***/
this.cycles = this.cycles + 5;this.b = this.d;; }
private opcode_cc(): void { /*** mov b,e ***/
this.cycles = this.cycles + 5;this.b = this.e;; }
private opcode_cd(): void { /*** mov b,h ***/
this.cycles = this.cycles + 5;this.b = this.h;; }
private opcode_ce(): void { /*** mov b,l ***/
this.cycles = this.cycles + 5;this.b = this.l;; }
private opcode_cf(): void { /*** mov b,m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.read();this.b = this.mbr;; }
private opcode_d0(): void { /*** mov c,a ***/
this.cycles = this.cycles + 5;this.c = this.a;; }
private opcode_d1(): void { /*** mov c,b ***/
this.cycles = this.cycles + 5;this.c = this.b;; }
private opcode_d2(): void { /*** mov c,c ***/
this.cycles = this.cycles + 5;this.c = this.c;; }
private opcode_d3(): void { /*** mov c,d ***/
this.cycles = this.cycles + 5;this.c = this.d;; }
private opcode_d4(): void { /*** mov c,e ***/
this.cycles = this.cycles + 5;this.c = this.e;; }
private opcode_d5(): void { /*** mov c,h ***/
this.cycles = this.cycles + 5;this.c = this.h;; }
private opcode_d6(): void { /*** mov c,l ***/
this.cycles = this.cycles + 5;this.c = this.l;; }
private opcode_d7(): void { /*** mov c,m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.read();this.c = this.mbr;; }
private opcode_d8(): void { /*** mov d,a ***/
this.cycles = this.cycles + 5;this.d = this.a;; }
private opcode_d9(): void { /*** mov d,b ***/
this.cycles = this.cycles + 5;this.d = this.b;; }
private opcode_da(): void { /*** mov d,c ***/
this.cycles = this.cycles + 5;this.d = this.c;; }
private opcode_db(): void { /*** mov d,d ***/
this.cycles = this.cycles + 5;this.d = this.d;; }
private opcode_dc(): void { /*** mov d,e ***/
this.cycles = this.cycles + 5;this.d = this.e;; }
private opcode_dd(): void { /*** mov d,h ***/
this.cycles = this.cycles + 5;this.d = this.h;; }
private opcode_de(): void { /*** mov d,l ***/
this.cycles = this.cycles + 5;this.d = this.l;; }
private opcode_df(): void { /*** mov d,m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.read();this.d = this.mbr;; }
private opcode_e0(): void { /*** mov e,a ***/
this.cycles = this.cycles + 5;this.e = this.a;; }
private opcode_e1(): void { /*** mov e,b ***/
this.cycles = this.cycles + 5;this.e = this.b;; }
private opcode_e2(): void { /*** mov e,c ***/
this.cycles = this.cycles + 5;this.e = this.c;; }
private opcode_e3(): void { /*** mov e,d ***/
this.cycles = this.cycles + 5;this.e = this.d;; }
private opcode_e4(): void { /*** mov e,e ***/
this.cycles = this.cycles + 5;this.e = this.e;; }
private opcode_e5(): void { /*** mov e,h ***/
this.cycles = this.cycles + 5;this.e = this.h;; }
private opcode_e6(): void { /*** mov e,l ***/
this.cycles = this.cycles + 5;this.e = this.l;; }
private opcode_e7(): void { /*** mov e,m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.read();this.e = this.mbr;; }
private opcode_e8(): void { /*** mov h,a ***/
this.cycles = this.cycles + 5;this.h = this.a;; }
private opcode_e9(): void { /*** mov h,b ***/
this.cycles = this.cycles + 5;this.h = this.b;; }
private opcode_ea(): void { /*** mov h,c ***/
this.cycles = this.cycles + 5;this.h = this.c;; }
private opcode_eb(): void { /*** mov h,d ***/
this.cycles = this.cycles + 5;this.h = this.d;; }
private opcode_ec(): void { /*** mov h,e ***/
this.cycles = this.cycles + 5;this.h = this.e;; }
private opcode_ed(): void { /*** mov h,h ***/
this.cycles = this.cycles + 5;this.h = this.h;; }
private opcode_ee(): void { /*** mov h,l ***/
this.cycles = this.cycles + 5;this.h = this.l;; }
private opcode_ef(): void { /*** mov h,m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.read();this.h = this.mbr;; }
private opcode_f0(): void { /*** mov l,a ***/
this.cycles = this.cycles + 5;this.l = this.a;; }
private opcode_f1(): void { /*** mov l,b ***/
this.cycles = this.cycles + 5;this.l = this.b;; }
private opcode_f2(): void { /*** mov l,c ***/
this.cycles = this.cycles + 5;this.l = this.c;; }
private opcode_f3(): void { /*** mov l,d ***/
this.cycles = this.cycles + 5;this.l = this.d;; }
private opcode_f4(): void { /*** mov l,e ***/
this.cycles = this.cycles + 5;this.l = this.e;; }
private opcode_f5(): void { /*** mov l,h ***/
this.cycles = this.cycles + 5;this.l = this.h;; }
private opcode_f6(): void { /*** mov l,l ***/
this.cycles = this.cycles + 5;this.l = this.l;; }
private opcode_f7(): void { /*** mov l,m ***/
this.cycles = this.cycles + 8;this.mar = ((this.h << 8) | this.l);this.read();this.l = this.mbr;; }
private opcode_f8(): void { /*** mov m,a ***/
this.cycles = this.cycles + 7;this.mar = ((this.h << 8) | this.l);this.mbr = this.a;this.write();; }
private opcode_f9(): void { /*** mov m,b ***/
this.cycles = this.cycles + 7;this.mar = ((this.h << 8) | this.l);this.mbr = this.b;this.write();; }
private opcode_fa(): void { /*** mov m,c ***/
this.cycles = this.cycles + 7;this.mar = ((this.h << 8) | this.l);this.mbr = this.c;this.write();; }
private opcode_fb(): void { /*** mov m,d ***/
this.cycles = this.cycles + 7;this.mar = ((this.h << 8) | this.l);this.mbr = this.d;this.write();; }
private opcode_fc(): void { /*** mov m,e ***/
this.cycles = this.cycles + 7;this.mar = ((this.h << 8) | this.l);this.mbr = this.e;this.write();; }
private opcode_fd(): void { /*** mov m,h ***/
this.cycles = this.cycles + 7;this.mar = ((this.h << 8) | this.l);this.mbr = this.h;this.write();; }
private opcode_fe(): void { /*** mov m,l ***/
this.cycles = this.cycles + 7;this.mar = ((this.h << 8) | this.l);this.mbr = this.l;this.write();; }
private opcode_ff(): void { /*** halt ***/
this.cycles = this.cycles + 4;this.halt = 1;; }
}
