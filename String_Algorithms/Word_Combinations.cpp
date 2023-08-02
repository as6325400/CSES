#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;
vector<int> dp;

class trie{
  public:
    class node{
      public:
        int count;
        vector<trie::node*> child;
        node(){
          child.resize(26, nullptr);
          count = 0;
        }
    };
    node* root;
    trie(){
      root = new node;
    }
    void insert(string s){
      auto temp = root;
      for(int i = 0; i < s.size(); i++){
        if(!temp -> child[s[i] - 'a']) temp -> child[s[i] - 'a'] = new node;
        temp = temp -> child[s[i] - 'a'];
      }
      temp -> count++;
    }
    void search(string &s, int start, int end){
      auto temp = root;
      for(int i = start; i < end; i++){
        temp = temp -> child[s[i] - 'a'];
        if(!temp) break;
        if(temp -> count){
          dp[start] += dp[i + 1];
          dp[start] %= mod;
        }
      }
    }
};



signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  trie t;
  cin >> s;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    string pattern;
    cin >> pattern;
    t.insert(pattern);
  }

  dp.resize(s.size() + 1, 0);
  dp.back() = 1;
  for(int i = s.size() - 1; i >= 0; i--){
    t.search(s, i, s.size());
  }
  cout << dp[0] << '\n';
}