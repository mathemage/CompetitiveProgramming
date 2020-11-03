 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 02-11-2020

   * Last Modified : Út 3. listopadu 2020, 00:21:37

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/1337/B

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

bool defeatable(int h, int n, int m) {
//   MSG(n) MSG(m)
  while ((h/2 + 10 < h) && n--) {
    h /= 2;
    h += 10;
//     MSG(h);
  }
//   MSG(m * 10);
  h -= m * 10;
  return h <= 0;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int x, n, m;
    cin >> x >> n >> m;

    cout << (defeatable(x, n, m) ? "YES" : "NO") << endl;
  }
  return 0;
}
