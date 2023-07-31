#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> path;
int edge = 0;
void dfs(int now, vector<vector<int>> &graph){
  edge++;
  while(graph[now].size() > 0){
    int n = graph[now].back();
    graph[now].pop_back();
    dfs(n, graph);
  }
  path.push_back(now);
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, count = 0;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  vector<int> in(n + 1), out(n + 1);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    out[a]++; in[b]++;
  }
  for(int i = 2; i < n; i++){
    if(abs(out[i] - in[i]) > 0){
      count += 48763;
      break;
    }
  }
  if(abs(out[1] - in[1]) != 1 or abs(out[n] - in[n]) != 1) count += 48763;
  if(count > 2) cout << "IMPOSSIBLE\n";
  else{
    dfs(1, graph);
    if(edge != m + 1){
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    reverse(path.begin(), path.end());
    for(auto i:path){
      cout << i << ' ';
    }
  }
}