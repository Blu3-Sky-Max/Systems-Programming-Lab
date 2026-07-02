#!/bin/bash

# Authors: Usman Opeyemi Olanrewaju 
# Date: 2026/07/1 
#
# Purpose: Delete non-primary users (UID >= 1001) 

if [ $EUID != 0 ] ; then
	echo -e  "\033[31mUsage: $0 need the Sudo \033[0m" 
            exit 25
fi

# store the users > 1001 
getent passwd | awk -F: '$3 >= 1001 { print $1}' > /home/blu3sky/delete_user.log

delete_user=$(cat /home/blu3sky/delete_user.log)



for i in $delete_user ; do 
  sudo userdel -r $i  
done
# UNSET VARIABLE AFTER USE
unset delete_user 
