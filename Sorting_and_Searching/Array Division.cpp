#include <bits/stdc++.h>
#define int long long

using namespace std;

bool judge(vector<int> &vec, int target, int k){
  int count = 0;
  for(int i = 0; i < vec.size(); i++){
    if(k <= 0) return false;
    if(count + vec[i] > target){
      k--;
      count = 0;
      i--;
    }
    else count += vec[i];
  }
  return true;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> vec(n);
  for(int i = 0; i < n; i++){
    cin >> vec[i];
  }
  int l = 0, r = 2e14, ans = -1;
  while(l <= r){
    int mid = (l + r) / 2;
    // cout << "mid " << mid << ' ' << l << ' ' << r << ' ' << judge(vec, mid, k) << '\n';
    if(judge(vec, mid, k)){
      r = mid - 1;
      ans = mid;
    }
    else l = mid + 1;
  }
  cout << ans << '\n';
}