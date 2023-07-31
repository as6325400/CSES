#include <bits/stdc++.h>
#define int long long

using namespace std;

int binary_search(vector<int> &save, int r, int x){
  int left = 0, right = r - 1;
  while(right >= left){
    int mid = left + (right - left) / 2;
    if(save[mid] < x){
      left = mid + 1;
    }
    else if(save[mid] > x){
      right = mid - 1;
    }
    else{
      return mid;
    }
  }
  return -1;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> save(n);
  map<int, vector<int>> mp;
  for(int i = 0; i < n; i++){
    cin >> save[i];
    mp[save[i]].push_back(i);
  }
  sort(save.begin(), save.end());

  for(int i = n -1; i >= 0; i--){
    int x = binary_search(save, i, m - save[i]);
    if(x != -1){
      if(save[i] == save[x]){
        cout << mp[save[i]][0] + 1 << ' ' << mp[save[i]][1] + 1 << '\n';
      }
      else cout << mp[save[i]][0] + 1 << ' ' << mp[save[x]][0] + 1 << '\n';
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << '\n';
  return 0;
}