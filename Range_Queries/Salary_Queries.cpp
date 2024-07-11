#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int long long

using namespace std;
using namespace __gnu_pbds;

template<class T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main(){
  int n, q;
  cin >> n >> q;
  vector<int> salary(n + 1);
  pbds<pair<int, int>> s;
  for(int i = 1; i <= n; i++){
    cin >> salary[i];
    s.insert({salary[i], i});
  }
  for(int i = 0; i < q; i++){
    char c;
    cin >> c;
    if(c == '!'){
      int x, y;
      cin >> x >> y;
      s.erase({salary[x], x});
      salary[x] = y;
      s.insert({salary[x], x});
    }else{
      int x, y;
      cin >> x >> y;
      cout << s.order_of_key({y, 1e9 + 7}) - s.order_of_key({x - 1, 1e9 + 7}) << '\n';
    }
  }
}