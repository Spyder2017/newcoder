#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    vector<int> view_flower;
    for(int i=0;i<m;i++){
        int flower;
        scanf("%d",&flower);
        view_flower.push_back(flower);
    }
    int q_n;
    scanf("%d",&q_n);
    vector<int> vnf;
    for(int i=0;i<q_n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
		set<int> iset;
		for(int j=l-1;j<r;j++){
			iset.insert(view_flower[j]);
			if(iset.size()==n) break;
		}
        vnf.push_back(iset.size());
		iset.clear();
    }
    for(int i=0;i<vnf.size();i++){
        printf("%d\n",vnf[i]);
    }
    return 0;
}