#include <bits/stdc++.h>
#define int long long

// 對於查詢建築 k 的最低價
// 若從 a <= k 訂購， cost = p[a] + (k - a) = p[a] - a + k
// 若從 a >= k 訂購， cost = p[a] + (a - k) = p[a] + a - k
// 因此蓋兩顆線段數，建樹跟修改時都跟著增減 a 
// 查詢時一次查詢兩顆 分別是 (0, k) (k, n - 1)

using namespace std;

// 不想要區間加值就把每個函數裡面的 push 都移除
// 最外層呼叫時，每個 id 都傳 1

const int N = 200000 + 9;
int a[N];
int seg[4 * N][2]; // 0 left, 1 right
int lazy[4 * N];

int site;

inline void pull(int id){ 
  seg[id][0] = min(seg[id * 2][0], seg[id * 2 + 1][0]); 
  seg[id][1] = min(seg[id * 2][1], seg[id * 2 + 1][1]); 
}

// inline void apply(int id, int l, int r, int v){
//     seg[id] += v * (r - l + 1);
//     lazy[id] += v;
// }

// inline void push(int id, int l, int r){
//     if (!lazy[id] || l == r) return;
//     int mid = (l + r) / 2;
//     apply(id * 2, l, mid, lazy[id]);
//     apply(id * 2 + 1, mid + 1, r, lazy[id]);
//     lazy[id] = 0;
// }

void build(int id, int l, int r) { // 編號為 id 的節點，存的區間為 [l, r]
    if (l == r) { 
      seg[id][0] = a[l] - l; 
      seg[id][1] = a[l] + l; 
      return; 
    } // 葉節點的值
    int mid = (l + r) / 2;                  // 將區間切成兩半
    build(id * 2, l, mid);                  // 左子節點
    build(id * 2 + 1, mid + 1, r);          // 右子節點
    pull(id);
}

// 區間查詢：回傳 [ql, qr] 的區間和
int query(int id, int l, int r, int ql, int qr, int t) {
    if (r < ql || qr < l) return 4e18;         // 交集為空
    if (ql <= l && r <= qr) return seg[id][t]; // 完全覆蓋
    // push(id, l, r);                         // 下傳 lazy
    int mid = (l + r) / 2;
    return min(query(id * 2, l, mid, ql, qr, t)    // 左
         , query(id * 2 + 1, mid + 1, r, ql, qr, t)); // 右
    // 否則，往左、右進行遞迴
}

// // 區間加值：將 [ql, qr] 每個位置都加上 x
// void range_add(int id, int l, int r, int ql, int qr, int x) {
//     if (r < ql || qr < l) return;           // 交集為空
//     if (ql <= l && r <= qr) { apply(id, l, r, x); return; } // 完全覆蓋
//     push(id, l, r);                         // 下傳 lazy 再往下走
//     int mid = (l + r) / 2;
//     range_add(id * 2, l, mid, ql, qr, x);           // 左
//     range_add(id * 2 + 1, mid + 1, r, ql, qr, x);   // 右
//     pull(id);
// }

// 單點修改 (設值版)：將 a[i] 改成 x
void modify(int id, int l, int r, int i, int x) {
    if (l == r) { 
      seg[id][0] = x - l;
      seg[id][1] = x + l;
      return; 
    }
    // push(id, l, r); // 確保往下的值正確
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
  for(int i = 0; i < n; i++) cin >> a[i];
  build(1, 0, n - 1);
  for(int i = 0; i < q; i++){
    int mode;
    cin >> mode;
    if(mode == 1){
      int pos, val;
      cin >> pos >> val;
      pos--; a[pos] = val;
      modify(1, 0, n - 1, pos, val);
    }
    if(mode == 2){
      int pos;
      cin >> pos;
      pos--;
      cout << min(query(1, 0, n - 1, 0, pos, 0) + pos, query(1, 0, n - 1, pos, n - 1, 1) - pos) << '\n';
    }
  }
}