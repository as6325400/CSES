#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, ans = 1e9;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) cin >> arr[i]; 
  for(int i = 0; i < (1 << n); i++){
    int n1 = 0, n2 = 0;
    for(int j = 0; j < n; j ++){
      if(i & (1 << j)) n1 += arr[j];
      else n2 += arr[j];
    }
    ans = min(ans, abs(n1 - n2));
  }
  cout << ans << '\n';
}