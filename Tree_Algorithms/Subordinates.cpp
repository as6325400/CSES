#include <bits/stdc++.h>
#define int long long

using namespace std;

int ans[200005];

int dfs(int now, vector<vector<int>> &graph){
  if(graph[now].size() == 0){
    ans[now] = 0;
    return 1;
  }
  int count = 0;
  for(int i : graph[now]){
    count += dfs(i, graph);
  }
  ans[now] += count;
  return ans[now] + 1;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> graph(n + 1);
  for(int i = 2; i <= n; i++){
    int a;
    cin >> a;
    graph[a].push_back(i);
  }
  dfs(1, graph);
  for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}