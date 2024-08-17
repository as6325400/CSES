#include <bits/stdc++.h>
#define int long long

using namespace std;

struct SuffixArray {
	int n; string s;
	vector<int> sa, rk, lc;
  // 想法 : 排序過了，因此前綴長得像的會距離很近在差不多位置
	// n: 字串長度
	// sa: 後綴數組，sa[i] 表示第 i 小的後綴的起始位置
	// rk: 排名數組，rk[i] 表示從位置 i 開始的後綴的排名
	// lc: LCP 數組，lc[i] 表示 sa[i] 和 sa[i + 1] 的最長公共前綴長度
  // 求 sa[i] 跟 sa[j] 的 LCP 長度 當 i < j : min(lc[i] ...... lc[j - 1])
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

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int len = s.size();
  s.push_back('$');
  for(int i = len - 1; i >= 0; i--) s.push_back(s[i]);
  auto sa = SuffixArray(s);
  function<bool(int)> is_ori = [&](int n){
    if(n < len) return true;
    return false;
  };
  int ans = -1, idx = -1;
  for(int i = 0; i < sa.lc.size(); i++){
    int s1 = sa.sa[i];
    int s2 = sa.sa[i + 1];
    if(is_ori(s1) != is_ori(s2) and sa.lc[i] > ans){
      idx = min(s1, s2);
      ans = sa.lc[i];
    }
  }
  for(int i = idx; i < idx + ans; i++){
    cout << s[i];
  }
  cout << '\n';
}