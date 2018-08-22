#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct point{
	int x;
	int y;
}point;

vector<point> points;
int n;

bool compare(const point &a, const point &b){
	return a.y==b.y ? a.x>b.x : a.y<b.y;
}

void find_max_point(){
	sort(points.begin(), points.end(), compare);
	printf("%d %d\n",points[n-1].x,points[n-1].y);
	int max_x = points[n-1].x;
	for(int i=n-2; i>=0; i--){
		if(max_x < points[i].x){
			printf("%d %d\n",points[i].x,points[i].y);
			max_x = points[i].x;
		}
	}
}

int main(){
	scanf("%d",&n);
	if(n<=0){
		printf("invalid parameter!!\n");
		return 0;
	}
	for(int i=0;i<n;i++){
		point p;
		scanf("%d %d",&p.x,&p.y);
		points.push_back(p);
	}
	find_max_point();
	return 0;
}
