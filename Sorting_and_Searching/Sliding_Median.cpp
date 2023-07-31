#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int long long

using namespace std;
using namespace __gnu_pbds;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> s;
  vector<int> save(n + 1);
  for(int i = 1; i <= n; i++) cin >> save[i];

  for(int i = 1; i <= n; i++){
    s.insert(save[i]);
    if(i >= k){
      auto it = s.find_by_order(k / 2);
      if(k % 2 == 0) it--;
      cout << *it << ' ';
      s.erase(s.upper_bound(save[i - k + 1]));
    }
  }
}