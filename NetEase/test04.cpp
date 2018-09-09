作者：好好学习秋招秋招！
链接：https://www.nowcoder.com/discuss/105805
来源：牛客网

#include <iostream>
using namespace std;
 
struct node {
  int x;
  int y;
}num[1000];
 
int main()
{
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cin >> num[i].x >> num[i].y;
    }
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        if (num[i].y == num[j].x) {
          num[j].x = num[i].x;
          cnt++;
          break;
        }
        if (num[i].x == num[j].y) {
          num[j].y = num[i].y;
          cnt++;
          break;
        }
      }   
    }
    if (cnt < n - 1)cout << "no" << endl;
    else cout << "yes" << endl;
  }
  system("pause");
  return 0;
}