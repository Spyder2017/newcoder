import sys
# 二分图最大匹配：葡萄牙算法
def dfs(u, m, nums, vis, match):
	for i in range(m):
		if vis[i]==0 and nums[u][i]==1:
			vis[i] = 1;
			if match[i]==-1 or dfs(match[i], m, nums, vis, match):
				match[i] = u
				return 1
	return 0

if __name__ == "__main__":
	mn = sys.stdin.readline().strip().split(' ')
	n = int(mn[0])
	m = int(mn[1])
	nums = [[-1 for i in range(m)] for j in range(n)]
	for i in range(n):
		line = [int(i) for i in sys.stdin.readline().strip().split(' ')]
		if len(line) > 1:
			for j in line[1:]:
				nums[i][j-1] = 1
	for i in range(m):
		line = [int(i) for i in sys.stdin.readline().strip().split(' ')]
		if len(line) > 1:
			for j in line[1:]:
				nums[j-1][i] = 1
	ans = 0
	while True:
		#print(nums)
		vis = [0 for i in range(n+m)]
		match = [-1 for i in range(n+m)]
		res = 0
		for i in range(n):
			if dfs(i, m, nums, vis, match) == 1:
				res += 1
		#print(vis)
		#print(match)
		#print(res)
		if res == 0:
			break
		elif res > 0:
			res = 0
			for j in range(len(match)):
				if j<n and match[j] != -1:
					nums[j][match[j]] = -1
				elif match[j] != -1:
					nums[match[j]][j] = -1
		ans += 1
	print(ans)

'''
2 3
1 1
2 2 3
0
0
0
3 3
2 1 2
2 1 3
2 2 3
1 1
2 1 3
2 2 3
'''