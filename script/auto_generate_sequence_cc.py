#!/usr/bin/python
import os
import re

src_file = './db/general_sequence.sql'
dest_hh = "../db/Sequence.hh"
dest_cc = "../db/Sequence.cc"
dest_hh_obj = open(dest_hh,"w")
dest_cc_obj = open(dest_cc,"w")


#main function
dest_hh_obj.write("#ifndef __SEQUENCE__\n"
                    "#define __SEQUENCE__\n")
dest_hh_obj.write('#include "SQLInterface.hh"\n\n')
dest_hh_obj.write('class Sequence:public SQLInterface\n')
dest_hh_obj.write('{\n')
dest_hh_obj.write('public:\n')

dest_cc_obj.write('#include "Sequence.hh"\n\n')

num_seq = 0
file_object = open(src_file,'r')
try:
    all_the_text = file_object.readlines()
    for line in all_the_text:
        line=line.strip()
        
        if re.search("CREATE", line) and re.search("SEQUENCE", line):
            num_seq+=1
            seqName = line.split(None,3)[2];
            seqName = seqName.strip()

            funName="get"
            for substr in seqName.split('_'):
                funName+=substr.capitalize()

            dest_hh_obj.write("    long long "+funName+"();\n")

            dest_cc_obj.write("long long Sequence::"+funName+"()\n")
            dest_cc_obj.write("{\n")
            dest_cc_obj.write('    setSQL("select '+seqName+'.nextval from dual");\n')
            dest_cc_obj.write('    executeQurey();\n')
            dest_cc_obj.write('\n')
            dest_cc_obj.write('    return id;\n')
            dest_cc_obj.write("}\n\n")
            print "cout<<seq."+funName+"()<<endl;"
#print funName+" generated."

finally:
    file_object.close()

dest_hh_obj.write('    virtual void doParse();\n')
dest_hh_obj.write("\n")
dest_hh_obj.write("private:\n")
dest_hh_obj.write("    long long id;\n")
dest_hh_obj.write("};\n")
dest_hh_obj.write("#endif\n")
dest_hh_obj.close()

dest_cc_obj.write("void Sequence::doParse()\n")
dest_cc_obj.write("{\n")
dest_cc_obj.write("    id=(double)rset->getNumber(1);\n")
dest_cc_obj.write("}\n")
dest_cc_obj.close()

print "A total of [",num_seq,"] sequences added"
