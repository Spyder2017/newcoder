#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
 
int main() {
    //freopen("../in.txt", "r", stdin);
    ll t,x,k,ans,i,j,a,lenX,lenK,lenA;
    int posX[160],posK[160],posA[160];
    cin>>t;
    while (t--){
        memset(posX,0, sizeof(posX));
        cin>>x>>k;
        i=0,ans=0;
        while (x>0){
            posX[i++]=x&1;
            x=x>>1;
        }
        lenX=i;
 
        i=0;
        while (k>0){
            posK[i++]=k&1;
            k=k>>1;
        }
        lenK=i;
 
        for(i=0,j=0,a=0;j<lenK;i++){
            if(posX[i]==0)
                posA[a++]=posK[j++];
            else
                posA[a++]=0;
        }
        lenA=a;
        for(i=lenA-1;i>=0;i--){
            ans=ans<<1;
            ans=ans|posA[i];
        }
        cout<<ans<<endl;
    }
}