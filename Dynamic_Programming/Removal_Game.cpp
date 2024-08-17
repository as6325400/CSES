#include <bits/stdc++.h>
#define int long long

using namespace std;

int arr[5005];

pair<int, int> dfs(int people, int lb, int rb, int idx, pair<int, int> score){
  if(people == 0) cout << "idx " << idx << ' ' << '\n';
  if(people == 0) score.first += arr[idx];
  else if(people == 1) score.second += arr[idx];
  if(lb == rb) return score;
  auto l = dfs(1 - people, lb + 1, rb, lb + 1, score);
  auto r = dfs(1 - people, lb, rb - 1, rb - 1, score);
  if(people == 1){
    if(l.first >= r.first) return l;
    return r;
  }
  else{
    if(l.first >= r.first) return r;
    return l;
  }
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  auto l = dfs(0, 0, n - 1, 0, {0, 0});
  // auto r = dfs(0, 0, n - 1, n - 1, {0, 0});
  // if(l.first > r.first) 
  cout << l.first << '\n';
  // else cout << r.first << '\n';
}