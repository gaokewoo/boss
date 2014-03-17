#!/usr/bin/python
import os
import re

path = './db/table_column/'

def checkFileName(file_name):
    special_name = ['CERTIFICATE_TYPE','ACCT_TYPE','PRIVILEGE','STAFF_PRIVILEGE','STAFF','BILLING_REGION','REGION','ADDRESS','BILLING_CYCLE','BILLING_CYCLE_TYPE','SERV_STATE_DESC','OWE_BUSINESS_TYPE']
    if file_name in special_name:
        return 1
    else:
        return 0
    
def HH(file_name,flag):

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

    if flag==1:
      dest_hh_obj.write('    void emptyData();\n')
      dest_hh_obj.write('    vector<ST_'+file_name.upper()+'> loadAllData();\n')

    dest_hh_obj.write('    virtual void prepareSQL();\n')
    if flag==1:
        dest_hh_obj.write('    virtual void doParse();\n\n')
    else:
        dest_hh_obj.write('    virtual void doParse(){};\n\n')
    dest_hh_obj.write('public:\n')
    dest_hh_obj.write('    ST_'+file_name.upper()+' '+file_name.lower()+';\n\n')
    dest_hh_obj.write('private:\n')

    if flag==1:
      dest_hh_obj.write('    int type;\n')
      dest_hh_obj.write('    static string emptySQL;\n')
      dest_hh_obj.write('    static string selectAllSQL;\n')
      dest_hh_obj.write('    vector<ST_'+file_name.upper()+'> v_data;\n')

    dest_hh_obj.write('    static string insSQL;\n')
    dest_hh_obj.write('};\n')
    dest_hh_obj.write('#endif\n')

    dest_hh_obj.close()

def CC(file_name,flag):
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
    sel_column=""
    selAllSQL=""
    file_object = open(path+file_name,'r')
    try:
        all_the_text = file_object.readlines()
        i=0
        index=0
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

            index+=1

            tmp_type= " ".join(re.findall("[a-zA-Z]+", first_two_data[1])) #Extract only chracters from a string
            tmp_type=tmp_type.lower()
            if (tmp_type == "date"):
                value+="SYSDATE,"
                sel_column+="TO_CHAR("+v_name+",'YYYYMMDDHH24MISS'),"
                selAllSQL+="    "+file_name.lower()+".m_"+v_name.lower()+" = rset->getString("+'%d' %index+");\n"
            else:
                sel_column+=v_name+","
                i+=1
                value+=":"+v_name+","
                if tmp_type == "number":
                    prepareSQL+="    stmt->setNumber("+'%d' %i+','+file_name.lower()+".m_"+v_name.lower()+");\n"
                    selAllSQL+="    "+file_name.lower()+".m_"+v_name.lower()+" = (long)rset->getNumber("+'%d' %index+");\n"
                else:
                    prepareSQL+="    stmt->setString("+'%d' %i+','+file_name.lower()+".m_"+v_name.lower()+");\n"
                    selAllSQL+="    "+file_name.lower()+".m_"+v_name.lower()+" = rset->getString("+'%d' %index+");\n"

        column=column.rstrip(',')
        sel_column=sel_column.rstrip(',')
        value=value.rstrip(',')
        insSQL='"INSERT INTO '+table_name+'('+column+')'+'VALUES ('+value+')";'
        dest_cc_obj.write('string '+class_name+'::insSQL='+insSQL+'\n\n')

        if flag==1:
            emptySQL='"DELETE FROM '+table_name+'";'
            dest_cc_obj.write('string '+class_name+'::emptySQL='+emptySQL+'\n\n')
            selectAllSQL='"SELECT '+sel_column+' FROM '+table_name+'";'
            dest_cc_obj.write('string '+class_name+'::selectAllSQL='+selectAllSQL+'\n\n')

        dest_cc_obj.write('void '+class_name+'::insertData()\n')
        dest_cc_obj.write('{\n')

        if flag==1:
           dest_cc_obj.write('    type=0;\n') 

        dest_cc_obj.write('    setSQL(insSQL);\n')
        dest_cc_obj.write('    executeUpdate();\n')
        dest_cc_obj.write('}\n\n')

        if flag==1:
            dest_cc_obj.write('void '+class_name+'::emptyData()\n')
            dest_cc_obj.write('{\n')
            dest_cc_obj.write('    type=1;\n')
            dest_cc_obj.write('    setSQL(emptySQL);\n')
            dest_cc_obj.write('    executeUpdate();\n')
            dest_cc_obj.write('}\n\n')

            dest_cc_obj.write('vector<ST_'+file_name.upper()+'> '+class_name+'::loadAllData()\n')
            dest_cc_obj.write('{\n')
            dest_cc_obj.write('    type=2;\n')
            dest_cc_obj.write('    setSQL(selectAllSQL);\n')
            dest_cc_obj.write('    executeQuery();\n\n')
            dest_cc_obj.write('    return v_data;\n')
            dest_cc_obj.write('}\n\n')

            dest_cc_obj.write('void '+class_name+'::doParse()\n')
            dest_cc_obj.write('{\n')
            dest_cc_obj.write(selAllSQL)
            dest_cc_obj.write('\n    v_data.push_back('+file_name.lower()+');\n')
            dest_cc_obj.write('}\n\n')

        if flag==1:
            dest_cc_obj.write('void '+class_name+'::prepareSQL()\n')
            dest_cc_obj.write('{\n')
            dest_cc_obj.write('    if (type == 0)\n')
            dest_cc_obj.write('    {\n')
            dest_cc_obj.write(prepareSQL)
            dest_cc_obj.write('    }\n')
            dest_cc_obj.write('}\n\n')
        else:
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
    flag = checkFileName(f)
    print flag
    HH(f,flag)
    CC(f,flag)

    numfiles +=1

print "A total of [",numfiles,"] files analysed"
