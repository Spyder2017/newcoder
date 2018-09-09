#include<bits/stdc++.h>
using namespace std;

int n,means;
int sc[10003];

void swap(int i,int j){int t; t=sc[i]; sc[i]=sc[j]; sc[j]=t;}

void shift_down(int arr[], int i, int n){
    int j = i * 2 + 1;//子节点 
    while(j<n){
        if(j+1<n && arr[j] > arr[j+1]) j++; //子节点中找较小的
        if(arr[i] < arr[j]) break;
        swap(i,j);
        i = j;
        j = i * 2 + 1;
    }
}

void build_heap(int arr[], int n)//建堆
{
    for(int i=n/2-1;i>=0;i--)//((n-1)*2)+1 =n/2-1
        shift_down(arr,i,n);
}

int main(){
	//freopen("in.txt", "r", stdin);
	cin>>n>>means;
	int sum = 0;
	for(int i=0;i<n;i++){
		cin>>sc[i];
		sum += sc[i];
	}
	double cur_means = 1.0 * sum / n;
	build_heap(sc,n);
	int num = 0;
    for(int i=n-1;i>=0;i--)
    {
		//cout<<sc[0]<<','<<cur_means<<','<<means<<endl;
		if(cur_means >= means) break;
		cur_means = cur_means + 1.0 * (100 - sc[0]) / n;
		num++;
        swap(i, 0);
        shift_down(sc, 0, i);
    }
	cout<<num<<endl;
	return 0;
}