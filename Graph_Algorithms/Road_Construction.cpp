#include <bits/stdc++.h>
#define int long long

using namespace std;

class dsu{
    vector<int> parent;
    vector<int> size;
  public:
    int max_size = 1;
    dsu(int n){
      parent.resize(n);
      size.resize(n);
      for(int i = 0; i < n; i++){
        size[i] = 1;
        parent[i] = i;
      }
    }
    int find_root(int n){
      if(parent[n] == n) return n;
      return parent[n] = find_root(parent[n]);
    }
    bool same(int a, int b){
      return find_root(a) == find_root(b);
    }
    void merge(int a, int b){
      if(find_root(a) == find_root(b)) return;
      int p1 = find_root(a), p2 = find_root(b);
      parent[p1] = p2;
      size[p2] += size[p1];
      max_size = max(max_size, size[p2]);
    }
};

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  dsu d(n + 1);
  int num = n;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    if(!d.same(a, b)) --num;
    cout << num << ' ';
    d.merge(a, b);
    cout << d.max_size << '\n';
  }
}