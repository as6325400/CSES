#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q, p = 1;
  cin >> n >> q;
  vector<vector<int>> table(25, vector<int>(n + 1, 1e9));
  for(int i = 1; i <= n; i++){
    cin >> table[0][i];
  }
  for(int i = 1; i <= 20; i++){
    p *= 2;
    for(int j = 1; j + (1 << (i - 1)) <= n; j++){
      table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
    }
  }
  for(int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    int j = (int)log2(r - l + 1);
    cout << min(table[j][l], table[j][r - (1 << j) + 1]) << '\n';
  }
}