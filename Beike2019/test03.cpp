#include<iostream>
#include<map>
#include<vector>
using namespace std;

int Mtr[3003][3003];
int visited[3003] = {0};
int num=0,m,n;

void DFS(int start)
{
    visited[start] = 1;
    for (int i=1; i<=m; i++){
        if(!visited[i] && Mtr[start][i] == 1)
            DFS(i);
    }
}

int main(){
    cin>>m>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        Mtr[x][y] = 1;
    }
	for(int i=1;i<=m;i++){
		if(!visited[i]){
			DFS(i);
			num++;
		}
	}
    cout<<num-1<<endl;
    return 0;
}