/* ========================================

   * File Name : B.cpp

   * Creation Date : 17-02-2015

   * Last Modified : Tue 17 Feb 2015 09:35:46 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/515/problem/B

   * Points Gained (in case of online contest) : -1, failed systests

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
  int n,m,b,g,z,i,j;
  cin >> n >> m;

  cin >> b;
  vector<bool> x(n,false);
  REP(i,b) {
    cin >> z;
    x[z] = true;
  }

  cin >> g;
  vector<bool> y(m,false);
  REP(i,g) {
    cin >> z;
    y[z] = true;
  }

  bool bx, by;
  int countdown = n*m/__gcd(n,m);
  int k = 0;
  while (countdown--) {
    i = k%n;
    j = k%m;
    bx = x[i];
    by = y[j];
    y[j] = x[i] = bx || by;
    if (bx != x[i]) {
      b++;
      countdown = n*m/__gcd(n,m);
    }
    if (by != y[j]) {
      g++;
      countdown = n*m/__gcd(n,m);
    }

    k++;
    //ERR(b,g,k)
    if (b == n && g == m) {
      cout << "Yes\n";
      return 0;
    }
  }

  cout << "No";
  return 0;
}
