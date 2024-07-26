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
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int count = arr[0];
  int l = 0, r = 0, ans = 0;
  while(r < n)
  {
    if(count < k){
      r++;
      count += arr[r];
    }
    else if(count > k){
      count -= arr[l];
      l++;
    }
    else{
      ans++;
      count -= arr[l];
      l++;
    }
  }
  cout << ans << endl;
}