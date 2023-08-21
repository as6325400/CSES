#include <bits/stdc++.h>
#define int long long

using namespace std;

string manachar(string temp){
  string s = "^";
  for(auto &i:temp){
    s += "#";
    s.push_back(i);
  }
  s += "#$";
  int num = s.size(), R = 0, C = 0;
  vector<int> p(num, 0);
  for(int i = 1; i < num - 1; i++){
    int i_mirror = 2 * C - i;
    if(R > i) p[i] = min(R - i, p[i_mirror]);
    else p[i] = 0;
    while(s[i + 1 + p[i]] == s[i - 1 - p[i]]) p[i]++;
    if (i + p[i] > R) {
        C = i;
        R = i + p[i];
    }
  }
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < num - 1; i++) {
      if (p[i] > maxLen) {
          maxLen = p[i];
          centerIndex = i;
      }
  }
  int start = (centerIndex - maxLen) / 2;
  return temp.substr(start, maxLen);
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  cout << manachar(s) << '\n';
}