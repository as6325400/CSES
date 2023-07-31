#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  multiset<int> p;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    p.insert(x);
  }
  for(int i = 0; i < m; i++){
    int x;
    cin >> x;
    auto it = p.upper_bound(x);
    if(it == p.begin()){
      cout << -1 << '\n';
    }
    else{
      it--;
      cout << *it << '\n';
      p.erase(it);
    }
  }
}