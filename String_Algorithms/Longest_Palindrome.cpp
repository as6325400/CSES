#include <bits/stdc++.h>
#define int long long

using namespace std;

// 找到對於每個位置的迴文半徑
vector<int> manacher(string s) {
    string t = "#";
    for (auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    vector<int> r(n);
    for (int i = 0, j = 0; i < n; i++) {    // i 是中心, j 是最長回文字串中心
        if (2 * j - i >= 0 && j + r[j] > i) {
            r[i] = min(r[2 * j - i], j + r[j] - i);
        }
        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
            r[i] += 1;
        }
        if (i + r[i] > j + r[j]) {
            j = i;
        }
    }
    return r; 
    // # a # b # a #
    // 1 2 1 4 1 2 1
    // # a # b # b # a #
    // 1 2 1 2 5 2 1 2 1
    // 值 -1 代表原回文字串長度
    // (id - val + 1) / 2 可得原字串回文開頭
}
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  auto p = manacher(s);
  int v = -1;
  int idx = -1;
  for(int i = 0; i < p.size(); i++){
    if(p[i] > v){
      v = p[i];
      idx = i;
    }
  }
  int start = (idx - v + 1) / 2;
  for(int i = start; i < start + (v - 1); i++){
    cout << s[i];
  }
  cout << '\n';
}