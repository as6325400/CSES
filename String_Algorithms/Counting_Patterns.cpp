#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> SuffixArray(const string& s) {
  int n = s.size();
  vector<int> suffixArray(n), rank(n), tempRank(n);
  for (int i = 0; i < n; ++i) {
    suffixArray[i] = i;
    rank[i] = s[i];
  }
  for (int k = 1; k < n; k <<= 1) {
    auto compare = [&](int i, int j) {
      if (rank[i] != rank[j])
        return rank[i] < rank[j];
      int ri = (i + k < n) ? rank[i + k] : -1;
      int rj = (j + k < n) ? rank[j + k] : -1;
      return ri < rj;
    };
    sort(suffixArray.begin(), suffixArray.end(), compare);
    tempRank[suffixArray[0]] = 0;
    for (int i = 1; i < n; ++i) {
      tempRank[suffixArray[i]] = tempRank[suffixArray[i - 1]] + compare(suffixArray[i - 1], suffixArray[i]);
    }
    rank = tempRank;
  }
  return suffixArray;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s1;
  cin >> s1;
  auto sa = SuffixArray(s1);
  int q;
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

  // cout << "sa-------\n";
  // for(auto i:sa) cout << i << ' ';
  // cout << '\n';

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
      // cout << mid << ' ' << cmp(str, sa[mid]) << '\n';
      if(cmp(str, sa[mid]) == -1){
        rb = mid;
        r = mid - 1;
      }
      else{
        l = mid + 1;
      }
    }
    // cout << lb << ' ' << rb << '\n';
    cout << rb - lb - 1 << '\n';
  }
}