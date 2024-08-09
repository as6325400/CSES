#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;

int fast_pow(int a, int b, int mod)
{	
	// a^b % mod 
  int res = 1;
  while(b)
  {
    if(b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    cout << fast_pow(a, fast_pow(b, c, mod), mod) << '\n';
  }
}