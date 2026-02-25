#!/bin/bash 

# Author: Usman O. Olanrewaju (Blu3 sky) 
# Date: 2026/02/16 
# Title: setup_users.sh 

if [ "$#" -lt 3 ]; then
    echo "Usage: $0 <username1> <username2> <username3>"
    exit 1
fi
user="$@" 
group="scriptgroup" 
dir="documents projects archives" 
share="/shared/teamfiles"
echo "creating group: $group" 
sudo  groupadd $group

for i in $user ; do 
  echo "creating user: $i"  
  echo 
      sudo useradd -m  -d /home/$i  $i ;
	echo "creating subdir for user: $i"
       echo 	
   for j in $dir ; do 
	sudo mkdir -p  /home/$i/$j 
done 
 echo "Adding $i to $group"
 echo 
 sudo  usermod -aG $group $i 
done 
 echo "Making a dir called $share " 
 echo 
 sudo  mkdir -p  $share 
  echo "changing $share group to $group"
 echo
sudo chgrp -R $group  $share 
 echo "changing permission for dir $share" 
sudo chmod -R 2770 $share
 
echo 
# --- Summary Report --------------------------
echo -e "\n--- SCRIPT COMPLETE: SUMMARY REPORT ---"
echo "Group '$group' members:"
getent group $group

echo -e "\nPermissions for $share directory:"

ls -ldn $share

for i in ${user[@]}; do 
echo -e "\nHome directory structure for users: $i"
 sudo ls -l /home/$i 
done 

  
