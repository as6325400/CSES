#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  if(n < 4){
    if(n == 1) cout << 1 << '\n';
    else cout << "NO SOLUTION\n";
  }
  else{
    for(int i = 2; i <= n; i += 2){
      cout << i << ' ';
    }
    for(int i = 1; i <= n; i += 2){
      cout << i << ' ';
    }
  }
  cout << '\n';
}