#include <bits/stdc++.h>
using namespace std;

int n, m;
string sarr[2005];
set<string> se;
set<char> cse[15];
string gs;
bool flag = false;
string ans;
void dfs(int id) {
    if (id >= m) {
        // find
        if (se.find(gs) != se.end()) {
            return;
        } else {
            ans = gs;
            flag = true;
            return;
        }
 
    }
    auto it = cse[id].begin();
    while(it != cse[id].end()) {
        gs[id] = *it;
        dfs(id + 1);
        if (flag) return;
        ++it;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> sarr[i];
        se.insert(sarr[i]);
        for (int j = 0; j < m; ++j) {
            cse[j].insert(sarr[i][j]);
        }
    }
    gs = "";
    for (int i = 0; i < m; ++i) gs += 'a';
    flag = false;
    dfs(0);
    if (flag) {
        cout << ans << endl;
    } else {
        cout << "-" << endl;
    }
    return 0;
}