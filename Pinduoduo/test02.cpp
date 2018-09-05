#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[20][20];
int main() {
    std::ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", &mat[i]);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = n-1; j >= 0; --j) {
            if (mat[j][i] == 'x') continue;
            if (mat[j][i] == '.') continue;
 
            int now = j;
            int k = j + 1;
            while(k < n) {
                if (mat[k][i] == 'x') break;
                if (mat[k][i] == 'o') break;
                swap(mat[k][i], mat[now][i]);
                now ++;
                k ++;
            }
            if (k == n) {
                mat[now][i] = '.';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s\n", mat[i]);
    }
 
    return 0;
}