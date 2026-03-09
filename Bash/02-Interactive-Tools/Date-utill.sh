#!/bin/bash 

# Author:Usman O. Olanrewaju (Blu3 Sky) 
# Date: 2026/02/06
# modify: 2026/03/09 
 # Description: A menu to check and manage system time and date settings.

PS3="Choose from the options above [1-5]:  "

select choice in "Check Time-Zone"  "Change location" "Check Date" "Check Uptime" "Exit" ; do 
	case "$REPLY" in 

		1)  
		      timedatectl | grep Time*
	              ;; 
	        2)
			read -r -p "Enter a city/region to search for (e.g, London, Lagos, Istnabul, New_York): " search_term
			 echo "--- Matching Time-Zones ---"
			 timedatectl list-timezones | grep -i "$search_term"
			 echo "------------------------" 
			 read -r -p "Enter the full Time-Zone to set from the list above: " selected_timezone
			 if timedatectl list-timezones | grep -q "${selected_timezone}$"; then
				 echo "Setting timezone to $selected_timezone"  
				 sudo timedatectl set-timezone "$selected_timezone"
				 if [ $? -eq 0 ]; then
                    			echo "-> -> Time-Zone updated successfully! <- <-"
               			 else
                    			echo "-> -> Failed to set Time-Zone. Please check for errors. <- <-" 
			 fi
		 else
			 echo "Error: '$selected_timezone' is not a valid time zone."
			 fi
			 ;;

	       3)  
		       echo -n "The date is " 
		       date 
		       ;;
	       4) 
		       echo -n "The computer has been " 
		       uptime -p 
		       ;;
	       5) 
		       echo "-> ->Exiting now <- <- " 
		      break 
		      ;;
	       *)  
		       echo "Invalid input" 
		       ;; 
       esac  
		       

done 
