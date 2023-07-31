#include <bits/stdc++.h>
#define int long long

using namespace std;


signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, ans = 0, mx = 0;
  cin >> n;
  map<int, int> mp;
  for(int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y;
    mp[x]++;
    mp[y]--;
  }

  for(auto i : mp){
    ans += i.second;
    mx = max(mx, ans);
  }

  cout << mx << '\n';
}