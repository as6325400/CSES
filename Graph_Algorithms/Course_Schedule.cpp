#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  vector<int> input(n + 1, 0);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    input[b]++;
  }
  queue<int> q;
  for(int i = 1; i <= n; i++){
    if(input[i] == 0) q.push(i);
  }
  vector<int> ans;
  while(!q.empty()){
    int now = q.front();
    q.pop();
    for(auto i: graph[now]){
      input[i]--;
      if(input[i] == 0) q.push(i);
    }
    ans.push_back(now);
  }
  if(ans.size() != n){
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  for(auto i: ans){
    cout << i << ' ';
  }
}