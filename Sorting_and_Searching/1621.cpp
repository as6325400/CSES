#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<int, int> mp;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    mp[x]++;
  }
  cout << mp.size() << endl;
}