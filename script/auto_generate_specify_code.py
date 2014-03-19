#!/usr/bin/python
import os
import re
import sys

path="./db/table_column/"
def CC(file_name,flag):
    table_name=file_name
    src_name=""
    for substr in file_name.split('_'):
        src_name+=substr.capitalize()

    class_name=src_name

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

        emptySQL='"DELETE FROM '+table_name+'";'
        selectAllSQL='"SELECT '+sel_column+' FROM '+table_name+'";'

        if flag=="INSERT":
            print 'void '+class_name+'::insertData()'
            print '{'
            print '    type=INSERT;' 

            print '    setSQL('+insSQL+');'
            print '    executeUpdate();'
            print '}\n'

        if flag=="EMPTY":
            print 'void '+class_name+'::emptyData()'
            print '{'
            print '    type=EMPTY;'
            print '    setSQL('+emptySQL+');'
            print '    executeUpdate();'
            print '}\n'

        if flag=="SELECT_ALL":
            print 'vector<ST_'+file_name.upper()+'> '+class_name+'::loadAllData()'
            print '{'
            print '    type=SELECT_ALL;'
            print '    setSQL('+selectAllSQL+');'
            print '    executeQuery();\n'
            print '    return v_data;'
            print '}\n'

            print 'void '+class_name+'::doParse()'
            print '{'
            print       selAllSQL
            print '    v_data.push_back('+file_name.lower()+');'
            print '}\n'

        print 'void '+class_name+'::prepareSQL()'
        print '{'
        print '    if (type == INSERT)'
        print '    {'
        print           prepareSQL
        print '    }'
        print '}\n'

    finally:
        file_object.close()

#main function

print sys.argv[1]," ",sys.argv[2]
print 'enum OP_TYPE {INSERT=0,EMPTY,SELECT_ALL}'
print 'OP_TYPE type'
CC(sys.argv[1],sys.argv[2])
