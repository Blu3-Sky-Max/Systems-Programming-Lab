#!/bin/bash
#
#   Author: Blu3-Sky
#   Created:2026/06/05


dang=5 

# giving only root the access to run the script
if [[ $EUID -ne 0 ]]; then
  echo "Run this script as root or with sudo." >&2
        exit 1
fi


for i in  user10 user20 user70 ; do
     # Adding 3  new users  with no login 
	sudo useradd $i -s /sbin/nologin 
     # Adding users password 
	echo $i | sudo passwd --stdin $i 

#  changing the primary content  
        sudo chcon -u system_u -t  public_content_t /home/$i 

# removing user70 from allowing to use at  
#  
  if [ $i == user70 ]; then
   echo $i >> /etc/at.deny 
fi 

       
done 

echo " --> --> User Created Successfully  <-- <--"  

# Adding prompt string for options of tearing down
#
PS3="Do you want to teardown? " 

# using select case for user options 
#
select Teardown in yes no ; do

case $REPLY in 
      YES|yes|Yes|1)

                 for i in  user10 user20 user70 ; do
                 sudo userdel -r $i
                 done 
                 echo "User Deleted Successfully" 
                 break
                ;;  

      NO|no|No|2) 
                    echo "Quiting......." 
                    break
                   ;; 
               *) 
                 echo "Invalid input" >&2


     esac

     sleep $dang


     done 
