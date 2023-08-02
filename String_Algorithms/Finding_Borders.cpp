#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> build(string &s){
  int length = s.size(), j = 0;
  vector<int> next = {0, 0};
  for(int i = 1; i < length; i++){
    while(j > 0 and s[i] != s[j]) j = next[j];
    if(s[i] == s[j]) j++;
    next.push_back(j);
  }
  return next;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  auto next = build(s);
  int length = s.size();
  vector<int> ans;
  while(next[length]){
    ans.push_back(next[length]);
    length = next[length];
  }
  reverse(ans.begin(), ans.end());
  for(auto i:ans){
    cout << i << ' ';
  }
}