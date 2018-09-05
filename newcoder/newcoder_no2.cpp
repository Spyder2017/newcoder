#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

/*
解题思路：
以第i个元素为最小值分别向两边扩大区间至最大，
算出该元素与区间内所有数的和的乘积f(i)，遍历
所有元素，更新f(i)即可。
*/
vector<int> num;
int n;

void compute_max(){
	int max=0;
	for(int i=0; i<n; i++){
		int j=i;
		int k=i-1;
		int sum=0;
		while(num[i]<=num[j] && j<n)
		{
			sum+=num[j];
			j++;
		}
		while(num[i]<=num[k] && k>=0)
		{
			sum+=num[k];
			k--;
		}
		int temp=sum;
		if (num[i]*temp>max)
			max=num[i]*temp;
	}
	printf("%d\n",max);
}

int main(){
	scanf("%d",&n);
	if(n<=0){
		printf("invalid parameter!!\n");
		return 0;
	}
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		num.push_back(x);
	}
	compute_max();
	return 0;
}