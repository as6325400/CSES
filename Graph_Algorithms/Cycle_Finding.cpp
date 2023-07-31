#include <bits/stdc++.h>
#define int long long

using namespace std;


signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n + 1);
  vector<int> dist(n + 1, 1e14);
  vector<int> before(n + 1, -1);
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
  }
  for(int i = 0; i < n; i++){
    for(int j = 1; j <= n; j++){
      for(auto k : graph[j]){
        if(dist[j] + k.second < dist[k.first]){
          dist[k.first] = dist[j] + k.second;
          before[k.first] = j;
          if(i == n - 1){
            vector<int> ans;
            cout << "YES\n";
            int start = k.first;
            for(int i = 0; i < n; i++) start = before[start];
            int end = start;
            do
            {
              ans.push_back(start);
              // cout << start << " ";
              start = before[start];
            } while (start != end);
            ans.push_back(start);
            reverse(ans.begin(), ans.end());
            for(int i : ans) cout << i << " ";
            return 0;
          }
        }
      }
    }
  }
  cout << "NO\n";
}