#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int long long

using namespace std;
using namespace __gnu_pbds;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> s;

  s.insert(1);
  s.insert(2);
  s.insert(2);
  s.insert(3);
  s.insert(3);

  cout << "origin----------------------\n";

  for(auto i : s){
    cout << i << ' ';
  }
  cout << '\n';
  cout << "-----------------------------\n";

  cout << *s.upper_bound(2) << '\n';

  cout << "after erase------------------\n";

  for(auto i : s){
    cout << i << ' ';
  }
}