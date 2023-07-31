#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, count = 0;
  cin >> n >> m;
  vector<vector<char>> graph(n + 2, vector<char>(m + 2, '#'));
  vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  vector<vector<char>> visited(n + 2, vector<char>(m + 2, '#'));
  queue<vector<int>> q;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> graph[i][j];
      if(graph[i][j] == 'M') q.push({i, j, 0});
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(graph[i][j] == 'A'){
        q.push({i, j, 1});
        visited[i][j] = 'S';
      }
    }
  }
  while(!q.empty()){
    int num = q.size();
    for(int i = 0; i < num; i++){
      auto point = q.front();
      q.pop();
      if(point[0] == 1 or point[0] == n or point[1] == 1 or point[1] == m){
        if(point[2] == 1){
          cout << "YES\n";
          cout << count << '\n';
          string ans = "";
          int x = point[0], y = point[1];
          while(visited[x][y] != 'S'){
            ans += visited[x][y];
            if(visited[x][y] == 'U') x++;
            else if(visited[x][y] == 'D') x--;
            else if(visited[x][y] == 'L') y++;
            else if(visited[x][y] == 'R') y--;
          }
          reverse(ans.begin(), ans.end());
          cout << ans << '\n';
          return 0;
        }
      }
      for(int j = 0; j < 4; j++){
        int x = point[0] + directions[j][0];
        int y = point[1] + directions[j][1];
        if(graph[x][y] == '.'){
          if(point[2] == 1){
            if(j == 0) visited[x][y] = 'D';
            if(j == 1) visited[x][y] = 'U';
            if(j == 2) visited[x][y] = 'R';
            if(j == 3) visited[x][y] = 'L';
          }
          graph[x][y] = '#';
          q.push({x, y, point[2]});
        }
      }
    }
    count++;
  }
  cout << "NO\n";
}