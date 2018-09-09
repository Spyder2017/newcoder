#include<bits/stdc++.h>
using namespace std;

#define MAX (1001)
int T;
int n,m;
int grid[MAX][MAX];
int grid_i[MAX];

int get_i(int x){
    if (grid_i[x]==x) return x;
    return grid_i[x]=get_i(grid_i[x]);
}

int find_set(int n) {
    for(int i=1;i<=n;i++)
        get_i(i);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i-1;j++){
            if(grid[i][j] && grid_i[i]==grid_i[j]) return 0;
            if(!grid[i][j] && grid_i[i]!=grid_i[j]) return 0;
        }
    int p=0;
    for(int i=1;i<=n;i++)
        if (grid_i[i]==i)
            p++;
    if (p<2) p=0;
    return p;
}

void union_s(int x,int y){
    x=get_i(x);
    y=get_i(y);
    if(x != y)
        grid_i[x]=y;
}

int main(){
    int T;
    cin >> T;
    
    while(T--){
        cin >> n >> m;
        memset(grid,0,sizeof(grid));
        for(int i=1;i<=n;i++)
            grid_i[i]=i;
        for(int i=1;i<=m;i++) {
            int a,b;
            cin >> a >> b;
            grid[a][b]=grid[b][a]=1;
        }
        for(int i =1 ;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if (!grid[i][j]) {
                    union_s(i, j);
                }
            }
        }
        if(find_set(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}