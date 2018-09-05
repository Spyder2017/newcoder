#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int A[50000];
    int B[50000];
    for(int i=1;i<n+1;i++){
        int x;
		scanf("%d",&x);
        A[x] = i;
    }
    for(int i=1;i<n+1;i++){
        int x;
		scanf("%d",&x);
        B[x] = i;
    }
    int nn = 0;
    for(int i=1;i<n+1;i++){
        for(int j=i+1;j<n+1;j++){
			printf("%d %d %d %d\n",A[i],A[j],B[i],B[j]);
            if(A[i]<A[j] && B[i]>B[j]){
                nn++;
            }
        }
    }
    printf("%d",nn);
    return 0;
}