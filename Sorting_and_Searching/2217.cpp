#include <bits/stdc++.h>
#define int long long

using namespace std;

int count(vector<int> &save, int id1,int id2){
  int ans = 0, n = save.size();
  if(id1 == 0 and save[id1] > save[id1 + 1]) ans++;
  if(id2 == 0 and save[id2] > save[id2 + 1]) ans++;
  if(id1 == n - 1 and save[id1] < save[id1 - 1]) ans++;
  if(id2 == n - 1 and save[id2] < save[id2 - 1]) ans++;
  if(id2 != 0 and id2 != n - 1){
    if(save[id2] < save[id2 - 1]) ans++;
    if(save[id2] > save[id2 + 1]) ans++;
  }
  if(id1 != 0 and id1 != n - 1){
    if(save[id1] < save[id1 - 1]) ans++;
    if(save[id1] > save[id1 + 1]) ans++;
  }
  return ans;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, ans = 0;
  cin >> n >> m;
  vector<int> origin(n);
  vector<int> save(n);
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    origin[i] = x;
    save[x - 1] = i;
  }

  for(int i = 1; i < n; i++){
    if(save[i] < save[i - 1]) ans++;
  }
  ans++;

  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    x--, y--;
    int id1 = origin[x] - 1, id2 = origin[y] - 1;
    int temp = count(save, id1, id2);
    swap(save[id1], save[id2]);
    swap(origin[x], origin[y]);
    temp -= count(save, id1, id2);
    ans += temp;
    cout << ans << '\n';
  }
}