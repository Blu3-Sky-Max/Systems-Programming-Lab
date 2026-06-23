#!/bin/bash



if [ "$EUID" != 0 ] ; then
	echo "Usage: $0 Needs the root to fucntion Sir"
        exit  23	
fi
# create the dir 
sudo mkdir -p /home/user1/backups
sudo mkdir -p /home/user1/config_backup

funky(){ 

# echo "Backing up the home dir of user1" 
 tar -czf /home/user1/backups/user1_backup.tar.gz /home/user1/  2>/dev/null 

# echo " copy all the .conf from /etc" 

sudo cp /etc/*.conf /home/user1/config_backup 

 # echo " finding files larger than 10M in /usr  " 
sudo find /usr -type f -size +10M 

# echo "clean up empty file in /tmp " 
sudo find /tmp -empty  -delete &> /dev/null 
echo -e  "\033[36m Successfully Done Sir \033[0m" 
} 



echo "============= Summary report ================" 
#adding color green to it 
echo -e "\033[32mBackup files:\033[0m " 
sudo ls -l /home/user1/backups/ 
# adding color red to
echo -e "\033[31mThe Copy Conf:\033[0m " 
sudo ls -l /home/user1/config_backup 

echo -e "\033[33mAll dir/file here are more than 0:\033[0m  " 
 ls -l /tmp  

echo -e "\033[34mFile larger than 10 are:\033[0m " 
 funky 

