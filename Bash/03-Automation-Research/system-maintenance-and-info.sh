#!/bin/bash



if [ "$EUID" != 0 ] ; then
	echo "Usage: $0  Need the root to fucntion Sir"
        exit  23	
fi
# create the dir 
 mkdir -p /home/user1/backups
 mkdir -p /home/user1/config_backup

funky(){ 

# echo "Backing up the home dir of user1" 
 tar -czf /home/user1/backups/user1_backup.tar.gz /home/user1/  2>/dev/null 

# echo " copy all the .conf from /etc" 

 cp /etc/*.conf /home/user1/config_backup 

 # echo " finding files larger than 10M in /usr  " 
 find /usr -type f -size +10M 

# echo "clean up empty file in /tmp " 
 find /tmp -empty  -delete &> /dev/null 
echo -e "\033[36mSuccessfully Done with System Backing up  Sir \033[0m" 
} 


system_info(){

echo -e "\033[34mHostname info: \033[0m"
 hostname

 echo -e "\033[34mDate:\033[0m"
 date

 echo -e "\033[34mkernel version:\033[0m "

 uname -r

 echo "Os version: "
 cat /etc/redhat-release

 echo -e "\033[34mlist of user above 1000:\033[0m"
 getent passwd | awk -F: '$3 >=1000 {print $1}'


 echo -e "\033[34mNumber of file in /etc:\033[0m "
 find /etc -type f  | wc -l

 echo -e "\033[36mSuccessfully Done with System Information Sir  \033[0m" 

}



echo "============= Summary report Maintenance================" 
#adding color green to it 
echo -e "\033[32mBackup files:\033[0m " 
 ls -l /home/user1/backups/ 
# adding color red to
echo -e "\033[31mThe Copy Conf:\033[0m " 
 ls -l /home/user1/config_backup 

echo -e "\033[33mAll dir/file here are more than 0:\033[0m  " 
 ls -l /tmp  

echo -e "\033[34mFile larger than 10 are:\033[0m " 
 funky 

 echo "---------- System Report Information ---------------------" 
   system_info


