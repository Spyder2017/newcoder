#include<bits/stdc++.h>
using namespace std;
/*
思路：走完所有节点类似于深度优先搜索，也就是说除了最后一条路径外，别的路径都经历了正着走，再返回
的过程，也就是两遍，设最后一条路径为x，总分支数为n-1，总路径=2*(n-1-x)+x=2*n-2-x，当x最大时
总路径最小，所以转化为求二叉树的深度。
*/
int lst[100005];
int main(){
    int n;
    while(cin>>n){
        memset(lst,0,sizeof(lst));
        for(int i = 0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            lst[b] = lst[a]+1;//当前节点的深度
        }
        int depth = 0;
        for(int i = 1;i<=n;i++)
            depth = lst[i]>depth?lst[i]:depth;//找到最大值
        cout<<2*n-2-depth<<endl;
    }
    return 0;
}
