#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, mod = 1e9 + 7;

  cin >> n;

  vector<vector<bool>> save(n + 1, vector<bool>(n + 1, false));
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  dp[0][1] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      char x;
      cin >> x;
      if(x == '*') save[i][j] = true;
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(save[i][j]) dp[i][j] = 0;
      else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
    }
  }

  // for(int i = 0; i <= n; i++){
  //   for(int j = 0; j <= n; j++){
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  cout << dp[n][n] << '\n';
}