#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, ans = 0;
  cin >> n >> m;
  vector<int> save(n);
  for(int i = 0; i < n; i++){
    cin >> save[i];
  }
  sort(save.begin(), save.end());
  int left = 0, right = n - 1;
  while(right >= left){
    if(save[right] + save[left] <= m){
      left++;
      right--;
      ans++;
    }
    else{
      right--;
      ans++;
    }
  }
  cout << ans << '\n';
}