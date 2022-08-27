#!/bin/bash

for test in *.c; do 
	gcc "$test" -I.. -L.. -lft -o test;
	./test
done
