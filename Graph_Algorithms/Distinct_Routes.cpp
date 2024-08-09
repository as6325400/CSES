#include <bits/stdc++.h>
#define int long long
using namespace std;

// Edmonds-Karp Algorithm Time: O(VE^2) 實際上會快一點

class edge{
  public:
    int next;
    int capicity;
    int rev;
    bool is_rev;
    edge(int _n, int _c, int _r, int _ir) : next(_n), capicity(_c), rev(_r), is_rev(_ir){};
};

vector<vector<edge>> graph;

void add_edge(int a, int b, int capacity){
  graph[a].push_back(edge(b, capacity, graph[b].size(), false));
  graph[b].push_back(edge(a, 0, graph[a].size() - 1, true));
}

int dfs(int now, int end, int flow, vector<pair<int, int>> &path, int idx){
  if(now == end) return flow;
  auto &e = graph[now][path[idx + 1].second];
  if(e.capicity > 0){
    auto ret = dfs(e.next, end, min(flow, e.capicity), path, idx + 1);
    if(ret > 0){
      e.capicity -= ret;
      graph[e.next][e.rev].capicity += ret;
      return ret;
    }
  }
  return 0;
}

// first 點, second 為該點在前一個節點中的 index
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
      if(e.capicity > 0 and parent[e.next].first == -1){
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
  
  function<bool(int, int, vector<int> &)> ddfs = [&](int fa, int node, vector<int> &temp){
    // cout << "node " << node << '\n';
    if(node == n) return true;
    for(auto &i:graph[node]){
      if(i.next != fa && i.capicity == 0 && i.is_rev == 0 && ddfs(node, i.next, temp)){
        temp.push_back(i.next);
        i.is_rev = 1;
        if(node != 1) return true;
      }
    }
    return false;
  };
  vector<vector<int>> ans;
  vector<int> temp;
  ddfs(-1, 1, temp);
  reverse(temp.begin(), temp.end());
  vector<int> road;
  road.push_back(1);
  for(auto i:temp){
    road.push_back(i);
    if(i == n){
      ans.push_back(road);
      road.clear();
      road.push_back(1);
    }
  }
  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i].size() << '\n';
    for(auto j:ans[i]){
      cout << j << ' ';
    }
    cout << '\n';
  }
}