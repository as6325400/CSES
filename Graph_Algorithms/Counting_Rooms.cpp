#include <bits/stdc++.h>
#define int long long

using namespace std;

void dfs(vector<vector<char>> &graph, int x, int y){
  if(graph[x][y] == '#'){
    return;
  }
  graph[x][y] = '#';
  dfs(graph, x + 1, y);
  dfs(graph, x - 1, y);
  dfs(graph, x, y + 1);
  dfs(graph, x, y - 1);
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, count = 0;
  cin >> n >> m;
  vector<vector<char>> graph(n + 2, vector<char>(m + 2, '#'));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> graph[i][j];
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(graph[i][j] != '#'){
        count++;
        dfs(graph, i, j);
      }
    }
  }
  cout << count << "\n";
}