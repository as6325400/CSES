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
  vector<int> dp(1000001);
  for(int i = 0; i < n; i++){
    cin >> coin[i];
    // dp[coin[i]] = 1;
  }

  sort(coin.begin(), coin.end());
  dp[0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 1; j <= m; j++){
      if(j < coin[i]){}
      else{
        dp[j] += dp[j - coin[i]];
        dp[j] %= mod;
      }
    }
  }

  cout << dp[m] << '\n';
}