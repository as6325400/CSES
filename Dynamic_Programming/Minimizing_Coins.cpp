#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<int> dp(x + 1, 1e9);
  vector<int> save(n);
  for(int i = 0; i < n; i++){
    cin >> save[i];
  }
  for(int i = 1; i <= x; i++){
    for(int j = 0; j < n; j++){
      if(i - save[j] < 0) continue;
      else if(i - save[j] == 0) dp[i] = 1;
      else dp[i] = min(dp[i], dp[i - save[j]] + 1);
    }
  }

  if(dp[x] == 1e9) cout << -1 << '\n';
  else cout << dp[x] << '\n';
}