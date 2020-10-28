 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 27-10-2020

   * Last Modified : St 28. října 2020, 23:47:33

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/1374/B

   * Points Gained (in case of online contest) : AC (after 2-3 fixes)

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

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int exp_3 = 0;
    while (n % 3 == 0) {
      n /= 3;
      exp_3++;
    }

    int exp_2 = 0;
    while (n % 2 == 0) {
      n /= 2;
      exp_2++;
    }
//     MSG(exp_2) MSG(exp_3) 
    cout << ((n == 1 && exp_2 <= exp_3) ? (exp_3 + exp_3 - exp_2) : -1) << endl;
  }

  return 0;
}
