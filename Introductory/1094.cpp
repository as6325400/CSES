#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> v(n, 0);
  int ans = 0, t = 0;
  for(int i = 0; i < n; i++){
    cin >> v[i];
    if(i != 0){
      ans += max((int)0, (t - v[i]));
      if(t < v[i]){
        t = v[i];
      }
    }
    else if(i == 0){
      t = v[0];
    }
  }
  cout << ans << '\n';
}