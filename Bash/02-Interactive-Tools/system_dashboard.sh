#!/bin/bash 
# Author: Blu3 Sky :
#===================================================================================menu==========================================================

Delay=5
while [[ "$REPLY" != 0 ]]; do
	clear
 cat << _EOF_
Please Select:



1. Display System Information
2. Display Disk Space 
3. Display Home Space Utilization
0. Quit
_EOF_

read -r -p "Enter Selection[0-3]: " 

 if [[ $REPLY  =~ ^[0-3]$ ]] ; then  
	 if [[ $REPLY  == 1 ]] ; then 
		 echo " Hostname: $HOSTNAME" 
		 uptime 
		 sleep $Delay
	 fi 
	 if [[ $REPLY  == 2 ]] ; then 
		 df -h
		sleep $Delay
	 fi 
 if [[ $REPLY  == 3 ]] ; then 
if [[ "$(id -u)" -eq 0 ]]; then 
 echo " Home Space Utilization(All user) " 
  du -sh /home/*

 else 
	 echo " Home space Utilization ($USER)"
	 du -sh "$HOME" 
	fi 
  sleep $Delay
 fi
else 
       echo "invaild entry">&2
  sleep $Delay
 fi 


done

echo " Program terminated " 
