/* ========================================

   * File Name : C.cpp

   * Creation Date : 14-02-2015

   * Last Modified : Sat 14 Feb 2015 07:55:02 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/514/problem/C

   * Points Gained (in case of online contest) : unsubmitted

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << endl;
  err(++it, args...);
}

struct Trie {
  Trie *s[3];
  bool tail;
};

void insert(Trie *root, string w) {
  Trie *cur = root;
  int i;
  //ERR(w);
  for (auto & x : w) {
    i = x-'a';
    //ERR(cur, x);
    if (NULL == cur->s[i]) {
      cur->s[i] = new Trie;
      cur->s[i]->tail = false;
      REP(j,3) cur->s[i]->s[j] = NULL;
    }
    cur = cur->s[i];
  }
  cur->tail = true;
}

bool find(Trie *root, string w) {
  Trie *cur = root;
  int i;
  for (auto & x : w) {
    i = x-'a';
    if (!cur->s[i]) return false;
    cur = cur->s[i];
  }
  if (cur->tail) return true;
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;

  Trie *tr = new Trie;
  REP(j,3) tr->s[j] = NULL;
  tr->tail = false;
  string w;
  REP(i,n) {
    cin >> w;
    insert(tr, w);
  }

  REP(j,m) {
    cin >> w;
    bool yes = false;
    REP(k,w.size()) {
      ERR(k)
      char c = w[k];
      REP(x,3) {
        if (x+'a' != c) {
          w[k] = x + 'a';
          ERR(x+'a', w);
          if (find(tr,w)) {
            cout << "YES";
            yes = true;
            break;
          }
        }
      }
      ERR(yes);
      if (yes) break;
      w[k] = c;
    }
    if (!yes) cout << "NO";
  }
  return 0;
}
