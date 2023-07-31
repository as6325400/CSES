#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  set<int> s;
  int n;
  cin >> n;
  vector<int> save(n);
  for(int i = 0; i < n; i++) cin >> save[i];
  sort(save.begin(), save.end());
  for(int i = 0; i < n; i++){
    // cin >> save[i];
    vector<int> temp;
    temp.push_back(save[i]);
    for(auto &j:s){
      temp.push_back(j + save[i]);
    }
    for(int j = 0; j < temp.size(); j++){
      s.insert(temp[j]);
    }
    // cout << "i " << i << '\n';
    // for(auto j:s){
    //   cout << j << ' ';
    // }
    // cout << '\n';
  }
  cout << s.size() << '\n';
  for(auto i: s){
    cout << i << ' ';
  }


}