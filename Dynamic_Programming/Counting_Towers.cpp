#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;

vector<vector<int>> dp;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  dp.resize(1000005, vector<int>(2, -1));
  dp[1][0] = dp[1][1] = 1;
  function<int(int, int)> ans = [&](int level, int mode){
    // cout << level << ' ' << mode << '\n';
    if(dp[level][mode] != -1) return dp[level][mode];
    if(mode == 0){
      dp[level][mode] = 4 * ans(level - 1, mode) + ans(level - 1, 1);
    }
    else{
      dp[level][mode] = 2 * ans(level - 1, mode) + ans(level - 1, 0);
    }
    return dp[level][mode] %= mod;
  };
  for(int i = 0; i < n; i++){
    int q;
    cin >> q;
    cout << (ans(q, 0) + ans(q, 1)) % mod << '\n';
  }
}