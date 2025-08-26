#######
Quest 1
#######

ssh-keygen
cat .ssh/id_rsa.pub
git clone ssh://git@repos-ssh.21-school.ru
ls
cd T01D01-1
git checkout -b develop
git branch

#######
Quest 2
#######

cd src
ls
bash ai_initial_module.sh
chmod +x ai_initial_module.sh
chmod +x ai_module_2.sh
nano important_data_for_ai_module_2.txt
bash ai_initial_module.sh
git add .
git commit -m ""

#######
Quest 3
####### 

bash ai_door_management_module.sh
cat door_management_fi  
mv door_management_fi door_management_files
mkdir door_configuration
mv *.conf door_configuration
mkdir door_logs
mv *.log door_logs
mkdir door_map
mv door_map_1.1 door_map
nano quest3.sh
git add .
git commit -m ""
