#include <bits/stdc++.h>
#define int long long

using namespace std;

void dfs1(vector<vector<int>> &graph, vector<bool> &visited, int now){
  if(visited[now] != 0) return;
  visited[now] = 1;
  for(auto i: graph[now]){
    dfs1(graph, visited, i);
  }
}

void dfs2(vector<vector<int>> &graph, vector<bool> &visited, int now){
  if(visited[now] != 0) return;
  visited[now] = 1;
  for(auto i: graph[now]){
    dfs2(graph, visited, i);
  }
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(m);
  vector<vector<int>> e1(n + 1);
  vector<vector<int>> e2(n + 1);
  vector<bool> visited1(n + 1, 0);
  vector<bool> visited2(n + 1, 0);
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    graph[i] = {a, b, -c};
    e1[a].push_back(b);
    e2[b].push_back(a);
  }
  dfs1(e1, visited1, 1);
  dfs2(e2, visited2, n);
  vector<int> dis(n + 1, 1e13);
  dis[1] = 0;
  int origin , next;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(dis[graph[j][1]] > dis[graph[j][0]] + graph[j][2]){
        dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
        if(i == n - 1 and visited1[graph[j][1]] and visited2[graph[j][1]]){
          cout << "-1\n";
          return 0;
        }
      }
    }
  }
  cout << -dis[n] << '\n';
}