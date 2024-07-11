#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#define int long long
 
using namespace std;

int p = 1e9 + 7;
int b = 31;

int h[2000010];
int POW[1000005];
 
void Pow(int b, int p){
  POW[0] = 1;
  for(int i = 1; i < 1000005; i++)
    POW[i] = POW[i - 1] * b % p;
  return;
}
 
void Hash(string s, int b, int p){
  h[0] = 0;
  int x = 1;
  for(int i = 0; i < s.size(); i++){
    h[i + 1] = (h[i] + s[i] * x) % p;
    x *= b;
    x %= p;
  }
  return;
}
 
int query(int l, int r, int index){
  int length = r - l + 1;
  return (h[r] - h[l - 1] + p) * POW[l - 1] % p;
}

int common(int s1, int s2, int length){
  // 找到不同的第一個
  // cout << s1 << ' ' << s2 << '\n';
  int l = 0, r = length - 1, mid;
  while(l <= r){
    mid = (l + r) / 2;
    // cout << mid << '\n';
    int q1 = query(s1, s1 + mid, s2 + mid);
    int q2 = query(s2, s2 + mid, s1 + mid);
    if(q1 != q2) r = mid - 1;
    else l = mid + 1;
  }
  return l;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  int len = s.size();
  s += s;
  Pow(b, p);
  Hash(s, b, p);
  int m = 0;
  for(int i = 1; i + len < s.size(); i++){
    int index = common(m, i, len);
    if(s[m + index] > s[i + index]) m = i;
  }
  cout << s.substr(m, len) << '\n';
  // cout << ccount << '\n';
}