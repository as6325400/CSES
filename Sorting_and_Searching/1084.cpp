#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < m; i++){
    cin >> b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int p1 = 0, p2 = 0, ans = 0;
  while(p1 < n and p2 < m){
    if(b[p2] <= a[p1] + x and b[p2] >= a[p1] - x){
      p1++;
      p2++;
      ans++;
    }
    else if(b[p2] < a[p1] - x){
      p2++;
    }
    else if(b[p2] > a[p1] + x){
      p1++;
    }
  }
  cout << ans << '\n';
}