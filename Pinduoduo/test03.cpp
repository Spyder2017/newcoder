#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<int, int> ma;
pair<int, int> solve(int n, int m) {
    ma.clear();
    int now = 0;
    int t, h;
    n = n % m;
    while(true) {
        n = n % m;
        t = n % m;
        if (ma.find(n) == ma.end()) {
            ma[n] = now;
        } else {
            h = now - ma[n];
            return make_pair(ma[n], h);
        }
        //cout << n << " " << m << " " << t << endl;
        if (t == 0) {
            return make_pair(now, 0);
        }
        n = t;
        n *= 10;
        now ++;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    auto ans = solve(n, m);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}