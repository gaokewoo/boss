#!/bin/bash

filename="detail_item_cmsg detail_item_cring detail_item_msg detail_item_voice"
start=2014
end=2015

sysdate=`date +%Y%m%d%H%M`

for f in $filename
do
    echo "Handling $f...."

    begin=$start

    while [[ $begin -le $end ]]
    do
    
        for i in 01 02 03 04 05 06 07 08 09 10 11 12
        do
            c=`cat ${f}.sql|sed "s/$f/$f$begin$i/g"`
            echo $c >> create_detail_item.sql.$sysdate
        done
        
        begin=`expr $begin + 1`

    done
done

