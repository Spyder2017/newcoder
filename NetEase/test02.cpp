作者：好好学习秋招秋招！
链接：https://www.nowcoder.com/discuss/105805
来源：牛客网

#include <iostream>
#include <string>
using namespace std;
int char_to_num(char x) {
  if ((x >= '0') && (x <= '9'))
    return x - '0';
  else return x - 'A' + 10;
}
int main()
{
  int n;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    string str;
    cin >> str;
    int len = str.length();
    int first, second;
    for (int i = 1; i < len; i++) {
      first = 0;
      second = 0;
      for (int j = 0; j < i; j++) {
        first *= x;
        first += char_to_num(str[j]);
      }
      for (int j = i; j < len; j++) {
        second *= y;
        second += char_to_num(str[j]);
      }
      if (first == second)
        cout << first << endl;
    }
  }
  system("pause");
  return 0;
}
