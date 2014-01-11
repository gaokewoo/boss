#!/usr/bin/python
import os
import re

path = './db/table_column/'

def HH(file_name):
    src_name=""
    for substr in file_name.split('_'):
        src_name+=substr.capitalize()

    class_name=src_name
    dest_hh = "../db/"+src_name+".hh"
    dest_hh_obj = open(dest_hh,"w")
    
    dest_hh_obj.write('#ifndef __'+src_name.upper()+'__\n')
    dest_hh_obj.write('#define __'+src_name.upper()+'__\n')
    dest_hh_obj.write('#include "DBStruct.hh"\n')
    dest_hh_obj.write('#include "SQLInterface.hh"\n\n')
    dest_hh_obj.write('class '+class_name+':public SQLInterface\n')
    dest_hh_obj.write('{\n')
    dest_hh_obj.write('public:\n')
    dest_hh_obj.write('    void insertData();\n')
    dest_hh_obj.write('    virtual void prepareSQL();\n')
    dest_hh_obj.write('    virtual void doParse(){};\n\n')
    dest_hh_obj.write('public:\n')
    dest_hh_obj.write('    ST_'+file_name.upper()+' '+file_name.lower()+';\n\n')
    dest_hh_obj.write('private:\n')
    dest_hh_obj.write('    static string insSQL;\n')
    dest_hh_obj.write('};\n')
    dest_hh_obj.write('#endif\n')

    dest_hh_obj.close()

def CC(file_name):
    table_name=file_name
    src_name=""
    for substr in file_name.split('_'):
        src_name+=substr.capitalize()

    class_name=src_name
    dest_cc = "../db/"+src_name+".cc"
    dest_cc_obj = open(dest_cc,"w")

    dest_cc_obj.write('#include "'+class_name+'.hh"\n\n')

    column=""
    value=""
    prepareSQL=""
    file_object = open(path+file_name,'r')
    try:
        all_the_text = file_object.readlines()
        i=0;
        for line in all_the_text:
            line=line.strip()
            #print "My line is:"+line
            if (line == "") or (line[0] == "#") or (line[0] == "(") or (line[0]==")" or (line.find("constraint") != -1)):
                continue

            first_two_data=line.split(None,2)
            #print first_two_data
            v_name=first_two_data[0].upper()
            v_name=v_name.strip('"')

            column+=v_name+","

            tmp_type= " ".join(re.findall("[a-zA-Z]+", first_two_data[1])) #Extract only chracters from a string
            tmp_type=tmp_type.lower()
            if (tmp_type == "date"):
                value+="SYSDATE,"
            else:
                i+=1
                value+=":"+v_name+","
                if tmp_type == "number":
                    prepareSQL+="    stmt->setNumber("+'%d' %i+','+file_name.lower()+".m_"+v_name.lower()+");\n"
                else:
                    prepareSQL+="    stmt->setString("+'%d' %i+','+file_name.lower()+".m_"+v_name.lower()+");\n"

        column=column.rstrip(',')
        value=value.rstrip(',')
        insSQL='"INSERT INTO '+table_name+'('+column+')'+'VALUES ('+value+')";'
        dest_cc_obj.write('string '+class_name+'::insSQL='+insSQL+'\n\n')

        dest_cc_obj.write('void '+class_name+'::insertData()\n')
        dest_cc_obj.write('{\n')
        dest_cc_obj.write('    setSQL(insSQL);\n')
        dest_cc_obj.write('    executeUpdate();\n')
        dest_cc_obj.write('}\n\n')

        dest_cc_obj.write('void '+class_name+'::prepareSQL()\n')
        dest_cc_obj.write('{\n')
        dest_cc_obj.write(prepareSQL)
        dest_cc_obj.write('}\n\n')

    finally:
        file_object.close()
        dest_cc_obj.close()

#main function
files = os.listdir(path)

numfiles = 0
for f in files:
    print "Start to analyse ",f
    HH(f)
    CC(f)

    numfiles +=1

print "A total of [",numfiles,"] files analysed"
