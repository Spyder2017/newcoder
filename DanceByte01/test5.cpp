#include<bits/stdc++.h>
using namespace std;
struct st
{
	int l,r;
}s[100005];

bool cmp(st a, st b){
	if(a.l==b.l){
		return a.r<b.r;
	}
	return a.l<b.l;
}

int n,m;

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d%d",&s[i].l,&s[i].r);
		if(s[i].l>s[i].r)s[i].r+=m;
	}
	sort(s,s+n,cmp);
	int ans = 0;
	int l = 0,r = 0;
	for(int i=0;i<n;i++){
		if(s[i].r>m)continue;
		if(s[i].l>=r){
			ans++;
			l = s[i].l,r = s[i].r;
		}else{
			if(s[i].r<r)r = s[i].r;
		}
	}
	cout<<ans<<endl;
	return 0;
}