#include <bits/stdc++.h>
#define int long long

using namespace std;


signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      char c;
      cin >> c;
      int a = dp[i - 1][j] - dp[i - 1][j - 1];
      int b = dp[i][j - 1] - dp[i - 1][j - 1];
      dp[i][j] = dp[i - 1][j - 1] + a + b;
      if(c == '*') dp[i][j]++;
    }
  }

  for(int i = 0; i < q; i++){
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;  

    int a = dp[y2][x2];
    int b = dp[y2][x1 - 1];
    int c = dp[y1 - 1][x2];
    int d = dp[y1 - 1][x1 - 1];
    cout << a - b - c + d << '\n';
  }
}