#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> ps;
	vector<int> visited;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		ps.push_back(x);
		visited.push_back(0);
	}
	int res = 0;
	for(int i=0;i<n;i++){
		if(visited[i] == 1) continue;
		int k = 0;
		int j = i;
		int sum = 0;
		while(k!=1){
			sum += ps[j];
			visited[j] = 1;
			int pj = j;
			if(ps[j]%2==0){
				j = (j+3)%n;
				if(j==i || (pj>i && j-i<3 && j-i>0) || (pj<i && i-pj<3)) k++;
			}else{
				j = (j+2)%n;
				if(j==i || (pj>i && j-i<2 && j-i>0) || (pj<i && i-pj<2)) k++;
			}
		}
		res = res>sum?res:sum;
	}
	cout<<res<<endl;
	return 0;
}