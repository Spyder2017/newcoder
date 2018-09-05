#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
 
void string_replace(string &strBig, const string &strsrc, const string &strdst) {
    int pos = 0;
    int srclen = strsrc.size();
    int dstlen = strdst.size();
 
    while ((pos = strBig.find(strsrc, pos)) != string::npos) {
        strBig.replace(pos, srclen, strdst);
        pos += dstlen;
    }
}
 
int main() {
    //freopen("../in.txt", "r", stdin);
    string str,s,p;
    getline(cin,str);
    cin>>s>>p;
    string_replace(str, s, p);
    cout << str << endl;
}