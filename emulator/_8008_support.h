static void inline add8bit() {
 t16 = a + mbr + carry;
 a = (t16 & 0xFF);
 carry = (t16 >> 8) & 1;
 pszv = a;
}
static void inline sub8bit() {
 t16 = a - mbr - carry;
 pszv = (t16 & 0xFF);
 carry = (t16 >> 8) & 1;
}
static void inline fetch() {
 mar = stack[stix];
 read();
 stack[stix] = (mar + 1) & 0x3FFF;
}
static void inline fetch16() {
 fetch();
 t16 = mbr;
 fetch();
 t16 = (t16 | (mbr << 8)) & 0x3FFF;
}
static void inline push() {
   stix = (stix + 1) & 7 ;
}
static void inline pull() {
   stix = (stix - 1) & 7 ;
}
static void inline branch() {
 stack[stix] = t16;
}
