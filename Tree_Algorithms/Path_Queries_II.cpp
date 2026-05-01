#include <bits/stdc++.h>
#define int long long

using namespace std;

// 不想要區間加值就把每個函數裡面的 push 都移除
// 最外層呼叫時，每個 id 都傳 1

const int N = 200000 + 9;
int a[N];
int seg[4 * N];
int lazy[4 * N];

inline void pull(int id){ seg[id] = max(seg[id * 2], seg[id * 2 + 1]); }

inline void apply(int id, int l, int r, int v){
    seg[id] += v * (r - l + 1);
    lazy[id] += v;
}

inline void push(int id, int l, int r){
    if (!lazy[id] || l == r) return;
    int mid = (l + r) / 2;
    apply(id * 2, l, mid, lazy[id]);
    apply(id * 2 + 1, mid + 1, r, lazy[id]);
    lazy[id] = 0;
}

void build(int id, int l, int r) { // 編號為 id 的節點，存的區間為 [l, r]
    if (l == r) { seg[id] = a[l]; return; } // 葉節點的值
    int mid = (l + r) / 2;                  // 將區間切成兩半
    build(id * 2, l, mid);                  // 左子節點
    build(id * 2 + 1, mid + 1, r);          // 右子節點
    pull(id);
}

// 區間查詢：回傳 [ql, qr] 的區間和
int query(int id, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;         // 交集為空
    if (ql <= l && r <= qr) return seg[id]; // 完全覆蓋
    // push(id, l, r);                         // 下傳 lazy
    int mid = (l + r) / 2;
    return max(query(id * 2, l, mid, ql, qr)    // 左
          ,query(id * 2 + 1, mid + 1, r, ql, qr)); // 右
    // 否則，往左、右進行遞迴
}

// 區間加值：將 [ql, qr] 每個位置都加上 x
void range_add(int id, int l, int r, int ql, int qr, int x) {
    if (r < ql || qr < l) return;           // 交集為空
    if (ql <= l && r <= qr) { apply(id, l, r, x); return; } // 完全覆蓋
    push(id, l, r);                         // 下傳 lazy 再往下走
    int mid = (l + r) / 2;
    range_add(id * 2, l, mid, ql, qr, x);           // 左
    range_add(id * 2 + 1, mid + 1, r, ql, qr, x);   // 右
    pull(id);
}

// 單點修改 (設值版)：將 a[i] 改成 x
void modify(int id, int l, int r, int i, int x) {
    if (l == r) { seg[id] = x; return; }
    // push(id, l, r); // 確保往下的值正確
    int mid = (l + r) / 2;
    if (i <= mid) modify(id * 2, l, mid, i, x);     // 左
    else modify(id * 2 + 1, mid + 1, r, i, x);      // 右
    pull(id);
}

struct HLD {
    int n, cur;
    vector<int> siz, top, dep, parent, in, out, seq;
    vector<vector<int>> adj;
    HLD(int n) : n(n), cur(0) {
        siz.resize(n); top.resize(n); dep.resize(n);
        parent.resize(n); in.resize(n); out.resize(n);
        seq.resize(n); adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int rt = 0) {
        top[rt] = rt;
        dep[rt] = 0;
        parent[rt] = -1;
        dfs1(rt); dfs2(rt);
    }
    void dfs1(int u) {
        if (parent[u] != -1)
            adj[u].erase(find(adj[u].begin(), adj[u].end(), parent[u]));
        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u, dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                swap(v, adj[u][0]);
            } // 讓 adj[u][0] 是重子節點
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u; // dfn 對應的編號
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    int jump(int u, int k) {
        if (dep[u] < k) return -1;
        int d = dep[u] - k;
        while (dep[top[u]] > d) u = parent[top[u]];
        return seq[in[u] - dep[u] + d];
    }
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    int rootedParent(int rt, int v) {
        if (rt == v) return rt;
        if (!isAncester(v, rt)) return parent[v];
        auto it = upper_bound(adj[v].begin(), adj[v].end(), rt,
            [&](int x, int y) {
                return in[x] < in[y];
            }) - 1;
        return *it;
    }
    int rootedSize(int rt, int v) {
        if (rt == v) return n;
        if (!isAncester(v, rt)) return siz[v];
        return n - siz[rootedParent(rt, v)];
    }
    int rootedLca(int rt, int a, int b) {
        return lca(rt, a) ^ lca(a, b) ^ lca(b, rt);
    }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int> tp(n);
  for (int i = 0; i < n; i++) cin >> tp[i];

  HLD t(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    t.addEdge(u, v);
  }

  t.work(0); // 以 0 (節點1) 為根

  // 將點值依照 dfn 映射到線段樹底層
  for (int i = 0; i < n; i++) {
    ::a[t.in[i]] = tp[i];
  }
  build(1, 0, n - 1); // 根 id = 1

  auto path_max = [&](int u, int v) {
    int res = LLONG_MIN;
    while (t.top[u] != t.top[v]) {
      if (t.dep[t.top[u]] < t.dep[t.top[v]]) swap(u, v);
      res = max(res, query(1, 0, n - 1, t.in[t.top[u]], t.in[u]));
      u = t.parent[t.top[u]];
    }
    int l = t.in[u], r = t.in[v];
    if (l > r) swap(l, r);
    res = max(res, query(1, 0, n - 1, l, r));
    return res;
  };

  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int s, x;
      cin >> s >> x;
      --s;
      modify(1, 0, n - 1, t.in[s], x);
    } else if (mode == 2) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      cout << path_max(a, b) << '\n';
    }
  }
}
