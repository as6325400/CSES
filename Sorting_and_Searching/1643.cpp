#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> save(n);
  vector<int> dp(n);
  for(int i = 0; i < n; i++){
    cin >> save[i];
  }
  dp[0] = save[0];
  for(int i = 1; i < n; i++){
    dp[i] = max(dp[i - 1], (int)0) + save[i];
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
}