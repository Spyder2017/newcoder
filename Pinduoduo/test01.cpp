#include <bits/stdc++.h>
using namespace std;

long long int hp, n, b;
int ans = 0;
int main() {
    std::ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> hp >> n >> b;
    ans = 0;
    if (2*n > b) {
        long long int t = hp / (2*n);
        ans += t*2;
        t = hp % (2*n);
        while(t > 0) {
            t -= n;
            ans ++;
        }
    } else {
        long long int t = hp / b;
        ans += t*2;
        t = hp % b;
        int c = 0;
        while(t > 0) {
            t -= n;
            c ++;
        }
        ans = ans + min(c, 2);
    }
    cout << ans << endl;
    return 0;
}