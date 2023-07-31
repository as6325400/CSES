#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int sum = n * (n + 1) / 2;
  if(sum % 2 == 1) cout << "NO" << endl;
  else{
    vector<int> a, b;
    int s_a = 0, s_b = 0;
    for(int i = n; i >= 1; i--){
      if(s_a < s_b){
        a.push_back(i);
        s_a += i;
      }
      else{
        b.push_back(i);
        s_b += i;
      }
    }
    cout << "YES" << endl;
    cout << a.size() << endl;
    for(int i = 0; i < a.size(); i++){
      cout << a[i] << ' ';
    }
    cout << endl;
    cout << b.size() << endl;
    for(int i = 0; i < b.size(); i++){
      cout << b[i] << ' ';
    }
  }
}