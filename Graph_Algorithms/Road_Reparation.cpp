#include <bits/stdc++.h>
#define int long long

using namespace std;

class dsu{
    vector<int> parent;
  public:
    dsu(int n){
      parent.resize(n);
      for(int i = 0; i < n; i++) parent[i] = i;
    }
    int find_root(int a){
      if(parent[a] == a) return a;
      return parent[a] = find_root(parent[a]);
    }
    bool same(int a, int b){
      return find_root(a) == find_root(b);
    }
    void merge(int a, int b){
      parent[find_root(a)] = find_root(b);
    }
};

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  dsu d(n + 1);
  vector<tuple<int, int, int>> edge;
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    edge.push_back({c, a, b});
  }
  sort(edge.begin(), edge.end());
  int ans = 0, count = 0;
  for(int i = 0; i < m; i++){
    int cost = get<0>(edge[i]), a = get<1>(edge[i]), b = get<2>(edge[i]);
    if(!d.same(a, b)){
      ans += cost;
      d.merge(a, b);
      count++;
    }
  }
  if(count != n - 1) cout << "IMPOSSIBLE\n";
  else cout << ans << '\n';
}