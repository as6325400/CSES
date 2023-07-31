#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, mod = 1e9 + 7;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= 6; j++){
      if(j > i) break;
      else{
        dp[i] += dp[i - j];
        dp[i] %= mod;
      }
    }
  }
  cout << dp[n] << '\n';
}