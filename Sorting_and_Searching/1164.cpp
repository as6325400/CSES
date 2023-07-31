#include <bits/stdc++.h>
#define int long long

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
  if(a.second == b.second){
    return a.first < b.first;
  }
  return a.second < b.second;
}

int binary_search(vector<int> &save, int x){
  auto it = lower_bound(save.begin(), save.end(), x);
  if(it == save.begin()) return -1;
  it--;
  return it - save.begin();
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, ans = 0;
  cin >> n;
  vector<pair<int, int>> save(n);
  for(int i = 0; i < n; i++){
    cin >> save[i].first >> save[i].second;
  }
  sort(save.begin(), save.end(), cmp);

  vector<int> end(n);
  vector<int> dp(n);
  vector<bool> visited(n, false);
  for(int i = 0; i < n; i++){
    end[i] = save[i].second;
  }
  for(int i = 0; i < n; i++){
    dp[i] = binary_search(end, save[i].first);
  }
  int count = 1;
  vector<int> a(n);
  for(int i = n - 1; i >= 0; i--){
    if(visited[i]) continue;
    int index = i;
    while(dp[index] != -1){
      if(visited[index]) break;
      visited[index] = true;
      a[index] = count;
      index = dp[index];
    }
    visited[index] = true;
    a[index] = count;
    count++;
  }
  cout << count - 1 << '\n';
  for(int i = 0; i < n; i++){
    cout << a[i] << ' ';
  }
}