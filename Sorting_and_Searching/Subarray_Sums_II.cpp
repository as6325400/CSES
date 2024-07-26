#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  map<int, int> mp;
  mp[0] = 1;
  int sum = 0, ans = 0;
  for(int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    sum += num;
    if(mp.find(sum - x) != mp.end())
      ans += mp[sum - x];
    mp[sum]++;
  }
  cout << ans << '\n';
}