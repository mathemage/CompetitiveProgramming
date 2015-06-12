 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 12-06-2015

   * Last Modified : Fri 12 Jun 2015 05:39:11 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/problemset/problem/122/A

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

bool is_lucky(int d) {
  for (auto & x : NumberToString(d)) {
    if (x != '4' && x != '7')
      return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  FOR(d,4,n+1) {
    if ( (n % d == 0) && is_lucky(d) ) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";
  return 0;
}
