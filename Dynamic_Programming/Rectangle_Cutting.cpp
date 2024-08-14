#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp(501, vector<int>(501, 1e9));

int dfs(int n, int m){
  if(n == m) return 0;
  if(n > m) swap(n, m);
  if(dp[n][m] != 1e9) return dp[n][m];
  int count = 1e9;
  for(int i = 1; i < n; i++){
    // cout << i << ' ' << n - i << '\n';
    count = min(count, dfs(i, m) + dfs(n - i, m) + 1);
  }
  for(int i = 1; i < m; i++){
    count = min(count, dfs(n, i) + dfs(n, m - i) + 1);
  }
  dp[n][m] = count;
  return count;
};

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, count = 0;
  cin >> n >> m;
  if(n > m) swap(n, m);
  cout << dfs(n, m) << '\n';
}