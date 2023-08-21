#include <bits/stdc++.h>
#define int long long

using namespace std;

int b = 223;

vector<int> Pow(int num){
  int p = 1e9 + 7;
  vector<int> ans = {1};
  for(int i = 0; i < num; i++)
    ans.push_back(ans.back() * b % p);
  return ans;
}

vector<int> Hash(string s){
  int p = 1e9 + 7;
  vector<int> ans = {0};
  for(char c:s){
    ans.push_back((ans.back() * b + c) % p);
  }
  return ans;
}

int query(vector<int> &vec, vector<int> &pow, int l, int r){
  int p = 1e9 + 7;
  int length = r - l + 1;
  return (vec[r + 1] - vec[l] * pow[length] % p + p) % p;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s1, s2;
  cin >> s1 >> s2;
  auto pow = Pow(1e6 + 5);
  int length = s2.size();
  auto h1 = Hash(s1);
  auto h2 = Hash(s2);
  // cout << s1.size() << ' ' << s2.size() << '\n';
  // cout << h1.back() << ' ' << h2.back() << '\n';
  int count = 0;
  for(int i = 0; i + length - 1 < s1.size(); i++){
    if(query(h1, pow, i, i + length - 1) == h2.back()) count++;
  }
  cout << count << '\n';
}