#include <bits/stdc++.h>
#define int long long

using namespace std;

class edge{
  public:
    int next;
    int capicity;
    int rev;
    edge(int _n, int _c, int _r) : next(_n), capicity(_c), rev(_r){};
};

vector<vector<edge>> graph;

void add_edge(int a, int b, int capacity){
  graph[a].push_back(edge(b, capacity, graph[b].size()));
  graph[b].push_back(edge(a, 0, graph[a].size() - 1));
}

int dfs(int now, int end, int flow, vector<bool> &visited){
  if(now == end) return flow;
  visited[now] = true;
  for(int i = 0; i < graph[now].size(); i++){
    auto &e = graph[now][i];
    if(e.capicity > 0 and !visited[e.next]){
      auto ret = dfs(e.next, end, min(flow, e.capicity), visited);
      if(ret > 0 ){
        e.capicity -= ret;
        graph[e.next][e.rev].capicity += ret;
        return ret;
      }
    }
  }
  return 0;
}

int maxflow(int start, int end, int node_num){
  int ans = 0;
  while(1){
    vector<bool> visited(node_num + 1, false);
    auto tmp = dfs(start, end, 1e9, visited);
    if(tmp <= 0) break;
    ans += tmp;
  }
  return ans;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  graph.resize(n + 1);
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    add_edge(a, b, c);
  }
  cout << maxflow(1, n, n);
}