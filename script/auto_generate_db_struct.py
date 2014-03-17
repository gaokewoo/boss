#!/usr/bin/python
import os
import re

path = './db/table_column/'
dest_file = "../db/DBStruct.hh"
dest_file_obj = open(dest_file,"w")

def handleFile(file):
    file_object = open(path+file,'r')
    try:
        dest_file_obj.write("typedef struct {\n")
        all_the_text = file_object.readlines()
        for line in all_the_text:
            line=line.strip()
            #print "My line is:"+line
            if (line == "") or (line[0] == "#") or (line[0] == "(") or (line[0]==")" or (line.find("constraint") != -1)):
                continue

            first_two_data=line.split(None,2)
            #print first_two_data
            v_name=first_two_data[0].lower()
            v_name=v_name.strip('"')

            tmp_type= " ".join(re.findall("[a-zA-Z]+", first_two_data[1])) #Extract only chracters from a string
            tmp_type=tmp_type.lower()
            if (tmp_type == "number"):
                v_type="long"
            else:
                v_type="string"

            dest_file_obj.write("\t"+v_type+"\tm_"+v_name+";\n")
        dest_file_obj.write("} ST_"+file+";\n\n")

    finally:
        file_object.close()

#main function
files = os.listdir(path)
dest_file_obj.write("#ifndef __DBSTRUCT__\n"
                    "#define __DBSTRUCT__\n"
                    "#include <string>\n"
                    "using namespace std;\n\n")

numfiles = 0
for f in files:
    print "Start to analyse ",f
    handleFile(f)

    numfiles +=1

dest_file_obj.write("#endif\n")

print "A total of [",numfiles,"] files analysed"
