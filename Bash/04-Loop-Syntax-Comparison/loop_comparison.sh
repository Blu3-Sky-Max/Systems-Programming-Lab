#!/bin/bash 
# Author:  blu3 sky
echo "Bash for loop method for nested " 


for i in {1..8}; do 
	for j in {1..5}; do 
		echo -e -n  $(($j*$i))  "\t " 
	done 
	echo 
done

echo "C method using shebang! for nested "
for (( i=1; i<=8; i++)){
 for ((j=1; j<=5; j++)) {
	 printf   "%d\t"  $(($i * $j))
 }
  printf "\n" 
}
