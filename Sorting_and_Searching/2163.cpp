#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int long long

using namespace std;
using namespace __gnu_pbds;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
  for(int i = 1; i <= n; i++){
    s.insert(i);
  }
  int index = m;
  index %= n;
  while(n--){
    auto it = s.find_by_order(index);
    cout << *it << ' ';
    if(n == 0) break;
    s.erase(it);
    index += m;
    index %= n;
  }
}