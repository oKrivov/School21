#!/bin/bash

echo "Укажите путь до файла"
read path
cd ..
if [ -e $path ]
    then
        echo "Укажите что менять"
        read str1
        echo "Укажите на что менять"
        read str2
        
    else
        echo "Файл не найден!"
        exit
    fi

sed -i '' "s|$str1|$str2|g" $path

fSize=$(stat -f%z $path)
fSha=$(shasum -a 256 $path | awk '{print $1}')
fDate=$(date +"%Y-%m-%d %H:%M")
echo "$path - $fSize - $fDate - $fSha - sha256"  >> src/files.log
