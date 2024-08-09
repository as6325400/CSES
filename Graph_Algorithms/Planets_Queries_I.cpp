#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> dp(65, vector<int>(n + 1));
  for(int i = 1; i <= n; i++){
    cin >> dp[0][i];
  }
  for(int i = 1; i <= 64; i++){
    for(int j = 1; j <= n; j++){
      dp[i][j] = dp[i - 1][dp[i - 1][j]];
    }
  }
  for(int i = 0; i < q; i++){
    int x, k, idx = 0;
    cin >> x >> k;
    while(k != 0){
      if(k % 2 == 1){
        x = dp[idx][x];
      }
      k /= 2;
      idx++;
    }
    cout << x << '\n';
  }
}