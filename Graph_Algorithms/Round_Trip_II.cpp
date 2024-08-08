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
  
  int flag = 1;

  vector<int> color(n + 1, 0);
  vector<int> pre(n + 1, 0);
  function<void(int)> dfs = [&](int node){
    color[node] = 1;
    for(auto i:graph[node]){
      if(color[i] == 0){
        pre[i] = node;
        dfs(i);
      }
      if(color[i] == 1){
        pre[i] = node;
        int start = node;
        for(int j = 0; j < n; j++){
          start = pre[start];
        }
        flag = 0;
        vector<int> ans;
        auto temp = start;
        do{
          ans.push_back(temp);
          temp = pre[temp];
        }while(temp != start);
        ans.push_back(start);
        cout << ans.size() << '\n';
        for(int j = ans.size() - 1; j >= 0; j--){
          cout << ans[j] << ' ';
        }
        exit(0);
      }
    }
    color[node] = 2;
  };

  for(int i = 1; i <= n; i++){
    if(color[i] == 0) dfs(i);
  }

  if(flag){
    cout << "IMPOSSIBLE\n";
  }

}