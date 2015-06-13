 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 12-06-2015

   * Last Modified : Sat 13 Jun 2015 04:28:21 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/551/problem/B

   * Points Gained (in case of online contest) : 805/1250 (AC)

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
template <typename T>
string NumberToString ( T Number ) {
  ostringstream ss;
  ss << Number;
  return ss.str();
}

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
  string a,b,c;
  cin >> a >> b >> c;

  vector<int> na(26,0);
  vector<int> nb(26,0);
  vector<int> nc(26,0);
  for (auto & x : a) {
    na[x-'a']++;
  }
  for (auto & x : b) {
    nb[x-'a']++;
  }
  for (auto & x : c) {
    nc[x-'a']++;
  }

  int mf = 0, nf = 0;
  bool doomsday = false;
  REP(m,*max_element(ALL(na))) {
    int n = 100000;
    REP(l,26) {
      if (na[l] < m * nb[l]) {
        doomsday = true;
        break;
      }

      if (nc[l]) {
        int k = (na[l] - m * nb[l]) / nc[l];
        n = min(n, k);
      }
    }

    if (doomsday) {
      break;
    }
    if (m + n > mf + nf) {
      mf = m;
      nf = n;
    }
  }

  REP(i,mf) {
    cout << b;
  }

  REP(i,nf) {
    cout << c;
  }

  REP(l,26) {
    REP(i, na[l] - mf * nb[l] - nf * nc[l]) {
      cout << char('a'+l);
    }
  }

  return 0;
}
