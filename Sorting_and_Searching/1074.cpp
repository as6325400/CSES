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
  for(int i = 0; i < n; i++){
    cin >> save[i];
  }
  sort(save.begin(), save.end());
  int value = save[n / 2];
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans += abs(save[i] - value);
  }
  cout << ans << '\n';
}