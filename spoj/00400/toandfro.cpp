/* ========================================

   ID: mathema6
   TASK: toandfro
   LANG: C++11
   (...for USACO solutions)

   * File Name : toandfro.cpp

   * Creation Date : 21-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.spoj.com/problems/TOANDFRO/

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

int main() {
  int columns;
  string w;
  while (cin >> columns && columns > 0) {
    cin >> w;
    REP(mod,columns) {
      REP(i,w.size()/columns) {
        cout << w[i*columns + ((i%2) ? columns-mod-1 : mod)];
      }
    }
    cout << endl;
  }
  return 0;
}
