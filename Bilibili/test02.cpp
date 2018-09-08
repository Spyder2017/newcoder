#include <iostream>
#include <vector>
using namespace std;

int m=0,n=0;
vector<vector<int> > mtr;

vector<int> mtr2list(vector<vector<int> > mtr) {
    vector<int>res;
    int row=mtr.size();
    int col=mtr[0].size();
    if(row==0||col==0)
        return res;

    int circle=((row<col?row:col)-1)/2+1;
    for(int i=0;i<circle;i++){
        for(int j=i;j<col-i;j++)
            res.push_back(mtr[i][j]);
        for(int k=i+1;k<row-i;k++)
            res.push_back(mtr[k][col-1-i]);
        for(int m=col-i-2;(m>=i)&&(row-i-1!=i);m--)
            res.push_back(mtr[row-i-1][m]);
        for(int n=row-i-2;(n>i)&&(col-i-1!=i);n--)
            res.push_back(mtr[n][i]);}
    return res;
}

int main()
{
    while(1){
        cin>>m>>n;
        if(m==-1 && n==-1) break;
    
        for(int i=0;i<m;i++){
            vector<int> lx;
            for (int j=0;j<n;j++){
                int x;
                cin>>x;
                lx.push_back(x);
            }
            mtr.push_back(lx);
        }
        vector<int> plt=mtr2list(mtr);
        int len = m*n;
        for(int i=0;i<len-1;i++){
            cout<<plt[i]<<",";
        }
        cout<<plt[len-1]<<endl;
    }
    return 0;
}