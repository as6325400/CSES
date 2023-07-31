#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, count = 0;
  cin >> n;
  while(n != 0){
    int max, num = n;
    vector<int> save; 
    while(num != 0){
      save.push_back(num % 10);
      num /= 10;
    }
    sort(save.begin(), save.end());
    n -= save.back();
    count++;
  }
  cout << count << '\n';
}