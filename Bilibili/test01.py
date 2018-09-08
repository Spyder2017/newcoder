#!/bin/python
# -*- coding: utf8 -*-
import sys
import os
import re

line = sys.stdin.readline().strip().split(' ');
minlen = 0;

def compareVersionNumber():
	res = 0;
	version1 = line[0].split('.')
	version2 = line[1].split('.')
	l1 = len(version1)
	l2 = len(version2)
	if(l1 < l2):
		minlen = l1
	else:
		minlen = l2
	for i in range(minlen):
		if(int(version1[i]) == int(version2[i])):
			continue;
		elif(int(version1[i]) > int(version2[i])):
			res = 1
			break;
		elif(int(version1[i]) < int(version2[i])) :
			res = -1
			break;
	return res

print(compareVersionNumber())