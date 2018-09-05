#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
/*
题目描述：
世界杯开幕式会在球场C举行，球场C的球迷看台可以容纳M*N个球迷。在
球场售票完成后，现官方想统计此次开幕式一共有多少个球队球迷群体，
最大的球队球迷群体有多少人。
经调研发现，球迷群体在选座时有以下特性：
	1.同球队的球迷群体会选择相邻座位，不同球队的球迷群体会选择不相
	  邻的座位。(注解：相邻包括前后相邻、左右相邻、斜对角相邻。)
	2.给定一个M*N的二维球场，0代表该位置没有坐人，1代表该位置已有
	  球迷，希望输出球队群体个数P，最大的球队群体人数Q。

输入描述：
第一行，2个数字，M以及N，使用英文逗号分割；
接下来M行，每行N个数字，使用英文逗号分割；

输出描述：
一行，2个数字，P以及Q，使用英文逗号分割；
其中，P表示球队群体个数，Q表示最大的球队群体人数。

示例1：
输入：
5,5
1,0,0,1,1
0,1,0,0,1
0,0,0,1,0
1,0,0,0,0
1,0,1,1,0
输出：
4,4


解题思路：球场分块用DFS搜索，寻找联通子图和最大联通子图
*/

using namespace std;
class PointInfo
{
public:
    int x,y;
};
int n,m;
int f[1001][1001];
int dx[8]={-1, 0, 1,-1,1,-1,0,1};
int dy[8]={-1,-1,-1, 0,0, 1,1,1};
int bfs(int x,int y)
{
    queue<PointInfo> q;
    while (!q.empty()) q.pop();
    PointInfo now;
    now.x=x;
    now.y=y;
    q.push(now);
    f[x][y]=0;
    int cnt=1;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (int i=0;i<8;i++)
        {
            x = now.x+dx[i];
            y = now.y+dy[i];
            if (x<0 || y<0 || x>n || y>m) continue;
            if (f[x][y]==0) continue;
            f[x][y]=0;
            PointInfo tmp;
            tmp.x = x;
            tmp.y = y;
            q.push(tmp);
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    scanf("%d,%d",&n,&m);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&f[i][0]);
        for (int j=1;j<m;j++)
            scanf(",%d",&f[i][j]);
    }
    int maxnum = 0;
    int cnt=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (f[i][j]==1)
        {
            int x = bfs(i,j);
            cnt++;
            if (x>maxnum) maxnum=x;
        }
    printf("%d,%d\n",cnt,maxnum);
    return 0;
}