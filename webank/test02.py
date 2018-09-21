import sys
from math import sqrt,pow

def is_prime(x):
	tmp = int(sqrt(x))
	for i in range(2, tmp+1):
		if x%i == 0:
			return False;
	return True;

if __name__ == "__main__":
	n = int(sys.stdin.readline().strip())
	res = 0
	flag = [0] * (n + 1)
	for i in range(2, n+1):
		if flag[i] == 1:
			continue
		if is_prime(i) == True:
			flag[i] = 1
			res += 1
			base = i
			while base * i <= n:
				base = base * i
				flag[base] = 1
				res += 1
	print(res)