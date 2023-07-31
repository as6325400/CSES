#include <bits/stdc++.h>
#define int long long

using namespace std;

bool dfs(int now, vector<vector<int>> &graph, vector<int> &color, int c){
  if(color[now] != -1){
    if(color[now] != c) return false;
    return true;
  }
  color[now] = c;
  for(int i : graph[now]){
    if(!dfs(i, graph, color, 1 - c)){
      // cout << "false " << now << ' ' << i << '\n';
      return false;
    }
  }
  return true;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  vector<int> color(n + 1, -1);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for(int i = 1; i <= n; i++){
    if(color[i] != -1) continue;
    if(!dfs(i, graph, color, 0)){
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }
  for(int i = 1; i <= n; i++) cout << color[i] + 1 << ' ';
}