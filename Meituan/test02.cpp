#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int array[300003];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    queue<int> test;
    int max = 0;
    int q_len = 0;
    int zeronum = 0;
    for(int i=0;i<n;i++){
        if(array[i]==0){
            zeronum++;
        }
        test.push(array[i]);
        q_len++;
        if(zeronum==k+1){
            int tm = q_len-1;
            max = max>tm?max:tm;
            int tmp=1;
            while(tmp!=0){
                tmp = test.front();
                test.pop();
                q_len--;
            }
            zeronum--;
        }
    }
    max = max>q_len?max:q_len;
    cout<<max<<endl;
}