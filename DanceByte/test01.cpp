#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string A, int n)
{
	int maps[256];
	memset(maps, -1, sizeof(maps));
	int pre = -1, maxLen = 0;

	for (int i = 0; i < n; ++i)
	{
		pre = max(pre, maps[A[i]]);
		maxLen = max(maxLen, i - pre);
		maps[A[i]] = i;
	}
	return maxLen;
}

int main()
{
    string str;
    cin>>str;
    cout<<longestSubstring(str, str.length())<<endl;
    return 0;
}