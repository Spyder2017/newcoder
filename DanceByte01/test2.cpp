
/*
先排序然后慢慢合并
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define maxnum(x,y) (x>y?x:y)
using namespace std;
class Info
{
public:
    int l,r;
    bool operator <(const Info& d)
    {
        if (l<d.l) return 1;
        if (l>d.l) return 0;

        if (r<d.r) return 1;
        if (r>d.r) return 0;

        return 1;
    }
};
int n;
vector<Info> l;
int main()
{
    scanf("%d\n",&n);
    int x,y;
    while (n>0)
    {
        Info tmp;
        scanf("%d,%d",&tmp.l,&tmp.r);
        l.push_back(tmp);
        char c = getchar();
        if (c=='\n') n--;
    }
    sort(l.begin(),l.end());
    printf("%d",l[0].l);
    int now = l[0].r;
    for (int i=1;i<l.size();i++)
    {
        if (l[i].l-1<=now) now=maxnum(now,l[i].r);
        else
        {
            printf(",%d;%d",now,l[i].l);
            now = l[i].r;
        }
    }
    printf(",%d\n",now);
    return 0;
}