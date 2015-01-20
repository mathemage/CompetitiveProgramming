/* ========================================

   ID: mathema6
   TASK: 25-autocomplete
   LANG: C++11
   (...for USACO solutions)

   * File Name : 25-autocomplete.cpp

   * Creation Date : 17-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/hackercup/problems.php?pid=313229895540583&round=344496159068801

   * Points Gained (in case of online contest) :

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

#define ERR(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c))
    v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
  err(++it, args...);
}

const int sz = 26;
int rec = 0;
struct Trie {
  Trie* sons[sz];
  Trie() {
    REP(i,sz) {
      sons[i] = NULL;
    }
  }

  int update(string & w) {
    Trie *cur = this;
    int res = w.size();
    REP(i,w.size()) {
      int id = w[i]-'a';
      if (cur->sons[id] == NULL) {
        cur->sons[id] = new Trie;
        REP(j,sz)
          cur->sons[id]->sons[j] = NULL;
        res = min(res, i+1);
      }
      cur = cur->sons[id];
    }
    return res;
  }
};

void clean(Trie *root) {
  //ERR(++rec);
  stack<Trie*> st;
  st.push(root);
  Trie *cur;
  while (st.size()) {
    cur = st.top(); st.pop();

    REP(i,sz) {
      if (cur->sons[i]) {
        st.push(cur->sons[i]);
      }
    }
    delete cur;
  }
}

int main() {
  int t,n;
  cin >> t;

  string w;
  REP(i,t) {
    cout << "Case #" << i+1 << ": ";
    cin >> n;

    int res = 0;
    Trie *root = new Trie;
    REP(j,n) {
      cin >> w;
      res += root->update(w);
    }
    cout << res << endl;
    clean(root);
  }
  return 0;
}
