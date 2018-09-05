#include <bits/stdc++.h>
#include <map>
#include <math.h>
using namespace std;

typedef struct data{
    int clas[2];
}data;

int n;
map<int,data> mp;
int classify[2] = {0};

double cpt_entroy(int m[]){
    int nu = m[0] + m[1];
    double first = 0.0;
    double second = 0.0;
    if(m[0] != 0){
        double tmp = 1.0 * m[0] / nu;
        first = -1 * tmp * log(tmp) / log(2);
    }
    if(m[1] != 0){
        double tmp = 1.0 * m[1] / nu;
        second = -1 * tmp * log(tmp) / log(2);
    }
    double entroy = 1.0 * nu / n * (first + second);
    return entroy;
}

int main() {
    int a, b;
    char indep;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin>>a>>indep>>b;
        classify[b]++;
        if(mp.find(a) == mp.end())
            mp[a].clas[b] = 0;
        mp[a].clas[b] += 1;
    }
    double gain = cpt_entroy(classify);
    map<int, data>::iterator it;
    for(it = mp.begin(); it != mp.end(); ++it)
        gain -= cpt_entroy(it->second.clas);
    int dans = (gain + 0.005) * 100;
    double res = 1.0 * dans / 100;
    printf("%.2f\n",res);
    return 0;
}