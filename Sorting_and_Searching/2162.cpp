#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int long long

using namespace std;
using namespace __gnu_pbds;

signed main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  int n;
  cin >> n;
  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;
  for(int i = 1; i <= n; i++){
    st.insert(i);
  }
  int index = 1;
  index %= n;
  while(n--){
    auto it = st.find_by_order(index);
    cout << *it << ' ';
    if(n == 0) break;
    st.erase(it);
    index += 1;
    index %= n;
  }
}