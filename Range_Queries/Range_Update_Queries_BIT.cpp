#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, q;

int lowbit(int idx){ return idx & -idx; }

void modify(int idx, int delta ,vector<int> &a){
  for(; idx <= n; idx += lowbit(idx)){
    a[idx] += delta;
  }
}

int query(int idx, vector<int> &a){
  int ans = 0;
  for(; idx > 0; idx -= lowbit(idx)){
    ans += a[idx];
  }
  return ans;
}

// d[i] = a[i] - a[i - 1]
// a[i] = d[i] + d[i - 1] + ... + d[1]
// a[1 ~ x] = sigma(d[i] * (x - i + 1)) = sigma(d[i] * (x + 1)) - sigma(d[i] * i)
// d1[i] = d[i] * i

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;

  vector<int> d(n + 5), d1(n + 5);

  int pre = 0, nxt = 0;
  for(int i = 1; i <= n; i++){
    cin >> nxt;
    modify(i, nxt - pre, d);
    modify(i, (nxt - pre) * i, d1);
    pre = nxt;
  }

  for(int i = 0; i < q; i++){
    int mode;
    cin >> mode;
    if(mode == 1){
      int l, r, u;
      cin >> l >> r >> u;
      modify(l, u, d);
      modify(r + 1, -u, d);
      modify(l, u * l, d1);
      modify(r + 1, -u * (r + 1), d1);
    }
    else{
      int v;
      cin >> v;
      int r = query(v, d) * (v + 1) - query(v, d1);
      int l = query(v - 1, d) * v - query(v - 1, d1);
      cout << r - l << '\n';
    }
  }


}