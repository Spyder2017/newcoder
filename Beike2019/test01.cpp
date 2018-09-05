#include <iostream>
#include <math.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int tmp[3003],rep,tempr[3003];
int pr[30] = {1,2,3,5,7,11,13,17,19,23,29,31,37,39,41,43,47,53,59,61,67,71};
double a,logs[30];

void dfs(int p,int v,int max,double c){
    if(c > a) return;
    if(v == 1){
        rep = p;
        a = c;
        for (int i=1;i<p;i++)
            tempr[i] = tmp[i];
        return;
    }

    for(int i=1;i*i<=v && i<=max;i++) {
        if(v%i==0) {
            if(i!=1) {
                tmp[p] = i;
                dfs(p+1,v/i,i,c+logs[p]*(i-1));
            }
            if(v/i<=max && v/i!=i) {
                tmp[p] = v/i;
                dfs(p+1,i,v/i,c+logs[p]*(v/i-1));
            }
        }
    }
}

int main() {
    int n;
	cin>>n;
    for(int i=0;i<16;i++)
		logs[i] = log((double)pr[i]);
    a = INF;
    dfs(1,n,n,0);
    long long M = 1;
    for (long i=1; i<rep; i++)
		for (long j=1; j<tempr[i];j++)
			M *= pr[i];
	cout<<M<<endl;
    return 0;
}