#!/bin/bash 

# Author: Blu3 Sky 
foo=10 


funky(){
	local foo
	foo=30
	echo "funky: foo=$foo"
	}
funky1(){
	local foo
	foo=1
	echo "funky1:foo=$foo"
	}

	echo "gobal: foo=$foo"
	funky
	echo "gobal: foo=$foo"
	funky1
	echo "gobal: foo=$foo"
