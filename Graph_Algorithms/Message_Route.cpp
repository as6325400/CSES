#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, count = 0;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  vector<int> visited(n + 1, -1);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  queue<int> q;
  q.push(1);
  visited[1] = 0;
  while(!q.empty()){
    int num = q.size();
    count++;
    for(int i = 0; i < num; i++){
      int node = q.front();
      q.pop();
      if(node == n){
        std::cout << count << '\n';
        stack<int> s;
        while(visited[node] != -1){
          s.push(node);
          node = visited[node];
        }
        while(!s.empty()){
          std::cout << s.top() << ' ';
          s.pop();
        }
        return 0;
      }
      for(int j : graph[node]){
        if(visited[j] == -1){
          q.push(j);
          visited[j] = node;
        }
      }
    }
  }
  std::cout << "IMPOSSIBLE\n";
}