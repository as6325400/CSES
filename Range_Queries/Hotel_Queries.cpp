#include <bits/stdc++.h>
#define int long long

using namespace std;


template<typename T>
class segment_tree
{
    private:
        
    public:
        template<typename F>
        class node{
            public:
            int lb, rb;
            F num, tag;
            node<F> *left, *right;
            node(){
                tag = 0;
                right = nullptr, left = nullptr;
            }
        };
        node<T> *root;
        node<T> *build(vector<T> &save, int l, int r){
            node<T> *temp = new node<T>; 
            temp -> lb = l;
            temp -> rb = r;
            if (l == r)
            {   
                temp -> num = save[l];
                return temp;
            }
            int mid = (l + r) / 2;
            temp -> left = build(save, l, mid);
            temp -> right = build(save, mid  + 1, r);
            node<T> *left_node, *right_node;
            left_node = temp -> left;
            right_node = temp -> right;
            temp -> num = max(left_node -> num,  right_node -> num);
            return temp;
        }
        void modify_node(int index, T delta, node<T> *t){
            if(t -> lb == t -> rb){
                t -> num -= delta;
                return;
            }
            int mid = (t -> lb + t -> rb) / 2;
            if(index > mid) modify_node(index, delta, t -> right);
            else modify_node(index, delta, t -> left);
            t -> num = max(t -> left -> num, t -> right -> num);
        }
        int dfs(int num, node<int> *n, int depth){
          auto nl = n -> left;
          auto nr = n -> right;
          if(num > n -> num) return 0;
          if(n -> lb == n -> rb) return n -> lb;
          if(nl -> num > num  and nr -> num > num) return dfs(num, nl, depth + 1);
          else if(nl -> num >= num) return dfs(num, nl, depth + 1);
          return dfs(num, nr, depth + 1);
        }
};

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> hotel(n + 1);
  vector<int> group(m + 1);
  for(int i = 1; i <= n; i++){
    cin >> hotel[i];
  }
  for(int i = 1; i <= m; i++){
    cin >> group[i];
  }
  segment_tree<int> s;
  auto root = s.build(hotel, 1, n);
  vector<int> ans(m + 1);
  for(int i = 1; i <= m; i++){
    ans[i] = s.dfs(group[i], root, 0);
    if(ans[i] == 0) continue;
    s.modify_node(ans[i], group[i], root );
  }
  for(int i = 1; i <= m; i++){
    cout << ans[i] << ' ';
  }
}