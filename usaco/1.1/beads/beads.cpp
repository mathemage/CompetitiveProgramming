/* ========================================

   ID: mathema6
   TASK: beads
   LANG: C++11
   (...for USACO solutions)

   * File Name : beads.cpp

   * Creation Date : 16-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL :

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

int main() {
  ifstream fin("beads.in");
  ofstream fout("beads.out");
  int n;
  fin >> n;
  string w;
  fin >> w;

  int ma = 0;
  REP(i,n) {
    int s = i, t = 0;
    char col = w[s];
    while ((w[s] == col || w[s] == 'w') && t < n) {
      t++;
      s = (n + s-1) % n;
      if (col == 'w')
        col = w[s];
    }

    s = (i+1)%n;
    if (t < n) {
      col = w[s];
      while ((w[s] == col || w[s] == 'w') && t < n) {
        t++;
        s = (s+1)%n;
        if (col == 'w')
          col = w[s];
      }
    }
    ma = max(ma, t);
  }

  fout << ma << endl;
  return 0;
}
