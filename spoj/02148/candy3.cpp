/* ========================================

   * File Name : candy3.cpp

   * Creation Date : 04-01-2016

   * Last Modified : Mon 04 Jan 2016 12:16:58 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.spoj.com/problems/CANDY3/

   * Status : WA, WA, WA, AC

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
  unsigned long long t,n,x;
  cin >> t;
  while (t--) {
    cin >> n;
    unsigned long long sum = 0;
    REP(i,n) {
      cin >> x;
      x %= n;
      sum += x;
      sum %= n;
    }
    cout << ( (n <= 0 || sum != 0) ? "NO" : "YES" );
    if (t > 0) {
      cout << endl;
    }
  }
  return 0;
}
