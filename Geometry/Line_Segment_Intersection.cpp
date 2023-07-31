#include <bits/stdc++.h>
#define int long long
#define mp make_pair
 
using namespace std;
 
const int mod = 1e9 + 7;
 
 
 
template<typename T>
pair<T, T> operator-(pair<T, T> a, pair<T, T> b){
  return make_pair(a.first - b.first, a.second - b.second);
}
 
template<typename T>
int sign(T num){
  if(num > 0) return 1;
  else if(num < 0) return -1;
  return 0;
}
 
template<typename T>
T cross(pair<T, T> a, pair<T, T> b){
  return (a.first * b.second - a.second * b.first);
}
 
template<typename T> 
T dot(pair<T, T> a, pair<T, T> b){
  return (a.first * b.first + a.second * b.second);
}
 
template<typename T>
bool commonline(pair<T, T> &a, pair<T, T> &b, pair<T, T> &c){
  return cross(b - a, b - c) == 0;
}
 
 
 
template<typename T>
bool inLine(pair<T, T> &a, pair<T, T> &b, pair<T, T> &p){
  return commonline(a, b, p) and dot(a - p, b - p) <= 0;
}
 
template<typename T>
bool intersect(pair<T, T> p1, pair<T, T> p2, pair<T, T> p3, pair<T, T> p4){
  return (sign(cross(p2 - p1, p3 - p1)) * sign(cross(p2 - p1, p4 - p1)) < 0 
  and sign(cross(p4 - p3, p1 - p3)) * sign(cross(p4 - p3, p2 - p3)) < 0)
  or (inLine(p3, p4, p1) or inLine(p3, p4, p2) or inLine(p1, p2, p3) or inLine(p1, p2, p4));
}
 
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    double x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;
    if(intersect(mp(x1, y1), mp(x2, y2), mp(x3, y3), mp(x4, y4))){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
}