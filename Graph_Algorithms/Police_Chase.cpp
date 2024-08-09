#include <bits/stdc++.h>
#define int long long
using namespace std;

// Edmonds-Karp Algorithm Time: O(VE^2) 實際上會快一點
// 記得在 main 裡面 resize graph

class edge{
  public:
    int next;
    int capacity;
    int rev;
    bool is_rev;
    edge(int _n, int _c, int _r, int _ir) : next(_n), capacity(_c), rev(_r), is_rev(_ir){};
};

vector<vector<edge>> graph;

void add_edge(int a, int b, int capacity){
  graph[a].push_back(edge(b, capacity, graph[b].size(), false));
  graph[b].push_back(edge(a, capacity, graph[a].size() - 1, true));
}

int dfs(int now, int end, int flow, vector<pair<int, int>> &path, int idx){
  if(now == end) return flow;
  auto &e = graph[now][path[idx + 1].second];
  if(e.capacity > 0){
    auto ret = dfs(e.next, end, min(flow, e.capacity), path, idx + 1);
    if(ret > 0){
      e.capacity -= ret;
      graph[e.next][e.rev].capacity += ret;
      return ret;
    }
  }
  return 0;
}

vector<pair<int, int>> search_path(int start, int end){
  vector<pair<int, int>> ans;
  queue<int> q;
  vector<pair<int, int>> parent(graph.size(), {-1, -1});
  q.push(start);
  while(!q.empty()){
    int now = q.front();
    q.pop();
    for(int i = 0; i < (int)graph[now].size(); i++){
      auto &e = graph[now][i];
      if(e.capacity > 0 and parent[e.next].first == -1){
        parent[e.next] = {now, i};
        if(e.next == end) break;
        q.push(e.next);
      }
    }
  }
  if(parent[end].first == -1) return ans;
  int now = end;
  while(now != start){
    auto [node, idx] = parent[now];
    ans.emplace_back(node, idx);
    now = node;
  }
  ans.emplace_back(start, -1);
  reverse(ans.begin(), ans.end());
  return ans;
}

int maxflow(int start, int end, int node_num){
  int ans = 0;
  while(1){
    vector<bool> visited(node_num + 1, false);
    auto tmp = search_path(start, end);
    if(tmp.size() == 0) break;
    auto flow = dfs(start, end, 1e9, tmp, 0);
    ans += flow;
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
    int a, b;
    cin >> a >> b;
    add_edge(a, b, 1);
  }
  maxflow(1, n, n);
  vector<bool> visited(n + 1, false);
  function<void(int)> dfs = [&](int node){
    visited[node] = true;
    for(auto &i:graph[node]){
      if(i.capacity && !visited[i.next]) dfs(i.next);
    }
  };
  dfs(1);
  vector<pair<int, int>> ans;
  for(int i = 1; i <= n; i++){
    for(auto j:graph[i]){
      if(visited[i] && !visited[j.next]){
        ans.push_back({i, j.next});
      }
    }
  }

  cout << ans.size() << '\n';
  for(auto i:ans){
    cout << i.first << ' ' << i.second << '\n';
  }
}