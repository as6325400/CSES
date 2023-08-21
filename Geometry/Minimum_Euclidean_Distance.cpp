#include <bits/stdc++.h>
#define int long long

using namespace std;

template<typename T>
class point{
  public:
    T x;
    T y;
    point(){}
    point(T _x, T _y):x(_x), y(_y){
    }
    bool operator<(const point<T> &a) const;
    point<T> converx() const{
      return point<T>(y, x);
    }
};


template<typename T>
bool point<T>::operator<(const point<T>& other) const {
    return (x < other.x) || (x == other.x && y < other.y);
}

int dis(const point<int> &a, const point<int> &b){
  int x = a.x - b.x;
  int y = a.y - b.y;
  return x * x + y * y;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<point<int>> p(n);
  for(int i = 0; i < n; i++){
    cin >> p[i].x >> p[i].y;
  }
  int l = 0, ans = (2e9 + 5) * (2e9 + 5) * 2;
  sort(p.begin(), p.end());
  set<point<int>> s;
  s.insert(p[0].converx());
  for(int i = 1; i < n; i++){
    while(l < i and p[l].x < p[i].x - ans){
      s.erase(p[l].converx());
      l++;
    }
    auto start = s.lower_bound(point<int>(p[i].y - ans, 0));
    auto end = s.upper_bound(point<int>(p[i].y + ans, 0));
    for(auto it = start; it != end; it++){
      ans = min(ans, dis(p[i], it -> converx()));
    }
    s.insert(p[i].converx());
  }
  cout << ans << '\n';
}