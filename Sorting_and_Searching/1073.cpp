#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, ans = 0;
  cin >> n;
  vector<int> save;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    auto it = upper_bound(save.begin(), save.end(), x);
    if(it == save.end()) save.push_back(x);
    else *it = x;
  }
  cout << save.size() << '\n';
}