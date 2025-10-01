#include <bits/stdc++.h>
#define int long long
#define lowbit(x) x & -x

using namespace std;


void modify(vector<int> &bit, int idx, int val) {
	for(int i = idx; i <= bit.size(); i+= lowbit(i))bit[i] += val;
}
 
int query_sum(vector<int> &bit, int idx) {
	int ans = 0;
	for(int i = idx; i > 0; i-= lowbit(i)) ans += bit[i];
	return ans;
}


bool cmp(const tuple<int, int, int> &a, const tuple<int, int, int> &b){
  return get<1>(a) < get<1>(b);
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> vec[i];
  }
  
  vector<int> bit(n + 1);
  
  vector<tuple<int, int, int>> query(q);
  
  for(int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    query[i] = {l, r, i};
  }

  sort(query.begin(), query.end(), cmp);

  map<int, int> mp;
  int r_tag = 0;
  vector<int> ans_v(q);
  
  for(int i = 0; i < q; i++){
    auto [l, r, id] = query[i];
    while(r_tag < r){
      r_tag++;
      // cout << r_tag << '\n';
      if(mp.find(vec[r_tag]) != mp.end()){
        modify(bit, mp[vec[r_tag]], -1);
      }
      mp[vec[r_tag]] = r_tag;
      modify(bit, r_tag, 1);
    }
    // for(int j = 1; j <= n; j++){
    //   cout << query_sum(bit, j) - query_sum(bit, j - 1) << ' ';
    // }
    // cout << '\n';
    ans_v[id] = query_sum(bit, r) - query_sum(bit, l - 1);
  }

  for(int i = 0; i < q; i++){
    cout << ans_v[i] << '\n';
  }


}