#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int m = s.size();
        int ctty = 0;
        for(int i=0;i<m;i++){
            ctty++;
            if(ctty<4 && s[i]+1 != s[i+1]) ctty = 0;
            if(ctty>=4 && s[i]+1 != s[i+1]){
                string s1;
                s1 = s1 + s[i-ctty+1] + '-' + s[i];
                s.replace(i-ctty+1, ctty, s1);
                i = i-ctty+2;
                m = m-ctty+3;
                ctty = 0;
				//cout<<i<<','<<m<<endl;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}