作者：好好学习秋招秋招！
链接：https://www.nowcoder.com/discuss/105805
来源：牛客网

#include <iostream> 
#include <vector> 
#include <string> 
#include <set> 
using namespace std; 
int max(int a,int b){ 
  return a>b?a:b; 
}; 
int min(int a,int b){ 
  return a<b?a:b; 
}; 
int main(){ 
  int T; 
  while(cin>>T){
    vector<int>result_v; 
    while(T) { 
      int N,M,L,S,temp,result=0; 
      cin>>N>>M>>L>>S; 
      string temps; 
      vector<pair<int,int>> timu = vector<pair<int,int>>(N); 
      vector<vector<string>> shuxin = vector<vector<string>>(N); 
      for(int i =0;i<N;i++){ 
        cin>>temp; 
        timu[i].first=temp; 
        cin>>temp; 
        timu[i].second=temp; 
        for(int j=0;j<temp;j++){ 
          cin>>temps; 
          shuxin[i].push_back(temps); 
        } 
      } 
      set<string>settemp; 
      int sum=0,Min,Max; 
      result=0; 
      for(int i = 0; i <N*N; ++i){ 
        bool flag=true; settemp.clear(); 
        sum=0,Min=L,Max=0; 
        int tempi=i; int count=0; 
        for (int j =0;j<N;j++){ 
          int index; index=tempi%2; 
          tempi/=2; 
          if(index) count++; 
        } 
        if(count!=M) 
          continue; 
        tempi=i; 
        for (int j =0;j<N;j++) { 
          int qianyigesize=settemp.size(); 
          int houyigesize; 
          int index; 
          index=tempi%2; 
          tempi/=2; 
          if (index){ 
            Max=max(Max,timu[j].first); 
            Min=min(Min,timu[j].first); 
            for (int k = 0; k < shuxin[j].size(); k++) { 
              settemp.insert(shuxin[j][k]); 
            } 
            houyigesize=settemp.size(); 
            if(qianyigesize+shuxin[j].size()!=houyigesize){ 
              flag= false; break; 
            } 
            sum+=timu[j].first; 
            if (sum>L) { 
              flag= false; 
              break; 
            } 
          } 
        } 
        if(flag){ 
          if(Max-Min>=S) { 
            result++;
          } 
        } 
      } 
      result_v.push_back(result); 
      T--; 
    } 
    for(int i:result_v) { 
      cout<<i<<endl; 
    } 
  } 
  return 0; 
}