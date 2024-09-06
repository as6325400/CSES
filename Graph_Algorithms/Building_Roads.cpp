#include <bits/stdc++.h>
#define int long long

using namespace std;

class dsu{
    vector<int> parent;
  public:
    dsu(int num){
      parent.resize(num);
      for(int i = 0; i < num; i++) parent[i] = i;
    }
    int find(int x){
      if(parent[x] == x) return x;
      return parent[x] = find(parent[x]);
    }
    bool same(int a, int b){
      return find(a) == find(b);
    }
    void Union(int a, int b){
      parent[find(a)] = find(b);
    }
};

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  dsu d(n + 1);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    d.Union(a, b);
  }
  set<int> s;
  for(int i = 1; i <= n; i++){
    s.insert(d.find(i));
  }
  cout << s.size() - 1 << '\n';
  for(auto i = s.begin(); i != s.end(); i++){
    auto j = i;
    j++;
    if(j != s.end()) cout << *i << ' ' << *j << '\n';
  }
}