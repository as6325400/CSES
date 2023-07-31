#include <bits/stdc++.h>
#define int long long

using namespace std;

bool check(vector<int> &save, int x){
  
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> save(n);
  vector<int> dp;
  for(int i = 0; i < n; i++){
    cin >> save[i];
  }
  sort(save.begin(), save.end());

  int sum = 0;
  for(int i = 0; i < n; i++){
    if(sum + 1 < save[i]) break;
    sum += save[i];
  }
  cout << sum + 1 << '\n';
}