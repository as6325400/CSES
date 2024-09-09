#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{ 
  int n;
  int base = 9, cnt = 1, num = 0;
  cin >> n;
  while(n - base * cnt >= 0){
    n -= (base * cnt);
    num += base;
    base *= 10;
    cnt++;
  }
  // 最終答案會在 num 這個數字上
  num += (((n + (cnt - 1)) / cnt));
  int e = n % cnt;
  if(e == 0) e = cnt;
  for(int i = 0; i < (cnt - e); i++) num /= 10;
  cout << num % 10 << '\n';
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}