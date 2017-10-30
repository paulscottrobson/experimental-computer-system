class CPU8008_Opcodes extends CPU8008_Base {

public getOpcodeList():Function[] {
    opcode_00(),opcode_01(),opcode_02(),opcode_03(),opcode_04(),opcode_05(),opcode_06(),opcode_07(),opcode_08(),opcode_09(),opcode_0a(),opcode_0b(),opcode_0c(),opcode_0d(),opcode_0e(),opcode_0f(),opcode_10(),opcode_11(),opcode_12(),opcode_13(),opcode_14(),opcode_15(),opcode_16(),opcode_17(),opcode_18(),opcode_19(),opcode_1a(),opcode_1b(),opcode_1c(),opcode_1d(),opcode_1e(),opcode_1f(),opcode_20(),opcode_21(),opcode_22(),opcode_23(),opcode_24(),opcode_25(),opcode_26(),opcode_27(),opcode_28(),opcode_29(),opcode_2a(),opcode_2b(),opcode_2c(),opcode_2d(),opcode_2e(),opcode_2f(),opcode_30(),opcode_31(),opcode_32(),opcode_33(),opcode_34(),opcode_35(),opcode_36(),opcode_37(),opcode_38(),opcode_39(),opcode_3a(),opcode_3b(),opcode_3c(),opcode_3d(),opcode_3e(),opcode_3f(),opcode_40(),opcode_41(),opcode_42(),opcode_43(),opcode_44(),opcode_45(),opcode_46(),opcode_47(),opcode_48(),opcode_49(),opcode_4a(),opcode_4b(),opcode_4c(),opcode_4d(),opcode_4e(),opcode_4f(),opcode_50(),opcode_51(),opcode_52(),opcode_53(),opcode_54(),opcode_55(),opcode_56(),opcode_57(),opcode_58(),opcode_59(),opcode_5a(),opcode_5b(),opcode_5c(),opcode_5d(),opcode_5e(),opcode_5f(),opcode_60(),opcode_61(),opcode_62(),opcode_63(),opcode_64(),opcode_65(),opcode_66(),opcode_67(),opcode_68(),opcode_69(),opcode_6a(),opcode_6b(),opcode_6c(),opcode_6d(),opcode_6e(),opcode_6f(),opcode_70(),opcode_71(),opcode_72(),opcode_73(),opcode_74(),opcode_75(),opcode_76(),opcode_77(),opcode_78(),opcode_79(),opcode_7a(),opcode_7b(),opcode_7c(),opcode_7d(),opcode_7e(),opcode_7f(),opcode_80(),opcode_81(),opcode_82(),opcode_83(),opcode_84(),opcode_85(),opcode_86(),opcode_87(),opcode_88(),opcode_89(),opcode_8a(),opcode_8b(),opcode_8c(),opcode_8d(),opcode_8e(),opcode_8f(),opcode_90(),opcode_91(),opcode_92(),opcode_93(),opcode_94(),opcode_95(),opcode_96(),opcode_97(),opcode_98(),opcode_99(),opcode_9a(),opcode_9b(),opcode_9c(),opcode_9d(),opcode_9e(),opcode_9f(),opcode_a0(),opcode_a1(),opcode_a2(),opcode_a3(),opcode_a4(),opcode_a5(),opcode_a6(),opcode_a7(),opcode_a8(),opcode_a9(),opcode_aa(),opcode_ab(),opcode_ac(),opcode_ad(),opcode_ae(),opcode_af(),opcode_b0(),opcode_b1(),opcode_b2(),opcode_b3(),opcode_b4(),opcode_b5(),opcode_b6(),opcode_b7(),opcode_b8(),opcode_b9(),opcode_ba(),opcode_bb(),opcode_bc(),opcode_bd(),opcode_be(),opcode_bf(),opcode_c0(),opcode_c1(),opcode_c2(),opcode_c3(),opcode_c4(),opcode_c5(),opcode_c6(),opcode_c7(),opcode_c8(),opcode_c9(),opcode_ca(),opcode_cb(),opcode_cc(),opcode_cd(),opcode_ce(),opcode_cf(),opcode_d0(),opcode_d1(),opcode_d2(),opcode_d3(),opcode_d4(),opcode_d5(),opcode_d6(),opcode_d7(),opcode_d8(),opcode_d9(),opcode_da(),opcode_db(),opcode_dc(),opcode_dd(),opcode_de(),opcode_df(),opcode_e0(),opcode_e1(),opcode_e2(),opcode_e3(),opcode_e4(),opcode_e5(),opcode_e6(),opcode_e7(),opcode_e8(),opcode_e9(),opcode_ea(),opcode_eb(),opcode_ec(),opcode_ed(),opcode_ee(),opcode_ef(),opcode_f0(),opcode_f1(),opcode_f2(),opcode_f3(),opcode_f4(),opcode_f5(),opcode_f6(),opcode_f7(),opcode_f8(),opcode_f9(),opcode_fa(),opcode_fb(),opcode_fc(),opcode_fd(),opcode_fe(),opcode_ff()
}

private opcode_00(): void { /*** halt ***/
    this.halt = 1;
}
private opcode_01(): void { /*** halt ***/
    this.halt = 1;
}
private opcode_02(): void { /*** rlc ***/
    this.carry = (this.a >> 7) & 1;this.a = ((this.a << 1) | this.carry) & 0xFF;
}
private opcode_03(): void { /*** rnc ***/
    if (this.carry == 0) { this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;};
}
private opcode_04(): void { /*** adi %1 ***/
    this.pszvalue = this.a = this.add(this.fetch(),0);
}
private opcode_05(): void { /*** rst 00 ***/
    this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = 0x00;
}
private opcode_06(): void { /*** nop ***/
    ;;
}
private opcode_07(): void { /*** ret ***/
    this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;
}
private opcode_08(): void { /*** inr a ***/
    this.pszvalue = this.a = (this.a+1) & 255;
}
private opcode_09(): void { /*** dcr b ***/
    this.pszvalue = this.a = (this.b-1) & 255;
}
private opcode_0a(): void { /*** rrc ***/
    this.carry = this.a & 1;this.a = (this.a >> 1) | (this.carry << 7);
}
private opcode_0b(): void { /*** rnz ***/
    if (this.pszvalue != 0) { this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;};
}
private opcode_0c(): void { /*** aci %1 ***/
    this.pszvalue = this.a = this.add(this.fetch(),this.carry);
}
private opcode_0d(): void { /*** rst 08 ***/
    this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = 0x08;
}
private opcode_0e(): void { /*** nop ***/
    ;;
}
private opcode_0f(): void { /*** ret ***/
    this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;
}
private opcode_10(): void { /*** inr a ***/
    this.pszvalue = this.a = (this.a+1) & 255;
}
private opcode_11(): void { /*** dcr b ***/
    this.pszvalue = this.a = (this.b-1) & 255;
}
private opcode_12(): void { /*** ral ***/
    this.t16 = (this.a << 1)|this.carry;this.carry = (this.t16 >> 8) & 1 ;this.a = this.t16 & 0xFF;
}
private opcode_13(): void { /*** rp ***/
    if ((this.pszvalue & 0x80) == 0) { this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;};
}
private opcode_14(): void { /*** sui %1 ***/
    this.pszvalue = this.a = this.sub(this.fetch(),0);
}
private opcode_15(): void { /*** rst 10 ***/
    this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = 0x10;
}
private opcode_16(): void { /*** nop ***/
    ;;
}
private opcode_17(): void { /*** ret ***/
    this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;
}
private opcode_18(): void { /*** inr a ***/
    this.pszvalue = this.a = (this.a+1) & 255;
}
private opcode_19(): void { /*** dcr b ***/
    this.pszvalue = this.a = (this.b-1) & 255;
}
private opcode_1a(): void { /*** rar ***/
    this.t16 = (this.carry << 8)|this.a;this.carry = this.a & 1;this.a = (this.t16 >> 1) & 0xFF;
}
private opcode_1b(): void { /*** rpo ***/
    if (this.parityeven(this.pszvalue) == 0) { this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;};
}
private opcode_1c(): void { /*** sbi %1 ***/
    this.pszvalue = this.a = this.sub(this.fetch(),this.carry);
}
private opcode_1d(): void { /*** rst 18 ***/
    this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = 0x18;
}
private opcode_1e(): void { /*** nop ***/
    ;;
}
private opcode_1f(): void { /*** ret ***/
    this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;
}
private opcode_20(): void { /*** inr a ***/
    this.pszvalue = this.a = (this.a+1) & 255;
}
private opcode_21(): void { /*** dcr b ***/
    this.pszvalue = this.a = (this.b-1) & 255;
}
private opcode_22(): void { /*** nop ***/
    ;;
}
private opcode_23(): void { /*** rc ***/
    if (this.carry != 0) { this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;};
}
private opcode_24(): void { /*** ani %1 ***/
    this.pszvalue = this.a = this.a & this.fetch();this.carry = 0;
}
private opcode_25(): void { /*** rst 20 ***/
    this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = 0x20;
}
private opcode_26(): void { /*** nop ***/
    ;;
}
private opcode_27(): void { /*** ret ***/
    this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;
}
private opcode_28(): void { /*** inr a ***/
    this.pszvalue = this.a = (this.a+1) & 255;
}
private opcode_29(): void { /*** dcr b ***/
    this.pszvalue = this.a = (this.b-1) & 255;
}
private opcode_2a(): void { /*** nop ***/
    ;;
}
private opcode_2b(): void { /*** rz ***/
    if (this.pszvalue == 0) { this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;};
}
private opcode_2c(): void { /*** xri %1 ***/
    this.pszvalue = this.a = this.a ^ this.fetch();this.carry = 0;
}
private opcode_2d(): void { /*** rst 28 ***/
    this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = 0x28;
}
private opcode_2e(): void { /*** nop ***/
    ;;
}
private opcode_2f(): void { /*** ret ***/
    this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;
}
private opcode_30(): void { /*** inr a ***/
    this.pszvalue = this.a = (this.a+1) & 255;
}
private opcode_31(): void { /*** dcr b ***/
    this.pszvalue = this.a = (this.b-1) & 255;
}
private opcode_32(): void { /*** nop ***/
    ;;
}
private opcode_33(): void { /*** rm ***/
    if ((this.pszvalue & 0x80) != 0) { this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;};
}
private opcode_34(): void { /*** ori %1 ***/
    this.pszvalue = this.a = this.a | this.fetch();this.carry = 0;
}
private opcode_35(): void { /*** rst 30 ***/
    this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = 0x30;
}
private opcode_36(): void { /*** nop ***/
    ;;
}
private opcode_37(): void { /*** ret ***/
    this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;
}
private opcode_38(): void { /*** nop ***/
    ;;
}
private opcode_39(): void { /*** nop ***/
    ;;
}
private opcode_3a(): void { /*** nop ***/
    ;;
}
private opcode_3b(): void { /*** rpe ***/
    if (this.parityeven(this.pszvalue) != 0) { this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;};
}
private opcode_3c(): void { /*** cpi %1 ***/
    this.pszvalue = this.sub(this.fetch(),0);
}
private opcode_3d(): void { /*** rst 38 ***/
    this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = 0x38;
}
private opcode_3e(): void { /*** nop ***/
    ;;
}
private opcode_3f(): void { /*** ret ***/
    this.sptr = (this.sptr-1) & 7;this.pc = this.stack[this.sptr];;
}
private opcode_40(): void { /*** jnc %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if (this.carry == 0) { this.pc = this.t16; };
}
private opcode_41(): void { /*** in 00 ***/
    this.a = this.input(0x00);
}
private opcode_42(): void { /*** cnc %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if (this.carry == 0) { this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16; };
}
private opcode_43(): void { /*** in 01 ***/
    this.a = this.input(0x01);
}
private opcode_44(): void { /*** jmp %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.pc = this.t16;
}
private opcode_45(): void { /*** in 02 ***/
    this.a = this.input(0x02);
}
private opcode_46(): void { /*** cal %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16;
}
private opcode_47(): void { /*** in 03 ***/
    this.a = this.input(0x03);
}
private opcode_48(): void { /*** jnz %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if (this.pszvalue != 0) { this.pc = this.t16; };
}
private opcode_49(): void { /*** in 04 ***/
    this.a = this.input(0x04);
}
private opcode_4a(): void { /*** cnz %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if (this.pszvalue != 0) { this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16; };
}
private opcode_4b(): void { /*** in 05 ***/
    this.a = this.input(0x05);
}
private opcode_4c(): void { /*** jmp %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.pc = this.t16;
}
private opcode_4d(): void { /*** in 06 ***/
    this.a = this.input(0x06);
}
private opcode_4e(): void { /*** cal %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16;
}
private opcode_4f(): void { /*** in 07 ***/
    this.a = this.input(0x07);
}
private opcode_50(): void { /*** jp %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if ((this.pszvalue & 0x80) == 0) { this.pc = this.t16; };
}
private opcode_51(): void { /*** out 08 ***/
    this.output(0x08,this.a);
}
private opcode_52(): void { /*** cp %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if ((this.pszvalue & 0x80) == 0) { this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16; };
}
private opcode_53(): void { /*** out 09 ***/
    this.output(0x09,this.a);
}
private opcode_54(): void { /*** jmp %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.pc = this.t16;
}
private opcode_55(): void { /*** out 0a ***/
    this.output(0x0A,this.a);
}
private opcode_56(): void { /*** cal %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16;
}
private opcode_57(): void { /*** out 0b ***/
    this.output(0x0B,this.a);
}
private opcode_58(): void { /*** jpo %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if (this.parityeven(this.pszvalue) == 0) { this.pc = this.t16; };
}
private opcode_59(): void { /*** out 0c ***/
    this.output(0x0C,this.a);
}
private opcode_5a(): void { /*** cpo %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if (this.parityeven(this.pszvalue) == 0) { this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16; };
}
private opcode_5b(): void { /*** out 0d ***/
    this.output(0x0D,this.a);
}
private opcode_5c(): void { /*** jmp %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.pc = this.t16;
}
private opcode_5d(): void { /*** out 0e ***/
    this.output(0x0E,this.a);
}
private opcode_5e(): void { /*** cal %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16;
}
private opcode_5f(): void { /*** out 0f ***/
    this.output(0x0F,this.a);
}
private opcode_60(): void { /*** jc %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if (this.carry != 0) { this.pc = this.t16; };
}
private opcode_61(): void { /*** out 10 ***/
    this.output(0x10,this.a);
}
private opcode_62(): void { /*** cc %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if (this.carry != 0) { this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16; };
}
private opcode_63(): void { /*** out 11 ***/
    this.output(0x11,this.a);
}
private opcode_64(): void { /*** jmp %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.pc = this.t16;
}
private opcode_65(): void { /*** out 12 ***/
    this.output(0x12,this.a);
}
private opcode_66(): void { /*** cal %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16;
}
private opcode_67(): void { /*** out 13 ***/
    this.output(0x13,this.a);
}
private opcode_68(): void { /*** jz %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if (this.pszvalue == 0) { this.pc = this.t16; };
}
private opcode_69(): void { /*** out 14 ***/
    this.output(0x14,this.a);
}
private opcode_6a(): void { /*** cz %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if (this.pszvalue == 0) { this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16; };
}
private opcode_6b(): void { /*** out 15 ***/
    this.output(0x15,this.a);
}
private opcode_6c(): void { /*** jmp %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.pc = this.t16;
}
private opcode_6d(): void { /*** out 16 ***/
    this.output(0x16,this.a);
}
private opcode_6e(): void { /*** cal %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16;
}
private opcode_6f(): void { /*** out 17 ***/
    this.output(0x17,this.a);
}
private opcode_70(): void { /*** jm %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if ((this.pszvalue & 0x80) != 0) { this.pc = this.t16; };
}
private opcode_71(): void { /*** out 18 ***/
    this.output(0x18,this.a);
}
private opcode_72(): void { /*** cm %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if ((this.pszvalue & 0x80) != 0) { this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16; };
}
private opcode_73(): void { /*** out 19 ***/
    this.output(0x19,this.a);
}
private opcode_74(): void { /*** jmp %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.pc = this.t16;
}
private opcode_75(): void { /*** out 1a ***/
    this.output(0x1A,this.a);
}
private opcode_76(): void { /*** cal %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16;
}
private opcode_77(): void { /*** out 1b ***/
    this.output(0x1B,this.a);
}
private opcode_78(): void { /*** jpe %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if (this.parityeven(this.pszvalue) != 0) { this.pc = this.t16; };
}
private opcode_79(): void { /*** out 1c ***/
    this.output(0x1C,this.a);
}
private opcode_7a(): void { /*** cpe %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;if (this.parityeven(this.pszvalue) != 0) { this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16; };
}
private opcode_7b(): void { /*** out 1d ***/
    this.output(0x1D,this.a);
}
private opcode_7c(): void { /*** jmp %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.pc = this.t16;
}
private opcode_7d(): void { /*** out 1e ***/
    this.output(0x1E,this.a);
}
private opcode_7e(): void { /*** cal %2 ***/
    this.t16 = this.fetch();this.t16 = (this.t16 | (this.fetch() << 8)) & 0x3FFF;this.stack[this.sptr] = this.pc;this.sptr = (this.sptr+1) & 7;this.pc = this.t16;
}
private opcode_7f(): void { /*** out 1f ***/
    this.output(0x1F,this.a);
}
private opcode_80(): void { /*** add a ***/
    this.pszvalue = this.a = this.add(this.a,0);
}
private opcode_81(): void { /*** add b ***/
    this.pszvalue = this.a = this.add(this.b,0);
}
private opcode_82(): void { /*** add c ***/
    this.pszvalue = this.a = this.add(this.c,0);
}
private opcode_83(): void { /*** add d ***/
    this.pszvalue = this.a = this.add(this.d,0);
}
private opcode_84(): void { /*** add e ***/
    this.pszvalue = this.a = this.add(this.e,0);
}
private opcode_85(): void { /*** add h ***/
    this.pszvalue = this.a = this.add(this.h,0);
}
private opcode_86(): void { /*** add l ***/
    this.pszvalue = this.a = this.add(this.l,0);
}
private opcode_87(): void { /*** add m ***/
    this.pszvalue = this.a = this.add(this.read((((this.h << 8)|this.l) & 0x3FFF)),0);
}
private opcode_88(): void { /*** adc a ***/
    this.pszvalue = this.a = this.add(this.a,this.carry);
}
private opcode_89(): void { /*** adc b ***/
    this.pszvalue = this.a = this.add(this.b,this.carry);
}
private opcode_8a(): void { /*** adc c ***/
    this.pszvalue = this.a = this.add(this.c,this.cARRY);
}
private opcode_8b(): void { /*** adc d ***/
    this.pszvalue = this.a = this.add(this.d,this.carry);
}
private opcode_8c(): void { /*** adc e ***/
    this.pszvalue = this.a = this.add(this.e,this.carry);
}
private opcode_8d(): void { /*** adc h ***/
    this.pszvalue = this.a = this.add(this.h,this.carry);
}
private opcode_8e(): void { /*** adc l ***/
    this.pszvalue = this.a = this.add(this.l,this.carry);
}
private opcode_8f(): void { /*** adc m ***/
    this.pszvalue = this.a = this.add(this.read((((this.h << 8)|this.l) & 0x3FFF)),this.carry);
}
private opcode_90(): void { /*** sub a ***/
    this.pszvalue = this.a = this.sub(this.a,0);
}
private opcode_91(): void { /*** sub b ***/
    this.pszvalue = this.a = this.sub(this.b,0);
}
private opcode_92(): void { /*** sub c ***/
    this.pszvalue = this.a = this.sub(this.c,0);
}
private opcode_93(): void { /*** sub d ***/
    this.pszvalue = this.a = this.sub(this.d,0);
}
private opcode_94(): void { /*** sub e ***/
    this.pszvalue = this.a = this.sub(this.e,0);
}
private opcode_95(): void { /*** sub h ***/
    this.pszvalue = this.a = this.sub(this.h,0);
}
private opcode_96(): void { /*** sub l ***/
    this.pszvalue = this.a = this.sub(this.l,0);
}
private opcode_97(): void { /*** sub m ***/
    this.pszvalue = this.a = this.sub(this.read((((this.h << 8)|this.l) & 0x3FFF)),0);
}
private opcode_98(): void { /*** sbb a ***/
    this.pszvalue = this.a = this.sub(this.a,this.carry);
}
private opcode_99(): void { /*** sbb b ***/
    this.pszvalue = this.a = this.sub(this.b,this.carry);
}
private opcode_9a(): void { /*** sbb c ***/
    this.pszvalue = this.a = this.sub(this.c,this.cARRY);
}
private opcode_9b(): void { /*** sbb d ***/
    this.pszvalue = this.a = this.sub(this.d,this.carry);
}
private opcode_9c(): void { /*** sbb e ***/
    this.pszvalue = this.a = this.sub(this.e,this.carry);
}
private opcode_9d(): void { /*** sbb h ***/
    this.pszvalue = this.a = this.sub(this.h,this.carry);
}
private opcode_9e(): void { /*** sbb l ***/
    this.pszvalue = this.a = this.sub(this.l,this.carry);
}
private opcode_9f(): void { /*** sbb m ***/
    this.pszvalue = this.a = this.sub(this.read((((this.h << 8)|this.l) & 0x3FFF)),this.carry);
}
private opcode_a0(): void { /*** ana a ***/
    this.pszvalue = this.a = this.a & this.a;this.carry = 0;
}
private opcode_a1(): void { /*** ana b ***/
    this.pszvalue = this.a = this.a & this.b;this.carry = 0;
}
private opcode_a2(): void { /*** ana c ***/
    this.pszvalue = this.a = this.a & this.c;this.cARRY = 0;
}
private opcode_a3(): void { /*** ana d ***/
    this.pszvalue = this.a = this.a & this.d;this.carry = 0;
}
private opcode_a4(): void { /*** ana e ***/
    this.pszvalue = this.a = this.a & this.e;this.carry = 0;
}
private opcode_a5(): void { /*** ana h ***/
    this.pszvalue = this.a = this.a & this.h;this.carry = 0;
}
private opcode_a6(): void { /*** ana l ***/
    this.pszvalue = this.a = this.a & this.l;this.carry = 0;
}
private opcode_a7(): void { /*** ana m ***/
    this.pszvalue = this.a = this.a & this.read((((this.h << 8)|this.l) & 0x3FFF));this.carry = 0;
}
private opcode_a8(): void { /*** xra a ***/
    this.pszvalue = this.a = this.a ^ this.a;this.carry = 0;
}
private opcode_a9(): void { /*** xra b ***/
    this.pszvalue = this.a = this.a ^ this.b;this.carry = 0;
}
private opcode_aa(): void { /*** xra c ***/
    this.pszvalue = this.a = this.a ^ this.c;this.cARRY = 0;
}
private opcode_ab(): void { /*** xra d ***/
    this.pszvalue = this.a = this.a ^ this.d;this.carry = 0;
}
private opcode_ac(): void { /*** xra e ***/
    this.pszvalue = this.a = this.a ^ this.e;this.carry = 0;
}
private opcode_ad(): void { /*** xra h ***/
    this.pszvalue = this.a = this.a ^ this.h;this.carry = 0;
}
private opcode_ae(): void { /*** xra l ***/
    this.pszvalue = this.a = this.a ^ this.l;this.carry = 0;
}
private opcode_af(): void { /*** xra m ***/
    this.pszvalue = this.a = this.a ^ this.read((((this.h << 8)|this.l) & 0x3FFF));this.carry = 0;
}
private opcode_b0(): void { /*** ora a ***/
    this.pszvalue = this.a = this.a | this.a;this.carry = 0;
}
private opcode_b1(): void { /*** ora b ***/
    this.pszvalue = this.a = this.a | this.b;this.carry = 0;
}
private opcode_b2(): void { /*** ora c ***/
    this.pszvalue = this.a = this.a | this.c;this.cARRY = 0;
}
private opcode_b3(): void { /*** ora d ***/
    this.pszvalue = this.a = this.a | this.d;this.carry = 0;
}
private opcode_b4(): void { /*** ora e ***/
    this.pszvalue = this.a = this.a | this.e;this.carry = 0;
}
private opcode_b5(): void { /*** ora h ***/
    this.pszvalue = this.a = this.a | this.h;this.carry = 0;
}
private opcode_b6(): void { /*** ora l ***/
    this.pszvalue = this.a = this.a | this.l;this.carry = 0;
}
private opcode_b7(): void { /*** ora m ***/
    this.pszvalue = this.a = this.a | this.read((((this.h << 8)|this.l) & 0x3FFF));this.carry = 0;
}
private opcode_b8(): void { /*** cmp a ***/
    this.pszvalue = this.sub(this.a,0);
}
private opcode_b9(): void { /*** cmp b ***/
    this.pszvalue = this.sub(this.b,0);
}
private opcode_ba(): void { /*** cmp c ***/
    this.pszvalue = this.sub(this.c,0);
}
private opcode_bb(): void { /*** cmp d ***/
    this.pszvalue = this.sub(this.d,0);
}
private opcode_bc(): void { /*** cmp e ***/
    this.pszvalue = this.sub(this.e,0);
}
private opcode_bd(): void { /*** cmp h ***/
    this.pszvalue = this.sub(this.h,0);
}
private opcode_be(): void { /*** cmp l ***/
    this.pszvalue = this.sub(this.l,0);
}
private opcode_bf(): void { /*** cmp m ***/
    this.pszvalue = this.sub(this.read((((this.h << 8)|this.l) & 0x3FFF)),0);
}
private opcode_c0(): void { /*** mov a,a ***/
    this.a = this.a;
}
private opcode_c1(): void { /*** mov a,b ***/
    this.a = this.b;
}
private opcode_c2(): void { /*** mov a,c ***/
    this.a = this.c;
}
private opcode_c3(): void { /*** mov a,d ***/
    this.a = this.d;
}
private opcode_c4(): void { /*** mov a,e ***/
    this.a = this.e;
}
private opcode_c5(): void { /*** mov a,h ***/
    this.a = this.h;
}
private opcode_c6(): void { /*** mov a,l ***/
    this.a = this.l;
}
private opcode_c7(): void { /*** mov a,m ***/
    this.a = this.read((((this.h << 8)|this.l) & 0x3FFF));
}
private opcode_c8(): void { /*** mov b,a ***/
    this.b = this.a;
}
private opcode_c9(): void { /*** mov b,b ***/
    this.b = this.b;
}
private opcode_ca(): void { /*** mov b,c ***/
    this.b = this.c;
}
private opcode_cb(): void { /*** mov b,d ***/
    this.b = this.d;
}
private opcode_cc(): void { /*** mov b,e ***/
    this.b = this.e;
}
private opcode_cd(): void { /*** mov b,h ***/
    this.b = this.h;
}
private opcode_ce(): void { /*** mov b,l ***/
    this.b = this.l;
}
private opcode_cf(): void { /*** mov b,m ***/
    this.b = this.read((((this.h << 8)|this.l) & 0x3FFF));
}
private opcode_d0(): void { /*** mov c,a ***/
    this.c = this.a;
}
private opcode_d1(): void { /*** mov c,b ***/
    this.c = this.b;
}
private opcode_d2(): void { /*** mov c,c ***/
    this.c = this.c;
}
private opcode_d3(): void { /*** mov c,d ***/
    this.c = this.d;
}
private opcode_d4(): void { /*** mov c,e ***/
    this.c = this.e;
}
private opcode_d5(): void { /*** mov c,h ***/
    this.c = this.h;
}
private opcode_d6(): void { /*** mov c,l ***/
    this.c = this.l;
}
private opcode_d7(): void { /*** mov c,m ***/
    this.c = this.read((((this.h << 8)|this.l) & 0x3FFF));
}
private opcode_d8(): void { /*** mov d,a ***/
    this.d = this.a;
}
private opcode_d9(): void { /*** mov d,b ***/
    this.d = this.b;
}
private opcode_da(): void { /*** mov d,c ***/
    this.d = this.c;
}
private opcode_db(): void { /*** mov d,d ***/
    this.d = this.d;
}
private opcode_dc(): void { /*** mov d,e ***/
    this.d = this.e;
}
private opcode_dd(): void { /*** mov d,h ***/
    this.d = this.h;
}
private opcode_de(): void { /*** mov d,l ***/
    this.d = this.l;
}
private opcode_df(): void { /*** mov d,m ***/
    this.d = this.read((((this.h << 8)|this.l) & 0x3FFF));
}
private opcode_e0(): void { /*** mov e,a ***/
    this.e = this.a;
}
private opcode_e1(): void { /*** mov e,b ***/
    this.e = this.b;
}
private opcode_e2(): void { /*** mov e,c ***/
    this.e = this.c;
}
private opcode_e3(): void { /*** mov e,d ***/
    this.e = this.d;
}
private opcode_e4(): void { /*** mov e,e ***/
    this.e = this.e;
}
private opcode_e5(): void { /*** mov e,h ***/
    this.e = this.h;
}
private opcode_e6(): void { /*** mov e,l ***/
    this.e = this.l;
}
private opcode_e7(): void { /*** mov e,m ***/
    this.e = this.read((((this.h << 8)|this.l) & 0x3FFF));
}
private opcode_e8(): void { /*** mov h,a ***/
    this.h = this.a;
}
private opcode_e9(): void { /*** mov h,b ***/
    this.h = this.b;
}
private opcode_ea(): void { /*** mov h,c ***/
    this.h = this.c;
}
private opcode_eb(): void { /*** mov h,d ***/
    this.h = this.d;
}
private opcode_ec(): void { /*** mov h,e ***/
    this.h = this.e;
}
private opcode_ed(): void { /*** mov h,h ***/
    this.h = this.h;
}
private opcode_ee(): void { /*** mov h,l ***/
    this.h = this.l;
}
private opcode_ef(): void { /*** mov h,m ***/
    this.h = this.read((((this.h << 8)|this.l) & 0x3FFF));
}
private opcode_f0(): void { /*** mov l,a ***/
    this.l = this.a;
}
private opcode_f1(): void { /*** mov l,b ***/
    this.l = this.b;
}
private opcode_f2(): void { /*** mov l,c ***/
    this.l = this.c;
}
private opcode_f3(): void { /*** mov l,d ***/
    this.l = this.d;
}
private opcode_f4(): void { /*** mov l,e ***/
    this.l = this.e;
}
private opcode_f5(): void { /*** mov l,h ***/
    this.l = this.h;
}
private opcode_f6(): void { /*** mov l,l ***/
    this.l = this.l;
}
private opcode_f7(): void { /*** mov l,m ***/
    this.l = this.read((((this.h << 8)|this.l) & 0x3FFF));
}
private opcode_f8(): void { /*** mov m,a ***/
    this.write((((this.h << 8)|this.l) & 0x3FFF),this.a);
}
private opcode_f9(): void { /*** mov m,b ***/
    this.write((((this.h << 8)|this.l) & 0x3FFF),this.b);
}
private opcode_fa(): void { /*** mov m,c ***/
    this.write((((this.h << 8)|this.l) & 0x3FFF),this.c);
}
private opcode_fb(): void { /*** mov m,d ***/
    this.write((((this.h << 8)|this.l) & 0x3FFF),this.d);
}
private opcode_fc(): void { /*** mov m,e ***/
    this.write((((this.h << 8)|this.l) & 0x3FFF),this.e);
}
private opcode_fd(): void { /*** mov m,h ***/
    this.write((((this.h << 8)|this.l) & 0x3FFF),this.h);
}
private opcode_fe(): void { /*** mov m,l ***/
    this.write((((this.h << 8)|this.l) & 0x3FFF),this.l);
}
private opcode_ff(): void { /*** halt ***/
    this.halt = 1;
}
}
