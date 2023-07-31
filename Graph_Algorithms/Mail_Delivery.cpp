#include <bits/stdc++.h>
#define int long long

using namespace std;

class Hierholzer{
    class Edge{
      public:
        int adj;
        list<Edge>::iterator inv;
        Edge(int _adj) : adj(_adj) {}
    };
    vector<list<Edge>> g;
    vector<int> path;
    vector<int> judge;
    int count = 0, edge_num = 0;
    void dfs(int v){
      count++;
      while (g[v].size() > 0) {
        int adj = g[v].front().adj;
        g[adj].erase(g[v].front().inv);
        g[v].pop_front();
        dfs(adj);
      }
      path.emplace_back(v);
    }
    bool het(vector<int> judge){
      // have elur tour
      for(int i = 0; i < judge.size(); i++){
        if(judge[i] % 2 != 0) return false;
      }
      return true;
    }
  public:
    // 輸入起始點，建構子為點的數量
    // 在計算由拉環前要在外部使用add_edge
    // 建構子 n 為頂點數量，0base為基準，1base題目請自行傳入時加1
    // 無向圖
    Hierholzer(int n){
      g.resize(n);
      judge.resize(n, 0);
    }
    void add_edge(int u, int v) {
      judge[u]++; judge[v]++; edge_num++;
      g[u].emplace_front(v);
      g[v].emplace_front(u);
      g[u].begin()->inv = g[v].begin();
      g[v].begin()->inv = g[u].begin();
    }
    vector<int> elur_tour(int start){
      if(!het(judge)) return {};
      dfs(1); // 隨便一個點開始dfs，若只有點0時須注意
      if(count != edge_num + 1) return {};
      reverse(path.begin(), path.end());
      return path;
    }
};

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  Hierholzer h(n + 1);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    h.add_edge(a, b);
  }
  auto e = h.elur_tour(1);
  if(e.size() == 0) cout << "IMPOSSIBLE\n";
  else{
    for(auto i:e){
      cout << i << ' ';
    }
    cout << '\n';
  }
}