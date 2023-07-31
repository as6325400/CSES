#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, count = 0;
  cin >> n >> m;
  queue<pair<int, int>> q;
  vector<vector<char>> graph(n + 2, vector<char>(m + 2, '#'));
  vector<vector<char>> next(n + 2, vector<char>(m + 2, '#'));
  vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> graph[i][j];
      if(graph[i][j] == 'A'){
        q.push({i, j});
        graph[i][j] = '#';
        next[i][j] = 'S';
      }
    }
  }
  while(!q.empty()){
    int num = q.size();
    count++;
    for(int i = 0; i < num; i++){
      auto point = q.front();
      q.pop();
      for(int j = 0; j < 4; j++){
        int x = point.first + direction[j][0], y = point.second + direction[j][1];
        if(graph[x][y] != '#'){
          if(j == 0) next[x][y] = 'D';
          else if(j == 1) next[x][y] = 'U';
          else if(j == 2) next[x][y] = 'R';
          else next[x][y] = 'L';
        }
        if(graph[x][y] == 'B'){
          cout << "YES\n";
          cout << count << '\n';
          stack<char> s;
          while(next[x][y] != 'S'){
            s.push(next[x][y]);
            if(next[x][y] == 'D') x--;
            else if(next[x][y] == 'U') x++;
            else if(next[x][y] == 'L') y++;
            else y--;
          }
          while(!s.empty()){
            cout << s.top();
            s.pop();
          }
          return 0;
        }
        if(graph[x][y] == '.'){
          graph[x][y] = '#';
          q.push({x, y});
        }
      }
    }
  }
  cout << "NO\n";
}