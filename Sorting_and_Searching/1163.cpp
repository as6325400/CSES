#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  set<int> s;
  s.insert(0);
  s.insert(n);

  multiset<int> dist;
  dist.insert(n);
  for(int i = 0; i < m; i++){
    int x;
    cin >> x;
    auto it = s.lower_bound(x);
    int dis = *it - *(--it);
    if(dist.find(dis) != dist.end()){
      dist.erase(dist.find(dis));
      dist.insert(x - *it);
      dist.insert(*(++it) - x);
    }
    s.insert(x);

    it = dist.end();
    it--;
    cout << *it << ' ';
  }
}
