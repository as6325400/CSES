#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, q;
int a[200005];

int lowbit(int n){ return n & -n; }

void modify(int idx, int delta){
  for(; idx <= n; idx += lowbit(idx)){
    a[idx] += delta;
  }
}

int query(int idx){
  int ans = 0;
  for(; idx > 0; idx -= lowbit(idx)){
    ans += a[idx];
  }
  return ans;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n >> q;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> vec[i];
    modify(i, vec[i]);
  }

  for(int i = 0; i < q; i++){
    int mode;
    cin >> mode;
    if(mode == 1){
      int k, u;
      cin >> k >> u;
      int delta = u - vec[k];
      vec[k] = u;
      modify(k, delta);
    }
    else{
      int l, r;
      cin >> l >> r;
      cout << query(r) - query(l - 1) << '\n';
    }
  }

}