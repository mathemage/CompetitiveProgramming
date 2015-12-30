/* ========================================

   * File Name : B.cpp

   * Creation Date : 30-12-2015

   * Last Modified : Wed 30 Dec 2015 08:42:12 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/611/problem/B

   * Points Gained (in case of online contest) : 536 / 750 (WA-AC)

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

int count(unsigned long long n) {
  int res = 0, digits = 0;
  vector<int> zero_pos;
  while (n) {
    if (n % 2 == 0) {
      zero_pos.emplace_back(digits);
    }
    n /= 2;
    digits++;
  }

  if (zero_pos.size() == 1) {
    res += max(0, digits - zero_pos.back() - 1);
  } else if (zero_pos.size() == 0) {
    res += max(0,digits - 1);
  } else {
    res += max(0, digits - zero_pos.back() - 2);
  }

  for (int i = 2; i < digits; i++) {
    res += i-1;
  }
  return res;
}

int main() {
  unsigned long long a, b;
  cin >> a >> b;

  cout << count(b) - count(a-1) << endl;
  return 0;
}
