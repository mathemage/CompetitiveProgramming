/* ========================================

   * File Name : B1.cpp

   * Creation Date : 07-02-2015

   * Last Modified : Sat 07 Feb 2015 09:26:27 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/513/problem/B1

   * Points Gained (in case of online contest) : 3 pts, AC

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
  int n, m, f, val = 0;

  cin >> n >> m;
  int *base = new int[n];
  REP(i,n) base[i] = i+1;
  do {
    f = 0;
    REP(i,n) FOR(j,i,n) {
      f += *min_element(base+i, base+j+1);
    }
    val = max(val, f);
  } while (next_permutation(base, base+n));

  REP(i,n) base[i] = i+1;
  do {
    f = 0;
    REP(i,n) FOR(j,i,n) {
      f += *min_element(base+i, base+j+1);
    }
    if (f == val && --m <= 0) {
      REP(i,n) {
        cout << base[i] << " ";
      }
      break;
    }
  } while (next_permutation(base, base+n));

  delete [] base;
  return 0;
}
