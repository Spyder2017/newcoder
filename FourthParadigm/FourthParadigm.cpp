#include<bits/stdc++.h>
using namespace std;

bool rec_traverse(vector<int>& array, int k, int subset_sum, int st, int cur_sum, vector<int>& accessed){
    if(k == 1) return true;
    int len = array.size();
    if(cur_sum == subset_sum) return rec_traverse(array, k-1, subset_sum, 0, 0, accessed);
    for(int i=st; i<len; i++){
        if(accessed[i]) continue;
        accessed[i] = true;
        if(rec_traverse(array, k, subset_sum, i+1, cur_sum+array[i], accessed)) return true;
        accessed[i] = false;
    }
    return false;
}

bool would_k_split(vector<int>& array, int k){
    int sum = accumulate(array.begin(), array.end(), 0);
    if (sum % k != 0) return false;
    vector<int> accessed(array.size(), 0);
    return rec_traverse(array, k, sum/k, 0, 0, accessed);
}

int main(){
    char ch;
    int k;
    cin>>ch;
    vector<int> array;
    while(ch!=']'){
        int x;
        cin>>x>>ch;
        array.push_back(x);
    }
    cin>>ch>>k;
    if(would_k_split(array,k))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    return 0;
}