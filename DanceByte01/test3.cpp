
/*
思路：动态规划，f[i][j]表示 考虑前i张卡片，a与b的个人得分之差为j时能得到的最大团体分。
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <numeric>

using namespace std;

typedef unsigned int ll;

int main()
{
    int N;
    while (cin >> N)
    {
        vector<int> x(N), y(N);
    for (int i = 0; i < N; ++i)
        cin >> x[i] >> y[i];
    int sumx = accumulate(x.begin(), x.end(), 0);
    int sumy = accumulate(y.begin(), y.end(), 0);
//    cout << sumx << endl;

    int INF = -sumy * 4;

    vector<vector<int>> f(2, vector<int>(2 * sumx + 1, INF));
    int pre = 0, cur = 1;
    f[cur][sumx] = 0;
    for (int i = 0; i < x.size(); ++i)
    {
        swap(pre, cur);
        for (int j = 0; j < f[cur].size(); ++j)
            f[cur][j] = f[pre][j];
        for (int j = 0; j < f[0].size(); ++j)
        {
            if (j - x[i] >= 0) f[cur][j - x[i]] = max(f[cur][j - x[i]], f[pre][j] + y[i]);
            if (j + x[i] < f[0].size()) f[cur][j + x[i]] = max(f[cur][j + x[i]], f[pre][j] + y[i]);
        }
    }
    cout << f[cur][sumx] << endl;
    }
}