#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    if(n<=0){
        printf("invalid parameter!!");
        return 0;
    }
    int maxx = 0;
    int maxy = 0;
    int minx = 1e9;
    int miny = 1e9;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        
        if(x > maxx) maxx = x;
        if(y > maxy) maxy = y;
        if(minx > x) minx = x;
        if(miny > y) miny = y;
    }
    int xx = maxx - minx;
    int yy = maxy - miny;
    long max = xx>yy?xx:yy;
    printf("%ld",max*max);
    return 0;
}