#include<bits/stdc++.h>
using namespace std;

typedef struct point{
    int x;
    int y;
}p;

int main(){
    int m;
    int n;
    cin>>n>>m;
    if(n <= 0) return 0;
    if(n == 1){
        cout<<1<<endl;
        return 0;
    }
    map<int, set<int> > persons;
    vector<p> ps(m);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ps[i].x = a;
        ps[i].y = b;
        persons[a].insert(a);
        persons[b].insert(b);
        persons[b].insert(persons[a].begin(),persons[a].end());
    }
    for(int i=0;i<m;i++)
        persons[ps[i].y].insert(persons[ps[i].x].begin(),persons[ps[i].x].end());
    int res = 0;
    map<int, set<int> >::iterator it;
    it = persons.begin();
    while(it != persons.end()) {
        if(it->second.size() == n)
            res++;
        it++;
    }
    cout<<res<<endl;
    return 0;
}