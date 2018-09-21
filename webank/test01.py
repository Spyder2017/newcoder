import sys

if __name__ == "__main__":
	n = int(sys.stdin.readline().strip())
	for i in range(n):
		line = sys.stdin.readline().strip()
		if len(line) <= 10:
			print(line)
		else:
			print(line[0] + str(len(line)-2) + line[-1])