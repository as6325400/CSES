#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }

  stack<int> s;
  vector<bool> in_stack(n + 1, false);
  vector<int> color(n + 1);

  function<void(int)> dfs = [&](int node){
    color[node] = 1;
    in_stack[node] = true;
    for(auto i:graph[node]){
      if(color[i] == 1){
        cout << "IMPOSSIBLE\n";
        exit(0);
      }
      if(!in_stack[i]) dfs(i);
    }
    color[node] = 2;
    s.push(node);
  };

  for(int i = 1; i <= n; i++){
    if(!in_stack[i]) dfs(i);
  }

  while(!s.empty()){
    cout << s.top() << ' ';
    s.pop();
  }
  cout << '\n';
}