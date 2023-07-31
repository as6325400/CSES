#include <bits/stdc++.h>
#define int long long

using namespace std;

int dfs(int now, vector<vector<int>> &graph, vector<int> &visited, int parent){
  if(visited[now] != -1){
    visited[now] = parent;
    return now;
  }
  visited[now] = parent;
  for(auto i: graph[now]){
    if(i == parent) continue;
    if(auto start = dfs(i, graph, visited, now)){
      return start;
    }
  }
  return false;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  // cout << "input taken\n";
  vector<int> visited(n + 1, -1);
  for(int i = 1; i <= n; i++){
    if(visited[i] != -1) continue;
    if(auto start = dfs(i, graph, visited, 0)){
      int node = start;
      vector<int> ans;
      do
      {
        ans.push_back(node);
        node = visited[node];
      } while (node != start);
      ans.push_back(start);
      cout << ans.size() << '\n';
      for(auto i: ans){
        cout << i << ' ';
      }
      return 0;
    }
  }
  cout << "IMPOSSIBLE\n";
}