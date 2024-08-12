#include <bits/stdc++.h>
#define int long long

using namespace std;

struct SuffixArray {
	int n; string s;
	vector<int> sa, rk, lc;
	// n: 字串長度
	// sa: 後綴數組，sa[i] 表示第 i 小的後綴的起始位置
	// rk: 排名數組，rk[i] 表示從位置 i 開始的後綴的排名
	// lc: LCP 數組，lc[i] 表示 sa[i] 和 sa[i + 1] 的最長公共前綴長度
	SuffixArray(const string &s_) {
		s = s_; n = s.length();
		sa.resize(n);
		lc.resize(n - 1);
		rk.resize(n);
		iota(sa.begin(), sa.end(), 0);
		sort(sa.begin(), sa.end(), [&](int a, int b) { return s[a] < s[b]; });
		rk[sa[0]] = 0;
		for (int i = 1; i < n; ++i)
			rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
		int k = 1;
		vector<int> tmp, cnt(n);
		tmp.reserve(n);
		while (rk[sa[n - 1]] < n - 1) {
			tmp.clear();
			for (int i = 0; i < k; ++i)
				tmp.push_back(n - k + i);
			for (auto i : sa)
				if (i >= k)
					tmp.push_back(i - k);
			fill(cnt.begin(), cnt.end(), 0);
			for (int i = 0; i < n; ++i)
				++cnt[rk[i]];
			for (int i = 1; i < n; ++i)
				cnt[i] += cnt[i - 1];
			for (int i = n - 1; i >= 0; --i)
				sa[--cnt[rk[tmp[i]]]] = tmp[i];
			swap(rk, tmp);
			rk[sa[0]] = 0;
			for (int i = 1; i < n; ++i)
				rk[sa[i]] = rk[sa[i - 1]] + (tmp[sa[i - 1]] < tmp[sa[i]] || sa[i - 1] + k == n || tmp[sa[i - 1] + k] < tmp[sa[i] + k]);
			k *= 2;
		}
		for (int i = 0, j = 0; i < n; ++i) {
			if (rk[i] == 0) {
				j = 0;
			} else {
				for (j -= j > 0; i + j < n && sa[rk[i] - 1] + j < n && s[i + j] == s[sa[rk[i] - 1] + j]; )
					++j;
				lc[rk[i] - 1] = j;
			}
		}
	}
};

template<typename T>
class segment_tree
{ 
  // 1-base4
  private:
      
  public:
    template<typename F>
    class node{
      public:
      int lb, rb;
      F num, tag;
      node<F> *left, *right;
      node(){
        tag = 0;
        right = nullptr, left = nullptr;
      }
      T rv(){
        return num + tag * (rb - lb + 1);
      }
      void pull(){
        if(left) left -> tag += tag;
        if(right) right -> tag += tag;
        num = rv();
        tag = 0;
      }
    };
    node<T> *root;
    node<T> *build(vector<T> &save, int l, int r){
      node<T> *temp = new node<T>; 
      temp -> lb = l;
      temp -> rb = r;
      if (l == r)
      {   
        temp -> num = save[l];
        return temp;
      }
      int mid = (l + r) / 2;
      temp -> left = build(save, l, mid);
      temp -> right = build(save, mid  + 1, r);
      node<T> *left_node, *right_node;
      left_node = temp -> left;
      right_node = temp -> right;
      temp -> num = min(left_node -> num, right_node -> num);
      return temp;
    }
    T query(int l, int r, node<T> *t){
      t -> pull();
      if(l == t -> lb and r == t -> rb)
          return t -> num;
      int mid = (t -> lb + t -> rb) / 2;
      if(r <= mid) return query(l, r, t -> left);
      else if(l > mid) return query(l, r, t -> right);
      else return min(query(l, mid, t -> left), query(mid + 1, r, t -> right));
    }
    void modify_node(int index, T delta, node<T> *t){
      if(t -> lb == t -> rb){
        t -> num += delta;
        return;
      }
      int mid = (t -> lb + t -> rb) / 2;
      if(index > mid) modify_node(index, delta, t -> right);
      else modify_node(index, delta, t -> left);
      t -> num += delta;
    }
    void modify_scope(int lb, int rb, int delta, node<T> *t){
      if(t -> lb >= lb and t -> rb <= rb){
        t -> tag += delta;
        return;
      }
      int mid = (t -> lb + t -> rb) / 2;
      if(t -> left and rb <= mid) modify_scope(lb, rb, delta, t -> left);
      else if(t -> right and lb > mid) modify_scope(lb, rb, delta, t -> right);
      else{
        modify_scope(lb, mid, delta, t -> left);
        modify_scope(mid + 1, rb, delta, t -> right);
      }
      if(t -> left and t -> right) t -> num = t -> left -> rv() + t -> right -> rv();
    }
};

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s1;
  cin >> s1;
  auto ss = SuffixArray(s1);
  auto sa = ss.sa;
  int q;
  segment_tree<int> s;
  s.root = s.build(sa, 0, sa.size() - 1);
  cin >> q;

  function<int(string &, int)> cmp = [&](string &str, int idx){
    int len = s1.size() - idx;
    for(int i = 0; i < min((int)str.size(), len); i++){
      if(str[i] != s1[idx + i]){
        if(str[i] > s1[idx + i]) return 1; // str 大
        return -1; // SA 大
      }
    }
    if(len < str.size()) return 1;
    return 0;
  };


  for(int i = 0; i < q; i++){
    string str;
    cin >> str;
    int l = 0, r = sa.size() - 1;
    int lb = -1, rb = sa.size();
    while(l <= r){
      int mid = (l + r) / 2;
      if(cmp(str, sa[mid]) == 1){
        lb = mid;
        l = mid + 1;
      }
      else{
        r = mid - 1;
      }
    }
    l = 0; r = sa.size() - 1;
    while(l <= r){
      int mid = (l + r) / 2;
      if(cmp(str, sa[mid]) == -1){
        rb = mid;
        r = mid - 1;
      }
      else{
        l = mid + 1;
      }
    }
    if(rb - lb - 1 == 0) cout << -1 << '\n';
    else cout << s.query(lb + 1, rb - 1, s.root) + 1 << '\n';
  }
}