#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s1;
  cin >> s1;
  int n = s1.size();
  int ans = -1e9, temp = 0;
  char t = s1[0];
  for(int i = 0; i < n; i++){
    if(s1[i] == t){
      temp++;
    }else{
      ans = max(ans, temp);
      temp = 1;
      t = s1[i];
    }
  }
  cout << max(ans, temp) << '\n';
}