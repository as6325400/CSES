#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>> &graph){
  vector<int> dis(graph.size(), 1e18);
  vector<bool> visited(graph.size(), false);
  dis[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, start});
  while(!pq.empty()){
    auto node = pq.top();
    pq.pop();
    if(visited[node.second]) continue;
    visited[node.second] = true;
    for(auto i:graph[node.second]){
      if(dis[i.first] > dis[node.second] + i.second){
        dis[i.first] = dis[node.second] + i.second;
        pq.push({dis[i.first], i.first});
      }
    }
  }
  return dis;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, ans = 1e18 + 7;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n + 1);
  vector<vector<pair<int, int>>> graph2(n + 1);
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph2[b].push_back({a, c});
  }
  auto dis1 = dijkstra(1, graph);
  auto dis2 = dijkstra(n, graph2);
  // for(int i = 1; i < dis1.size(); i++){
  //   cout << dis1[i] << ' ';
  // }
  // cout << '\n';
  // for(int i = 1; i < dis1.size(); i++){
  //   cout << dis2[i] << ' ';
  // }
  // cout << '\n';
  for(int i = 1; i <= n; i++){
    for(auto j:graph[i]){
      ans = min(ans, dis1[i] + dis2[j.first] + j.second / 2);
    }
  }
  cout << ans << '\n';
}