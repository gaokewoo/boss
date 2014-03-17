#!/bin/bash

for file in `ls *.thrift`
do
    echo "--------Handle $file---------"
    thrift --gen cpp $file
done

