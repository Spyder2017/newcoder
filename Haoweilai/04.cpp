#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	int score[100];
	cin>>n>>m;
	int sum = 0;
	for(int i=0;i<n;i++){
		cin>>score[i];
		sum += score[i];
	}
	float e = float(sum)/(float(n)-float(m));
	printf("%.2f",e);
	return 0;
}