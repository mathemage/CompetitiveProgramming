/* ========================================

   * File Name : C.cpp

   * Creation Date : 14-02-2015

   * Last Modified : Sat 14 Feb 2015 09:43:20 PM CET

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

int main() {
  int n, m;
  cin >> n >> m;

  unordered_set<string> ds;
  string w;
  REP(i,n) {
    cin >> w;
    ds.insert(w);
  }

  REP(j,m) {
    cin >> w;
    bool yes = false;
    REP(k,w.size()) {
      char c = w[k];
      REP(x,3) {
        if (x+'a' != c) {
          w[k] = x + 'a';
          if (ds.find(w) != ds.end()) {
            cout << "YES";
            yes = true;
            break;
          }
        }
      }
      if (yes) break;
      w[k] = c;
    }
    if (!yes) cout << "NO";
    cout << endl;
  }
  return 0;
}
