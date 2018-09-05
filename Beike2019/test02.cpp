#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct dmn{
	int x;
	int h;
	int nu;
	int index;
}dmn;

vector<dmn> dmns;

bool compare(const dmn &a, const dmn &b){
	return a.x<b.x;
}

bool compare_i(const dmn &a, const dmn &b){
	return a.index<b.index;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		dmn td;
		td.nu = 0;
		td.index = i;
		cin>>td.x>>td.h;
		dmns.push_back(td);
	}
	int num = 0;
	sort(dmns.begin(),dmns.end(),compare);
	for(int i=0;i<n;i++){
		//int tmpx = dmns[i].x+1;
		int tmph = dmns[i].h+dmns[i].x-1;
		for(int j=i;j<n;j++){
			if(tmph>=dmns[j].x){
				num++;
				int tmp = dmns[j].h+dmns[j].x-1;
				if(tmp>tmph) tmph = tmp;
			}else break;
		}
		dmns[i].nu = num;
		num = 0;
	}
	sort(dmns.begin(),dmns.end(),compare_i);
	for(int i=0;i<n;i++){
		cout<<dmns[i].nu;
		if(i!=n-1) cout<<' ';
	}
	cout<<endl;
	return 0;
}