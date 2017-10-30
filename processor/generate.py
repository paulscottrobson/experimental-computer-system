import re,sys

class Instruction:
	def __init__(self,defn):
		m = re.match("^([A-Fa-f0-9\-\,]+)\s+(\d+)\s+\"(.*?)\"\s+(.*)$",defn)
		assert m is not None,"Bad line "+defn
		range = m.group(1)
		range = range+"-"+range if len(range) == 2 else range
		range = range+",1" if len(range) == 5 else range
		self.first = int(range[:2],16)
		self.last = int(range[3:5],16)
		self.step = int(range[-1],16)
		self.cycles = int(m.group(2))
		self.names = m.group(3).strip()
		self.code = m.group(4).strip()
		#print(defn,range,self.first,self.last,self.step,self.getOpcodes())

	def getOpcodes(self):
		return range(self.first,self.last+self.step,self.step)

	def getMnemonics(self,opcode,newType = True):
		base = self.names.split(":")[1 if newType else 0]
		base = self.process(base,opcode)
		return base.lower()

	def getCode(self,opcode,type = "C"):
		base = self.process(self.code,opcode)
		while base.find("$") >= 0:
			m = re.search("(\$[A-Za-z]+)",base)
			mWord = m.group(1)			
			if type == "C":
				base = base.replace(mWord,mWord[1:].upper())
			elif type == "T":
				base = base.replace(mWord,"this."+mWord[1:].lower())
			else:
				raise Exception()

		return base

	def process(self,s,opc):
		b03 = opc & 7
		b35 = (opc >> 3) & 7
		s = s.replace("@C1","FC,FZ,FS,FP,TC,TZ,TS,TP".split(",")[b35])
		s = s.replace("@C2","NC,NZ,P,PO,C,Z,M,PE".split(",")[b35])
		s = s.replace("@D","ABCDEHLM"[b35])
		s = s.replace("@FETCH16","$T16 = $fetch();$T16 = ($T16 | ($fetch() << 8)) & 0x3FFF")
		s = s.replace("@HL","((($H << 8)|$L) & 0x3FFF)")
		s = s.replace("@IOA","{0:02X}".format((opc >> 1) & 0x1F))
		s = s.replace("@PUSHPC","$STACK[$SPTR] = $PC;$SPTR = ($SPTR+1) & 7")
		s = s.replace("@PULLPC","$SPTR = ($SPTR-1) & 7;$PC = $STACK[$SPTR];")
		s = s.replace("@R1","{0:01X}".format(b35))
		s = s.replace("@R2","{0:02X}".format(opc & 0x38))
		s = s.replace("@R","ABCDEHLM"[b03])

		tests = [ "$CARRY == 0","$PSZVALUE != 0","($PSZVALUE & 0x80) == 0","$parityeven($PSZVALUE) == 0", \
				  "$CARRY != 0","$PSZVALUE == 0","($PSZVALUE & 0x80) != 0","$parityeven($PSZVALUE) != 0"]
		s = s.replace("@T",tests[b35])
		return s

src = open("8008.def").readlines()
src = [x if x.find("//") < 0 else x[:x.find("//")] for x in src]
src = [x.replace("\t"," ").strip() for x in src]
src = [x for x in src if x != ""]

instructions = [ None ] * 256
for l in src:
	instr = Instruction(l)
	for opc in instr.getOpcodes():
		assert instructions[opc] is None,"Duplicate opcode : "+l
		instructions[opc] = instr

for i in range(0,256):
	if instructions[i] is None:
		instructions[i] = Instruction('{0:02x} 4 "nop:nop" ;'.format(i))

oldList = ",".join(['"'+instructions[x].getMnemonics(x,False)+'"' for x in range(0,256)])		
newList = ",".join(['"'+instructions[x].getMnemonics(x,True)+'"' for x in range(0,256)])

open("_8008_oldMnemonics.h","w").write("{ "+oldList+ " };\n\n")
open("_8008_newMnemonics.h","w").write("{ "+newList+ " };\n\n")

h = open("_8008_case.h","w")
for i in range(0,256):
	h.write("case 0x{0:02x}: /*** {1} ***/\n".format(i,instructions[i].getMnemonics(i)))
	h.write("    "+instructions[i].getCode(i,"C")+";break;\n")
h.close()

h = open("_8008_opcodes.ts","w")
h.write("class CPU8008_Opcodes extends CPU8008_Base {\n\n")
h.write("public getOpcodeList():Function[] {\n    ")
h.write(",".join("opcode_{0:02x}()".format(n) for n in range(0,256)))
h.write("\n}\n\n")
for i in range(0,256):
	h.write("private opcode_{0:02x}(): void {{ /*** {1} ***/\n".format(i,instructions[i].getMnemonics(i)))
	h.write("    "+instructions[i].getCode(i,"T")+";\n}\n")
h.write("}\n")
h.close()