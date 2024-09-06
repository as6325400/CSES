#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> prime_table(int n){
  vector<int> table(n + 1, 0);
  for(int i = 1; i <= n; i++){
    for(int j = i; j <= n; j += i){
      table[j]++;
    }
  }
  return table;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  auto table = prime_table(1e6 + 5);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    cout << table[x] << '\n';
  }
}