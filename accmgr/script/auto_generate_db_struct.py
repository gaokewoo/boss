#!/usr/bin/python
import os
import re

path = './db/table_column/'

def handleLine(file,line):
    line.strip()
    if (line[0] == "#") or (line[0] == "(") or (line[0]==")" or (line.find("constraint") != -1)):
        return
    first_two_data=line.split(None,2)
    v_name=first_two_data[0].lower()
    v_type= " ".join(re.findall("[a-zA-Z]+", first_two_data[1])) #Extract only chracters from a string
    v_type=v_type.lower()
    print v_name,v_type

def handleFile(file):
    file_object = open(path+file,'r')
    try:
        all_the_text = file_object.readlines()
        for line in all_the_text:
            handleLine(file,line)
    finally:
        file_object.close()

files = os.listdir(path)
numfiles = 0
for f in files:
    print "Start to analyse ",f
    handleFile(f) 
    numfiles +=1
    break
print "A total of [",numfiles,"] files analysed"

