 
/* ========================================

   * File Name : C.cpp

   * Creation Date : 24-06-2015

   * Last Modified : Thu 25 Jun 2015 03:51:21 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/554/problem/C

   * Points Gained (in case of online contest) : 0 / 1500, WA-WA

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

const unsigned long long MOD = 1000000007;
long long combin(int n, int k) {
  k = min(k, n-k);
  unsigned long long res = 1;
  for (unsigned long long i = 1; i <= k; i++) {
    res *= n--;
    res /= i;
  }
  res %= MOD;
  return res;
}

int main() {
  cout << "c: " << combin(500,50) << endl;
  int k;
  cin >> k;
  vector<int> c(k);
  long long res = 1;
  int width = 0;
  REP(i,k) {
    cin >> c[i];
    unsigned long long nx = combin(width+c[i]-1, c[i]-1);
    res *= (nx % MOD);
    res %= MOD;
    width += c[i];
  }
  cout << res << endl;
  return 0;
}
