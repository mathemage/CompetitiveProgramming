 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 22-11-2020

   * Last Modified : Ne 22. listopadu 2020, 23:22:13

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/1354/A

   * Points Gained (in case of online contest) : AC

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << (a) << endl;

const int CLEAN = -1;

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

long long solve(long long a, long long b, long long c, long long d) {
  long long remain = a - b;
//   MSG(remain);
  if (remain <= 0) {
    return b;
  }

  long long asleep = c - d;
//   MSG(asleep);
  return (asleep <= 0) ? -1 : (b + ((remain + asleep - 1) / asleep) * c);
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << solve(a, b, c, d) << endl;
  }
  return 0;
}
