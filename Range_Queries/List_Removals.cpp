#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	int n;
	cin >> n;
	Tree<int> pbds;
	vector<int> p(n + 1);
	for(int i = 1; i <= n; i++){
    pbds.insert(i);
    cin >> p[i];
  }
  for(int i = 1; i <= n; i++){
    int q;
    cin >> q;
    int pos = *pbds.find_by_order(q - 1);
    pbds.erase(pos);
    cout << p[pos] << ' ';
  }
  cout << '\n';
}