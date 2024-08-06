#include <bits/stdc++.h>
#define int long long

using namespace std;

class tarjan{
    //  1-base
    int time = 1;
    int id = 1;
    stack<int> s;
    vector<int> low;
    vector<int> dfn;
    vector<bool> in_stack;
    void dfs(int node, vector<vector<int>> &graph){
      in_stack[node] = true;
      s.push(node);
      dfn[node] = low[node] = time++;
      for(auto &j : graph[node]){
        if(dfn[j] == 0){
          dfs(j, graph);
          // 看看往下有沒有辦法回到更上面的點
          low[node] = min(low[node], low[j]); 
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
          scc_id[s.top()] = id;
          s.pop();
        }
        t.push_back(s.top());
        scc_id[s.top()] = id;
        in_stack[s.top()] = false;
        s.pop();
        id++;
      }
      if(!t.empty()) ans.push_back(t);
    }
  public:
    vector<int> scc_id;
    vector<vector<int>> ans;
    vector<vector<int>> scc(vector<vector<int>> &graph){
      int num = graph.size();
      scc_id.resize(num, -1);
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
  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(m * 2 + 1);
  function<int(int)> tr = [&](int x){
    if(x > m) return x - m;
    return x + m;
  }; 

  for(int i = 0; i < n; i++){
    char c1, c2;
    int a, b;
    cin >> c1 >> a >> c2 >> b;
    // a 代表 a 為真，m + a 代表 a 為假
    if(c1 == '-') a += m;
    if(c2 == '-') b += m;
    graph[tr(a)].push_back(b);
    graph[tr(b)].push_back(a);
  }

  tarjan t;
  auto scc = t.scc(graph);

  // cout << scc.size() << '\n';

  for(int i = 1; i <= m; i++){
    if(t.scc_id[i] == t.scc_id[tr(i)]){
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }

  for(int i = 1; i <= m; i++){
    if(t.scc_id[i] < t.scc_id[tr(i)]){
      cout << '+';
    }
    else cout << '-';
    cout << ' ';
  }

  cout << '\n';
}