#include<bits/stdc++.h>
using namespace std;

int solve(string S, string T) {
    int res = 0;
    int m = S.size(),n = T.size();
    set<string> dpl;

    for(int i=0;i<m-n+1;i++){
        int k = dpl.size();
        dpl.insert(S.substr(i, n));
        if(k == dpl.size()) continue;
        map<char, char> mps;
        map<char, char> mpt;
        bool coc = true;
        mps[T[0]] = S[i];
        mpt[S[i]] = T[0];
        for(int j=1; j<n; j++){
            if(mps[T[j]] || mpt[S[i+j]]){
                if(mps[T[j]] != S[i+j] || mpt[S[i+j]] != T[j]){
                    coc = false;
                    break;
                }
            }else{
                mps[T[j]] = S[i+j];
                mpt[S[i+j]] = T[j];
            }
        }
        if(coc) res++;
    }
    return res;
}


int main() {
    int res = 0;

    string _S, _T;
    cin >> _S >> _T;
    
    res = solve(_S, _T);
    cout << res << endl;
    return 0;
}
