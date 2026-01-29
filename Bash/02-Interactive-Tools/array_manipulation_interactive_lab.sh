#!/bin/bash

# Blu3 Sky
read -r   -p "Enter your array 5-10 numbers separated by spaces: " -a arr  
Delay=5

echo "Array numbers are: "  ${arr[@]};  

echo   "5th position number: "  ${arr[5]} 

read -r -n 2  -p "Enter the number you want for the position 5: " p
arr[5]=$p; echo

echo "using Bash "for loop"  to print our new array"
for i in ${arr[*]}; do 
       echo -n  $i "  "  
done        
 echo
echo  "5th position number now: "  ${arr[5]} 
read  -p "Enter the numbers you want to add to the array separated by spaces: " -a usman
arr+=(${usman[@]}) 
echo "using C "for loop" to print our new array" 
for (( i=0; i<${#arr[*]} ; i++)){ 
	 echo -n   ${arr[i]} " " 
} 
echo 
echo  "5th position  number now: "  ${arr[5]} 
array=${arr[*]:4:2}
echo "slicing array from the front(4) and picking 2  next two  numbers: "  ${array[*]} 


array1=${arr[*]:    -5:3}
echo 
echo "slicing array from the back(5) and picking 3 numbers towards ending: "  ${array1[*]} ; echo 
PS3="Do you want to Reset Yes or No?" 
select usman in yes no; do 
	case $REPLY in	
		1|yes|Yes|YES)	
			unset arr     
			echo "we reseting our array now  we have:" ${arr[*]} 
			break 
			;; 
		2|no|NO|No)  
			echo "we still have our array: " ${arr[@]} 
			break 
			;;
		*)  
			echo "invaild input pal -> ->  -> -> -> " 
			sleep $Delay
	esac
	echo 
done 



		

echo "-> -> -> Blu3 Sky <- <- <- " 
