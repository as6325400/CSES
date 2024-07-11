#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> num(n, 0);
  vector<int> dp(n + 1, 0);
  for(int i = 0; i < n; i++){
    cin >> num[i];
    dp[i + 1] = dp[i] + num[i];
  }

  for(int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    cout << dp[r] - dp[l - 1] << '\n';
  }

}