#include <bits/stdc++.h>
#define int long long

using namespace std;

template<typename T> 
T dot(pair<T, T> a, pair<T, T> b){
  return a.first * b.first + b.second * a.second;
}

pair<double, double> f(pair<double, double> a){
  if(a.second > 0){
    if(a.first > 0) return {a.second, -a.first};
    return {a.second, -a.first};
  }
  if(a.first > 0) return {a.second, -a.first};
  return {a.second, -a.first};
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    double x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    auto temp = f({x2 - x1, y2 - y1});
    pair<double, double> t2 = {x3 - x1, y3 - y1 };
    auto ans = dot(t2, temp);
    if(ans > 0){
      cout << "RIGHT\n";
    }
    else if(ans < 0){
      cout << "LEFT\n";
    }
    else{
      cout << "TOUCH\n";
    }

  }
}