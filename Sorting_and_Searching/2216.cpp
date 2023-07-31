#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, ans = 0;
  cin >> n;
  vector<int> save(n);
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    save[x - 1] = i;
  }
  

  for(int i = 1; i < n; i++){
    if(save[i] < save[i - 1]) ans++;
  }
  cout << ++ans << '\n';
}