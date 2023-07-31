#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, mod = 1e9 + 7;
  cin >> n >> m;
  vector<int> coin(n);
  for(int i = 0; i < n; i++) cin >> coin[i];
  sort(coin.begin(), coin.end());
  vector<int> dp(m + 1);
  dp[0] = 1;
  for(int i = 1; i <= m; i++){
    for(int j = 0; j < n; j++){
      if(i < coin[j]) break;
      else{
        dp[i] += dp[i - coin[j]];
        dp[i] %= mod;
      }
    }
  }

  cout << dp[m] << '\n';
}