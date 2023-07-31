#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x, count = 0;
  cin >> n >> x;

  vector<int> save(n);
  for(int i = 0; i < n; i++) cin >> save[i];
  while(!save.empty()){
    // cout << save.size() << '\n';
    vector<int> visit_ans;
    int p = pow(2, save.size()), ans = -1e9;
    // cout << p << '\n';
    for(int i = 0; i < p; i++){
      vector<int> visit(save.size());
      int index = 0, sum = 0, num = i;
      while(num != 0){
        visit[index] = num % 2;
        num /= 2;
        index++;
      }
      for(int j = 0; j < visit.size(); j++){
        if(visit[j]) sum += save[j];
      }
      if(sum > ans and sum <= x){
        cout << "round " << count << ' ' <<"sum " << sum << ' ' << i << '\n';
        visit_ans = visit;
        ans = sum;
      }
    }
    vector<int> temp;
    for(int i = 0; i < visit_ans.size(); i++){
      if(!visit_ans[i]) temp.push_back(save[i]);
      else cout << save[i] << ' ';
    }
    cout << '\n';
    save = temp;
    count++;
    if(save.size() == 0) break;
    if(accumulate(save.begin(), save.end(), (int)0) <= x){
      count++;
      break;
    }
  }
  cout << count;
}