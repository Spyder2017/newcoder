#include<bits/stdc++.h>
using namespace std;

const int MAXN=100003;

int seq[MAXN];
int subseq[MAXN];

int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> seq[i];
    subseq[1]=seq[1];
    int len=1;
    for(int i=2;i<=n;i++)
    {
        if(seq[i]>subseq[len])
            subseq[++len] = seq[i];
        else
        {
            int j = lower_bound(subseq+1,subseq+len+1,seq[i])-subseq;
            subseq[j] = seq[i];
        }
    }
    cout << len << endl;
    return 0;
}