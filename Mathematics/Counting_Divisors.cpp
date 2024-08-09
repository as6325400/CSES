#include <bits/stdc++.h>
#define int long long

using namespace std;


signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> table(1e6 + 5, 0);
  for(int i = 1; i <= 1e6; i++){
    for(int j = i; j <= 1e6; j += i){
      table[j]++;
    }
  }
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    cout << table[x] << '\n';
  }
}