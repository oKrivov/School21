#######
Quest 6
####### 

bash ai_door_management_module.sh
ls
cd ai_help
ls
bash keygen.sh
bash unifier.sh
cd key
rm file*
ls
cd ..
bash unifier.sh
nano quest6.sh
git add .
git commit -m ""


#######
Quest 7
#######

cat git_for_human/readme.txt
git checkout -b key-branch
git branch
ls ai_help/main.key 
cd ai_help
cp main.key main-2.key 
git add . 
git commit -m ""
git checkout -b feature/3-key
git branch
cp main.key main-3.key
git add .
git commit -m "feature/3-key branch ..."
git checkout key-branch
git merge feature/3-key
git checkout develop 
git checkout -b release/1.0
git checkout develop
git merge key-branch 
git checkout release/1.0
git merge develop
git add .
git commit -m ""
git push origin release/1.0
git push origin develop
git push origin feature/3-key
git push origin key-branch
