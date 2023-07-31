#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, count = 0;
  cin >> n >> m;
  vector<int> indegree(n + 1, 0);
  vector<vector<int>> graph(n + 1);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    indegree[b]++;
  }
  queue<int> q;
  for(int i = 1; i <= n; i++){
    if(indegree[i] == 0) q.push(i);
  }
  while(!q.empty()){
    int now = q.front();
    q.pop();
    for(int i : graph[now]){
      indegree[i]--;
      if(indegree[i] == 0) q.push(i);
    }
    count++;
  }
  if(count == n) cout << "IMPOSSIBLE\n";
  else{
    for(int i = 1; i <= n; i++){
      if(indegree[i] != 0){
        q.push(i);
        break;
      }
    }
    vector<int> visited(n + 1, 0);
    set<int> s;
    while(!q.empty()){
      int now = q.front();
      q.pop();
      s.insert(now);
      for(int i : graph[now]){
        if(indegree[i] == 0) continue;
        visited[i] = now;
        if(s.find(i) == s.end()) q.push(i);
        else{
          for(int j = 0; j < n; j++) i = visited[i];
          stack<int> st;
          int index = i;
          st.push(i);
          do
          {
            st.push(visited[index]);
            index = visited[index];
          } while (st.top() != i);
          
          cout << st.size() << '\n';
          while(!st.empty()){
            cout << st.top() << ' ';
            st.pop();
          }
          cout << '\n';
          for(int i = 1; i <= n; i++){
            cout << visited[i] << ' ';
          }
          return 0;
        }
      }
    }

    
  }
}