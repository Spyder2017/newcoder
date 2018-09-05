#include <bits/stdc++.h>

using namespace std;
#define ll long long
 
int n, a[1005] = {0,100,1,3,4,9,7,6,8}, Max;
int dp[1005];//dp[i]为前i个数的最大升序子段和
const int inf = 99999;

int main() {
    //freopen("../in.txt", "r", stdin);
    int i = 1, j, temp;
    //while (cin >> a[i++]);

    n = 9;
    memset(dp, 0, sizeof(dp));
    for (i = 1; i < n; i++) {
        temp = -inf;
        for (j = 0; j < i; j++) {
            if (a[j] < a[i])
                temp = max(temp, dp[j]);//如果i前没有小于它的，temp就为0
        }                           //且dp[i]也为它本身
		if(temp == -inf) temp = 0;
        dp[i] = temp + a[i];
		cout << dp[i] << endl;
    }
    temp = -inf;
    for (i = 1; i <= n; i++)
        if (dp[i] > temp)
            temp = dp[i];
    cout << temp << endl;
}