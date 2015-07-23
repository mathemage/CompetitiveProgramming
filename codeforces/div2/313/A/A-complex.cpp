 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 22-07-2015

   * Last Modified : Wed 22 Jul 2015 04:09:33 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL :

   * Points Gained (in case of online contest) :

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
  int top = 1000010;
  vector<bool> payable(top, false);
  payable[0] = true;
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) {
    cin >> a[i];
    payable[a[i]] = true;
  }

  REP(k, top) {
    //ERR(k, top); cout << endl;
    for (auto & x : a) {
      if (k-x >= 0 && payable[k - x]) {
        payable[k] = true;
        break;
      }
    }
    if (!payable[k]) {
      cout << k << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
