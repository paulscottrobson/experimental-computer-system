import re,sys

def process(s,opcode,step,macros):

	cont = True
	keys = macros.keys()
	while cont:
		cont = False
		for k in keys:
			if s.find(k) >= 0:
				cont = True
				s = s.replace(k,macros[k])

	s = s.replace("@p","{0:02x}".format(opcode/2%32))
	s = s.replace("@r","abcdehlm"[step % 8])
	s = s.replace("@v","{0:02x}".format(opcode & 0x38))
	s = s.replace("@c","nc,nz,p,po,c,z,m,pe".split(",")[step % 8])
	s = s.replace("@t",["$carry == 0","$pszv != 0","($pszv & 0x80) == 0","$parityeven($pszv) == 0", \
						"$carry != 0","$pszv == 0","($pszv & 0x80) != 0","$parityeven($pszv) != 0"][step % 8])

	return s

def cProcess(s,type,opcode = -1):
	while s.find("$") >= 0:
		p = s.find("$")
		m = re.match("(\$[a-z0-9]+)(.)",s[p:])
		repl = m.group(1)
		if type == 'C':
			s1 = repl[1:].upper() if m.group(2)[0] != '(' else repl[1:].lower()
		else:
			s1 = "this."+repl[1:].lower()
		s = s[:p] + s1 + s[p+len(repl):]
	return s 

mnemonics = [ None ] * 256
code = [ None ] * 256
macros = {}

src = open("8008.def").readlines()
src = [x if x.find("//") < 0 else x[:x.find("//")] for x in src]
src = [x.replace("\t"," ").rstrip() for x in src]
src = [x for x in src if x != ""]

for m in [x for x in src if x[0] == '@']:
	p = m.find(" ")
	macros[m[:p]] = m[p:].strip()

for line in [x for x in src if x[0] != '@']:
	m = re.match("^([0-9A-F\-\,]+)\s+(\d+)\s+\"(.*?)\"\s*(.*)$",line)
	assert m is not None,line+" fails regex check"
	srange = m.group(1)
	srange = srange if len(srange) != 2 else srange+"-"+srange
	srange = srange if len(srange) != 5 else srange+",1"
	oStart = int(srange[:2],16)
	oEnd = int(srange[3:5],16)
	oStep = int(srange[-1])
	oRange = [x for x in range(oStart,oEnd+1,oStep)]
	for opcode in oRange:
		xcode = "$cycles = $cycles + {0};{1};".format(m.group(2),m.group(4))
		mnemonics[opcode] = m.group(3)
		code[opcode] = xcode
		mnemonics[opcode] = process(mnemonics[opcode],opcode,int(opcode/oStep),macros)
		code[opcode] = process(code[opcode],opcode,int(opcode/oStep),macros).replace(";;",";")
		#print(opcode,mnemonics[opcode],code[opcode])



for i in range(0,256):
	if mnemonics[i] is None:
		mnemonics[i] = "db {0:02x}".format(i)
		code[i] = ""


mnemonicAll = ",".join(['"'+x+'"' for x in mnemonics])
open("_8008_mnemonics.h","w").write("{ "+mnemonicAll+ " };\n\n")

h = open("_8008_case.h","w")
for i in range(0,256):
	h.write("case 0x{0:02x}: /*** {1} ***/\n".format(i,mnemonics[i]))
	h.write("    "+cProcess(code[i],'C')+";break;\n")
h.close()

h = open("_8008_opcodes.ts","w")
h.write("class CPU8008_Opcodes extends CPU8008_Base {\n\n")
h.write("public getOpcodeList():Function[] {\n    ")
h.write(",".join("opcode_{0:02x}()".format(n) for n in range(0,256)))
h.write("\n}\n\n")
for i in range(0,256):
	h.write("private opcode_{0:02x}(): void {{ /*** {1} ***/\n".format(i,mnemonics[i]))
	h.write("    "+cProcess(code[i],'J')+";\n}\n")
h.write("}\n")
h.close()

h = open("_8008_ports.h","w")
for i in range(0,8):
	h.write("#ifndef input{0:02x}\n#define input{0:02x}() (0)\n#endif\n".format(i))
for i in range(8,32):
	h.write("#ifndef output{0:02x}\n#define output{0:02x}(d) {{}}\n#endif\n".format(i))
