#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, mod = 1e9 + 7;
  cin >> n;
  int sum = (1 + n) * n / 2;
  if(sum % 2 == 1){
    cout << 0 << '\n';
    return 0;
  }
  sum /= 2;
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
  for(int i = 0; i <= n; i++){
    dp[i][0] = 1;
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= sum; j++){
      if(j < i) dp[i][j] = dp[i - 1][j];
      else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - i]) % mod;
    }
  }
  // for(int i = 1; i <= n; i++){
  //   for(int j = 1; j <= sum; j++){
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  dp[n][sum] = (dp[n - 1][sum] + dp[n - 1][sum - n]) / 2 % mod;
  cout << dp[n][sum] << '\n';
}