#!/bin/bash 

# Blu3 Sky
read -r -n 2 -p "Enter just two character:  " u;
printf "\n" # or just put "echo or echo "" " both will give you space or printf "\n"   

case $u  in 
	 [[:upper:]][[:upper:]])  echo "it an upper letter " 
		;;
	[[:lower:]][[:lower:]]) echo "it a lower letter  "
		;;
	[[:digit:]][[:digit:]]) echo "it a digit number dawg "
		;;
	*) echo "it none of the above " 
		;;
esac 

