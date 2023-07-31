#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, end;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  vector<int> indegree(n + 1, 0);
  vector<int> dis(n + 1, -1e9);
  vector<int> before(n + 1, -1);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    indegree[b]++;
  }
  queue<int> q;
  for(int i = 1; i <= n; i++){
    if(indegree[i] == 0) q.push(i);
  }
  dis[1] = 0;
  while(!q.empty()){
    auto node = q.front();
    q.pop();
    for(auto &j:graph[node]){
      if(dis[node] + 1 > dis[j]){
        dis[j] = dis[node] + 1;
        before[j] = node;
      }
      indegree[j]--;
      if(indegree[j] == 0) q.push(j);
    }
  }
  if(dis[n] < 0) cout << "IMPOSSIBLE" << '\n';
  else{
    int end = n;
    vector<int> ans;
    while(end != 1){
      ans.push_back(end);
      end = before[end];
    }
    ans.push_back(1);
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
      cout << ans[i] << ' ';
    }
  }
}