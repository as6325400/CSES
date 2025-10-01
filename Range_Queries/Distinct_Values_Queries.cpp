#include <bits/stdc++.h>
#define int long long

using namespace std;

int ans = 0;
int n, q, k, l = 0, r = 0;
const int N = 2e5 + 5;
int cnt[N], a[N];
vector<int> v;

int id(int val){
  return lower_bound(v.begin(), v.end(), val) - v.begin();
}

vector<int> unique(vector<int> &v){
  vector<int> ans;
  for(int i = 0; i < n; i++){
    if(ans.empty() || ans.back() != v[i]){
      ans.push_back(v[i]);
    }
  }
  return ans;
}

void add(int x){
  if(cnt[x] == 0) ans++;
  cnt[x]++;
}

void del(int x){
  cnt[x]--;
  if(cnt[x] == 0) ans--;
}


signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  
  for(int i = 0; i < n; i++){
    cin >> a[i];
    v.push_back(a[i]);
  }

  sort(v.begin(), v.end());
  v = unique(v);

  for(int i = 0; i < n; i++){
    a[i] = id(a[i]);
  }

  k = sqrt(n);
  vector<int> ans_v(q);
  vector<tuple<int, int, int, int>> vec(q);

  for(int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    vec[i] = {l / k, r, l, i};
  }

  sort(vec.begin(), vec.end());

  add(a[0]);

  for(int i = 0; i < q; i++){
    auto [_, rp, lp, id] = vec[i];
    lp--; rp--;
    while(l > lp) add(a[--l]);
    while(l < lp) del(a[l++]); 
    while(r < rp) add(a[++r]);
    while(r > rp) del(a[r--]);
    ans_v[id] = ans;
  }

  for(int i = 0; i < q; i++){
    cout << ans_v[i] << '\n';
  }
}