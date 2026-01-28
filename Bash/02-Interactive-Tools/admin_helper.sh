#!/bin/bash

# Author: Blu3 Sky  
PS3="Enter your choice [1-5]: "

dang=3
select usman in  \
 "Display System Information" \
 " Display home space" \
 "Display Home specilization" \
 " calandar" \
  " quit"  ; do  

    	case "$REPLY" in 
	 1) echo "system info: $HOSTNAME" 
		uptime 
		;; 
	2) echo "system home space: "
	        df -h 
	       ;;

      	3)  if [[ "$(id -u)" -eq 0 ]]; then 
	       echo "home specilazation (all user)"
	        du -sh /home/*
	else 
		echo " Home utilization  ($user)" 
	            du -sh "$HOME"
       fi 
                ;;
	4) cal 
	     ;;
    	5) echo " you quit "
	     break
	     ;; 
    	*) echo " you enter an  invaild number" >&2
	     

     esac

     sleep $dang 


done

