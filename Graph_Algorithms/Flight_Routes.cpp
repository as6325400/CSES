#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<pair<int, int>>> graph(n + 1);
  vector<int> ans[n + 1];
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({c, b});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 1});
  while(!pq.empty()){
    auto node = pq.top();
    pq.pop();
    if(ans[node.second].size() == k) continue;
    ans[node.second].push_back(node.first);
    for(auto i : graph[node.second]){
      pq.push({node.first + i.first, i.second});
    }
  }
  for(auto i : ans[n]){
    cout << i << ' ';
  }
}