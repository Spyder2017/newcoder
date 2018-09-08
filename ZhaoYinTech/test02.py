# coding=utf-8
import sys

if __name__ == '__main__':
	line1 = sys.stdin.readline().strip()
	line2 = sys.stdin.readline().strip()
	visited = [0 for i in line1]
	
	num = 0
	for s in line2:
		for i,l in enumerate(line1):
			if(s==l and visited[i]==0):
				num = num + 1
	if(num==len(line1)-1):
		print(str(1))
	else:
		print(str(0))