#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

stack<int> s1,s2;

int main(){
	//freopen("in.txt", "r", stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s1.push(x);
    }
    int res = 0;
	int killed = -1;
    while(killed!=0){
		killed = 0;
        while(s1.size() != 1){
            int t1 = s1.top();
            s1.pop();
            int t2 = s1.top();
            if(t1 < t2) {
				killed++;
				continue;
			}
            else{
                s2.push(t1);
            }
        }
        s2.push(s1.top());
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
		//cout<<"killed:"<<killed<<endl;
        if(killed!=0) res++;
    }
    cout<<res<<endl;
    return 0;
}