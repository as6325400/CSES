#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  vector<int> dp((1 << n) + 1), last((1 << n) + 1);
  dp[0] = 1;
  for(int i = 0; i < n; i++) cin >> arr[i];
  for(int i = 1; i < (1 << n); i++){
    // 1011
    // 1010 1001 0011
    dp[i] = 1e15;
    last[i] = 1e15;
    for(int j = 0; j < n; j++){
      // 若第 j 位為 0 跳過
      if(!(i & (1 << j))) continue;
      int last_e = last[i & ~(1 << j)] + arr[j];
      if(last_e < last[i] and last_e <= k and dp[i & ~(1 << j)] <= dp[i]){
        dp[i] = dp[i & ~(1 << j)];
        last[i] = last_e;
      }
      else if(last_e > k and dp[i & ~(1 << j)] < dp[i]){
        dp[i] = dp[i & ~(1 << j)] + 1;
        last[i] = arr[j];
      }
      else if(last_e > last[i] and dp[i & ~(1 << j)] < dp[i]){
        dp[i] = dp[i & ~(1 << j)];
        last[i] = last_e;
      }
    }
  }
  cout << dp[(1 << n) - 1] << '\n';
}