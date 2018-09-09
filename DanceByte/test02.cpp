#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int> >& grid, int i, int j){
    if (i<0 || i>grid.size()-1 || j<0 || j>grid[0].size()-1 || grid[i][j] == 0)
        return;
    grid[i][j] = 0;
    bfs(grid, i - 1, j);
    bfs(grid, i + 1, j);
    bfs(grid, i, j - 1);
    bfs(grid, i, j + 1);
    return;
}

int main(){
    int M;
    cin>>M;
    vector<vector<int> > grid(M, vector<int>(M, 0));
    for(int i=0; i<M; i++)
        for (int j=0; j<M; j++)
            cin>>grid[i][j];

    int num=0;
    for (int i=0; i!=M; i++)
        for (int j=0; j!=M; j++)
            if(grid[i][j] == 1){
                bfs(grid, i, j);
                ++num;
            }
    cout<<num<<endl;
    return 0;
}