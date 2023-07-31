#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, mod = 1e9 + 7;
  cin >> n >> m;
  vector<int> save(n);
  for(int i = 0; i < n; i++) cin >> save[i];

  vector<vector<int>> dp(n, vector<int>(m + 2, 0));
  if(save[0] == 0){
    for(int i = 1; i <= m; i++) dp[0][i] = 1;
  }
  else dp[0][save[0]] = 1;
  for(int i = 1; i < n; i++){
    if(save[i] == 0){
      for(int j = 1; j <= m; j++){
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
      }
    }
    else{
      dp[i][save[i]] = (dp[i - 1][save[i] - 1] + dp[i - 1][save[i]] + dp[i - 1][save[i] + 1]) % mod;
    }
  }
  cout << accumulate(dp[n - 1].begin(), dp[n - 1].end(), (int)0) % mod << '\n';

}