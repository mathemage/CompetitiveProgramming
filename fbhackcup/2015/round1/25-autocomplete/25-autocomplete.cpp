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
  cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
  err(++it, args...);
}

const int sz = 26;
class Trie {
  int freq;
  Trie* sons[sz];

  public:
  Trie(int f = 0) : freq(f) {
    REP(i,sz) {
      sons[i] = NULL;
    }
  }

  void insert(string w) {
    if (w.empty()) return;

    int id = w[0]-'a';
    if (sons[id] == NULL)
      sons[id] = new Trie;
    sons[id]->freq++;
    sons[id]->insert(w.substr(1));
  }

  int search(string w) {
    if (w.empty()) return 0;

    int id = w[0]-'a';
    if (sons[id]->freq == 1) return 1;
    else return 1 + sons[id]->search(w.substr(1));
  }
};

int main() {
  int t,n;
  cin >> t;

  string w;
  REP(i,t) {
    cout << "Case #" << i+1 << ": ";
    cin >> n;

    int res = 0;
    Trie root;
    REP(i,n) {
      cin >> w;
      root.insert(w);
      res += root.search(w);
    }
    cout << res << endl;
  }
  return 0;
}
