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
      int time = 1;
      while(!s.empty()) s.pop();
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

int dfs(int now, vector<vector<int>> &graph, vector<int> &price, vector<int> &dp){
  if(dp[now] != -1e9) return dp[now];
  if(graph[now].size() == 0){
    dp[now] = price[now];
    return price[now];
  }
  int t = -1e9;
  for(int i = 0; i < graph[now].size(); i++){
    t = max(t, dfs(graph[now][i], graph, price, dp));
  }
  dp[now] = t + price[now];
  return dp[now];
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> price(n + 1);
  vector<vector<int>> graph(n + 1);
  tarjan t;
  for(int i = 1; i <= n; i++){
    cin >> price[i];
  }
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }
  auto scc = t.scc(graph);
  vector<int> group(n + 1, 0);
  vector<int> p(scc.size() + 1, 0);
  for(int i = 0; i < scc.size(); i++){
    int temp = 0;
    for(int j = 0; j < scc[i].size(); j++){
      temp += price[scc[i][j]];
      group[scc[i][j]] = i + 1;
    }
    p[i + 1] = temp;
  }
  vector<vector<int>> graph2(scc.size() + 1);
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < graph[i].size(); j++){
      if(group[i] != group[graph[i][j]]){
        graph2[group[i]].push_back(group[graph[i][j]]);
      }
    }
  }
  vector<int> indegree(scc.size() + 1, 0);
  for(int i = 1; i <= scc.size(); i++){
    for(int j = 0; j < graph2[i].size(); j++){
      indegree[graph2[i][j]]++;
    }
  }
  vector<int> q;
  for(int i = 1; i <= scc.size(); i++) if(indegree[i] == 0) q.push_back(i);
  int ans = -1e9;
  vector<int> dp(scc.size() + 1, -1e9);
  for(auto i:q){
    ans = max(dfs(i, graph2, p, dp), ans);
  }
  cout << ans << '\n';
}