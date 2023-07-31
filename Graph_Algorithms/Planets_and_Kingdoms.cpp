#include <bits/stdc++.h>
#define int long long

using namespace std;


class tarjan{
    int time = 1;
    stack<int> s;
    vector<int> dfn;
    vector<int> low;
    vector<bool> in_stack;
    vector<vector<int>> ans;
    void dfs(int node, vector<vector<int>> &graph){
      in_stack[node] = true;
      s.push(node);
      dfn[node] = low[node] = time++;
      for(auto &j : graph[node]){
        if(dfn[j] == 0){
          dfs(j, graph);
          low[node] = min(low[node], low[j]); // 看看往下有沒有辦法回到更上面的點
        }
        else if(in_stack[j]){
          low[node] = min(low[node], low[j]);
        }
      }
      vector<int> t; // 儲存這個強連通分量
      if(dfn[node] == low[node]){
        while(s.top() != node){
          t.push_back(s.top());
          in_stack[s.top()] = false;
          s.pop();
        }
        t.push_back(s.top());
        in_stack[s.top()] = false;
        s.pop();
      }
      if(!t.empty()) ans.push_back(t);
    }
  public:
    vector<vector<int>> scc(vector<vector<int>> &graph){
      int num = graph.size();
      dfn.resize(num, 0);
      low.resize(num, 0);
      in_stack.resize(num, false);
      for(int i = 1; i < num; i++){
        if(dfn[i] == 0) dfs(i, graph);
      }
      return ans;
    }
};


signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  tarjan t;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }
  auto scc = t.scc(graph);
  cout << scc.size() << '\n';
  vector<int> ans(n + 1);
  for(int i = 0; i < scc.size(); i++){
    for(int j = 0; j < scc[i].size(); j++){
      ans[scc[i][j]] = i + 1;
    }
  }
  for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
}