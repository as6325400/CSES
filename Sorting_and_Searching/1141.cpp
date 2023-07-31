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

  int left = 0, right = 0;
  int ans = 0;
  map<int, int> mp;
  mp[save[0]]++;
  while(right < n){
    if(left == right) right++;
    else if(mp.find(save[right]) == mp.end()){
      mp[save[right]]++;
      ans = max(ans, right - left + 1);
      right++;
    }
    else{
      while(save[left] != save[right]) mp.erase(save[left++]);
      left++;
      ans = max(ans, right - left + 1);
      right++;
    }
  }
  ans = max(ans, right - left);
  cout << ans << '\n';
}