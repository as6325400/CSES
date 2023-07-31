// 2DFS


// #include <bits/stdc++.h>
// #define int long long

// using namespace std;

// int dis[200005];
// int c;

// void dfs(int now, int fa, vector<vector<int>> &graph){
//   for(auto i: graph[now]){
//     if(i != fa){
//       dis[i] = dis[now] + 1;
//       if(dis[i] > dis[c]) c = i;
//       dfs(i, now, graph);
//     }
//   }
// }

// signed main()
// {
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int n;
//   cin >> n;
//   vector<vector<int>> graph(n + 1);
//   for(int i = 0; i < n - 1; i++){
//     int a, b;
//     cin >> a >> b;
//     graph[a].push_back(b);
//     graph[b].push_back(a);
//   }
//   dfs(1, 0, graph);
//   dis[c] = 0;
//   dfs(c, 0, graph);
//   cout << dis[c];
// }

// DP

#include <bits/stdc++.h>
#define int long long

using namespace std;

int d1[200005], d2[200005], ans;

void dfs(int now, int fa, vector<vector<int>> &graph){
  for(auto i: graph[now]){
    if(i != fa){
      dfs(i, now, graph);
      if(d1[i] + 1 > d1[now]){
        d2[now] = d1[now];
        d1[now] = d1[i] + 1;
      }
      else if(d1[i] + 1 > d2[now]){
        d2[now] = d1[i] + 1;
      }
    }
  }
  ans = max(ans, d1[now] + d2[now]);
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> graph(n + 1);
  for(int i = 0; i < n - 1; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs(1, 0, graph);
  cout << ans << '\n';
}