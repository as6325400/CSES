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
  for(int i = 0; i < n; i++) cin >> save[i]; 
  vector<int> dp;
  dp.push_back(save[0]);
  for(int i = 1; i < n; i++){
    if(save[i] > dp.back()) dp.push_back(save[i]);
    else{
      auto it = lower_bound(dp.begin(), dp.end(), save[i]);
      *it = save[i];
    }
  }
  cout << dp.size() << '\n';
}