!/bin/bash
echo "Введите путь к файлу"
read path

# path="src/files.log"
cd ..

if [ ! -e $path ]
    then 
        echo "Путь к файлу не найден!"
        exit
fi
if [ -z $path]
    then 
        echo "Путь не неуказан!"
        exit
fi

numOfLines=$(cat $path | wc -l )
uniNumOfLines=$(cat $path | uniq  | wc -l)
numOfChangedHash=$(cat $path |  awk '{print $8}' | grep -v 'NULL' | uniq  | wc -l)
echo "$numOfLines $uniNumOfLines $numOfChangedHash" 