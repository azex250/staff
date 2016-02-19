#!/usr/bin/env python3

oldfile = open("lalala","w")
oldfile.write("hello word\n")
oldfile.close()

newfile = open("lalala", "r")
for i in newfile:
	print(i, end='')

newfile.close()