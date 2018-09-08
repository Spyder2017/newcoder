#include<iostream>
#include<vector>
using namespace std;

int n;
char ch;
vector< vector<int> > graph;
int count=0;

int minPathSum(vector<vector<int> >& grid)
{
    if (grid.empty())
        return 0;

    int rows = grid.size();
    int cols = grid[0].size();

    vector<int> pre(cols, grid[0][0]);
    vector<int> cur(cols);
    for (int i = 1; i < cols; ++i)
    {
        pre[i] = pre[i - 1] + grid[0][i];
    }
    for (int i = 1; i < rows; ++i)
    {
        cur[0] = grid[i][0] + pre[0];
        for (int j = 1; j < cols; ++j)
        {
            cur[j] = min(cur[j - 1], pre[j]) + grid[i][j];
        }
        swap(cur, pre);
    }
    return pre[cols - 1];
}
int main(){    
    int n;
    //freopen("in.txt", "r", stdin);
    cin >> n;
    vector< vector<int> >::iterator it;
    for(int i=0;i<n;i++){
        vector<int> lx;
        for(int j=0;j<n;j++){
            int x;
            if(j!=n-1) cin>>x>>ch;
            else cin>>x;
            lx.push_back(x);
        }
        graph.push_back(lx);
    }
    cout<<minPathSum(graph)<<endl;
 }