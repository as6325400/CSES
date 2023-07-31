#include <bits/stdc++.h>
#define int long long

using namespace std;

bool cmp(pair<int, int > &a, pair<int, int> &b){
  if(a.second == b.second){
    return a.first < b.first;
  }
  return a.second < b.second;
}

int binary_search(vector<pair<int, int>> &p, int x){
  int left = 0, right = x - 1, value = p[x].first;
  while(right >= left){
    int mid = left + (right - left) / 2;
    if(p[mid].second > value){
      right = mid - 1;
    }
    else if(p[mid].second <= value and p[mid + 1].second > value){
      return mid;
    }
    else{
      left = mid + 1;
    }
  }
  return -1;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  vector<int> d(n, -1);
  vector<int> dp(n);
  for(int i = 0; i < n; i++){
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(), p.end(), cmp);

  for(int i = 1; i < n; i++){
    d[i] = binary_search(p, i);
  }
  dp[0] = 1;
  for(int i = 1; i < n; i++){
    if(d[i] == -1) dp[i] = dp[i - 1];
    else dp[i] = max(dp[i - 1], dp[d[i]] + 1);
  }

  cout << dp[n - 1] << '\n';
}