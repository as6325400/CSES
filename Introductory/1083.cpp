#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> v(n + 1, 0);
  for(int i = 0; i <= n; i++){
    int num;
    cin >> num;
    v[num]++;
  }
  for(int i = 1; i <= n; i++){
    if(v[i] == 0){
      cout << i << '\n';
      break;
    }
  }
}