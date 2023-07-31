#include <bits/stdc++.h>
#define int long long

using namespace std;


template<typename T>
class point{
    public:
    T x;
    T y;
    point(){}
    point(T x, T y){
        this -> x = x;
        this -> y = y;
    }
    point<T>& operator+(const point<T> &a);
    point<T>& operator-(const point<T> &a);
    point<T>& operator/(const point<T> &a);
    point<T>& operator/(T a);
    point<T>& operator*(const T &a);
};

template<typename T>
point<T>& point<T>::operator+(const point<T> &a){
    auto temp = new point<T>;
    temp -> x = a.x + this -> x;
    temp -> y = a.y + this -> y;
    return *temp;
}

template<typename T>
point<T>& point<T>::operator-(const point<T> &a){
    auto temp = new point<T>;
    temp -> x = this -> x - a.x;
    temp -> y = this -> y - a.y;
    return *temp;
}

template<typename T>
point<T>& point<T>::operator/(const point<T> &a){
    auto temp = new point<T>;
    temp -> x = this -> x / a.x;
    temp -> y = this -> y / a.y;
    return *temp;
}

template<typename T>
point<T>& point<T>::operator/(T a){
    auto temp = new point<T>;
    temp -> x = this -> x / a;
    temp -> y = this -> y / a;
    return *temp;
}

template<typename T>
point<T>& point<T>::operator*(const T &a){
    auto temp = new point<T>;
    temp -> x = this -> x * a;
    temp -> y = this -> y * a;
    return *temp;
}

template<typename T>
T dot(const point<T> &a,const point<T> &b){
    auto temp = new T;
    *temp = a.x * b.x + a.y * b.y;
    return *temp;
}

template<typename T>
T cross(const point<T> &a,const point<T> &b){
    auto temp = new T;
    *temp = a.x * b.y - a.y * b.x;
    return *temp;
}

template<typename T>
T abs2(const point<T> &a){
    auto temp = new T;
    *temp = a.x * a.x + a.y * a.y;
    return *temp;
}

template<typename T>
bool collinearity(point<T> p1, point<T> p2, point<T> p3){
    //檢查三點是否共線
    return cross(p2 - p1, p2 - p3) == 0;
}

template<typename T>
bool inLine(point<T> a, point<T> b, point<T> p){
    //檢查 p 點是否在ab線段
    return collinearity(a, b, p) && dot(a - p, b - p) <= 0;
}

template<typename T>
int intersect(point<T> a, point<T> b, point<T> c, point<T> d){
    //ab線段跟cd線段是否相交
    if(cross(b - a, c - a) * 
        cross(b - a, d - a) < 0 && 
        cross(d - c, a - c) * 
        cross(d - c, b - c) < 0 || inLine(a, b, c) || 
        inLine(a, b, d) || inLine(c, d, a) 
        || inLine(c, d, b)) return 1;
    return 0;
}

template<typename T>
point<T> intersection(point<T> a, point<T> b, point<T> c, point<T> d){
    //ab線段跟cd線段相交的點
    assert(intersect(a, b, c, d));
    return a + (b - a) * cross(a - c, d - c) / cross(d - c, b - a);
}

// template<typename T>
// int inPolygon(vector<point<T>> polygon, point<T> p){
//     //判斷點p是否在多邊形polygon裡，vector裡的點要連續填對 
//     for(int i = 0; i < polygon.size(); i++){
//       auto temp = cross(p - polygon[i], polygon[(i + 1 + polygon.size()) % polygon.size()] - polygon[i]) * cross(p - polygon[i], polygon[(i - 1 + polygon.size()) % polygon.size()] - polygon[i]);
//       if(temp > 0){
//         cout << i << '\n';
//         return 0;
//       }
//       else if(temp == 0) return 1;
//     }
//     return 2;
// }

template<typename T>
T triangleArea(point<T> a, point<T> b, point<T> c){
    //三角形頂點，求面積
    return abs(cross(b - a, c - a)) / 2;
}

template<typename T,typename F,typename S>
long double triangleArea_Herons_formula(T a, F b, S c){
    //三角形頂點，求面積(給邊長)
    auto p = (a + b + c)/2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

template<typename T>
T area(vector<point<T>> &p){
    //多邊形頂點，求面積
    T ans = 0;
    for(int i = 0; i < p.size(); i++)
        ans += cross(p[i], p[(i + 1) % p.size()]);
    return ans  > 0 ? ans  : -ans ;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<point<double>> polygom(n);
  vector<point<double>> point_set(m);
  for(int i = 0; i < n; i++){
    cin >> polygom[i].x >> polygom[i].y;
  }
  for(int i = 0; i < m; i++){
    cin >> point_set[i].x >> point_set[i].y;
    int count = 0, flag = 0, count2 = 0;
    for(int j = 0; j < n; j++){
      if(inLine(polygom[j], polygom[(j + 1 + n) % n], point_set[i])){
        cout << "BOUNDARY\n";
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      auto p2 = point_set[i] + point<double>(1, 2e9 + 7);
      for(int j = 0; j < n; j++){
        count += intersect(polygom[j], polygom[(j + 1 + n) % n], point_set[i], p2);
      }
      if(count % 2 == 0) cout << "OUTSIDE\n";
      else cout << "INSIDE\n";
    }
  }
}