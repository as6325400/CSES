#include <bits/stdc++.h>
#define int long long

using namespace std;

int a = 0;

void dfs(int now, int fa, vector<vector<int>> &graph, vector<int> &dis){
  dis[now] = dis[fa] + 1;
  // cout << now << ' ' << fa << ' ' << dis[now] << ' ' << dis[a] << '\n';
  if(dis[a] < dis[now]) a = now;
  for(auto &i : graph[now]){
    if(i == fa) continue;
    dfs(i, now, graph, dis);
  }
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> graph(n + 1);
  for(int i = 0; i < n - 1; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vector<int> dis1(n + 1, -1);
  vector<int> dis2(n + 1, -1);
  dfs(1, 0, graph, dis1);
  // cout << a << '\n';
  int left = a;
  // cout << "----------\n";
  dfs(left, 0 , graph, dis2);
  // cout << a << '\n';
  int right = a;
  // cout << "----------\n";
  dfs(a, 0, graph, dis1);
  // cout << left << ' ' << right << '\n';
  for(int i = 1; i <= n; i++){
    cout << max(dis1[i], dis2[i]) << ' ';
  }
}