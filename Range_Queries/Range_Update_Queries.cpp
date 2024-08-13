#include <bits/stdc++.h>
#define int long long

using namespace std;


// 要改最大或者最小值線段樹需改 build 跟 queryRange
template<typename T>
class segment_tree {
private:
  vector<T> tree, lazy;
  int size;
  void build(vector<T> &save, int node, int start, int end) {
    if (start == end) tree[node] = save[start];
    else {
      int mid = (start + end) / 2;
      build(save, 2 * node, start, mid);
      build(save, 2 * node + 1, mid + 1, end);
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }
  void updateRange(int node, int start, int end, int l, int r, T delta) {
    if (lazy[node] != 0) {
      tree[node] += (end - start + 1) * lazy[node];
      if (start != end) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (start > end or start > r or end < l) return;
    if (start >= l and end <= r) {
      tree[node] += (end - start + 1) * delta;
      if (start != end) {
        lazy[2 * node] += delta;
        lazy[2 * node + 1] += delta;
      }
      return;
    }
    int mid = (start + end) / 2;
    updateRange(2 * node, start, mid, l, r, delta);
    updateRange(2 * node + 1, mid + 1, end, l, r, delta);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
  T queryRange(int node, int start, int end, int l, int r) {
    if (lazy[node] != 0) {
      tree[node] += (end - start + 1) * lazy[node];
      if (start != end) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (start > end or start > r or end < l){
      // return numeric_limits<T>::max(); // 找區間最小值用這行
      // return numeric_limits<T>::min(); // 找區間最大值用這行
      return 0; // 區間和
    }
    if (start >= l and end <= r) return tree[node];
    int mid = (start + end) / 2;
    T p1 = queryRange(2 * node, start, mid, l, r);
    T p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
  }
  void updateNode(int node, int start, int end, int idx, T delta) {
    if (start == end) tree[node] += delta;
    else {
      int mid = (start + end) / 2;
      if (start <= idx and idx <= mid) updateNode(2 * node, start, mid, idx, delta);
      else updateNode(2 * node + 1, mid + 1, end, idx, delta);
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }

public:
  void build(vector<T> &save, int l, int r) {
    int n = size = save.size();
    tree.resize(4 * n);
    lazy.resize(4 * n);
    build(save, 1, l, r);
  }
  void modify_scope(int l, int r, T delta) {
    updateRange(1, 0, size - 1, l, r, delta);
  }
  void modify_node(int idx, T delta) {
    updateNode(1, 0, size - 1, idx, delta);
  }
  T query(int l, int r) {
    return queryRange(1, 0, size - 1, l, r);
  }
};

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> save(n, 0);
  for(int i = 0; i < n; i++){
    cin >> save[i];
  }
  segment_tree<int> s;
  s.build(save, 0, n - 1);
  for(int i = 0; i < q; i++){
    int m, a, b;
    cin >> m;
    if(m == 1){
      int a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      s.modify_scope(a, b, c);
    }
    else{
      int index;
      cin >> index;
      index--;
      cout << s.query(index, index) << '\n';
    }
  }
}