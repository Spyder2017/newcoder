#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
 
int a[10]={0,1,2,3,4,5,6,7,8,9};
int pos[10],i,p[10];
set<string> v;
 
void Print(){
    string s="";
    for(i=0;i<10;i++){
        if(p[i]==1)
            s+=a[i]+'0';
//            cout<<a[i];
    }
    v.insert(s);
    //    cout<<s<<endl;
}
 
int main() {
//    freopen("../in.txt", "r", stdin);
    for(i=0;i<10;i++)
        cin>>pos[i];
 
    int add = 0,tmp;
    while (1){
        int flag=0;
        for(i=9;i>=0;i--){
            if(p[i]==0){
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
        //打印
        tmp=add++;
        for(i=9;i>=0;i--){
            p[i]=pos[i];
            if(pos[i]==0){
                p[i]=tmp&1;
                tmp=tmp/2;
            }
        }
        Print();
    }
    set<string>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }
}