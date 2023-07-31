#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  unordered_map<int, int> mp;

  int sum = 0, ans = 0;
  mp[0]++;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    sum += x;
    if(mp.find(sum - m) != mp.end()){
      ans += mp[sum - m];
    }
    mp[sum]++;
  }
  // cout << mp[]
  cout << ans << '\n';
}