#include <bits/stdc++.h>
#define int long long

using namespace std;

// 不想要區間加值就把 push 全部註解掉就可以了

const int N = 200000 + 9;
int a[N];
int seg[4 * N];
int lazy[4 * N];

inline void pull(int id){ seg[id] = max(seg[id * 2], seg[id * 2 + 1]); }

inline void apply(int id, int l, int r, int v){
    seg[id] += v;
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
    if (r < ql || qr < l) return -4e18;         // 交集為空
    if (ql <= l && r <= qr) return seg[id]; // 完全覆蓋
    push(id, l, r);                         // 下傳 lazy
    int mid = (l + r) / 2;
    return max(query(id * 2, l, mid, ql, qr)    // 左
         , query(id * 2 + 1, mid + 1, r, ql, qr)); // 右
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
    push(id, l, r); // 確保往下的值正確
    int mid = (l + r) / 2;
    if (i <= mid) modify(id * 2, l, mid, i, x);     // 左
    else modify(id * 2 + 1, mid + 1, r, i, x);      // 右
    pull(id);
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> vec(n);
  vector<int> pre(n + 1);
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    if(i == 0) a[i] = num;
    else{
      a[i] = a[i - 1] + num;
    }
    vec[i] = num;
  }

  // for(int i = 0; i < n; i++){
  //   cout << a[i] << ' ';
  // }
  // cout << '\n';

  build(1, 0, n - 1);

  for(int i = 0; i < q; i++){
    int mode;
    cin >> mode;
    if(mode == 2){
      int l, r;
      cin >> l >> r;
      l--; r--;
      int base = 0;
      if(l != 0) base = query(1, 0, n - 1, l - 1, l - 1);
      cout << max(0LL, query(1, 0, n - 1, l, r) - base) << '\n';
    }
    if(mode == 1){
      int id, val;
      cin >> id >> val;
      id--;
      int delta = val - vec[id];
      range_add(1, 0, n - 1, id, n - 1, delta);
      vec[id] += delta;
    }
  }
}