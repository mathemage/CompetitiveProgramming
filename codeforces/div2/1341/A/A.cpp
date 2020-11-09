 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 09-11-2020

   * Last Modified : Po 9. listopadu 2020, 00:31:05

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/1341/A

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

int main() {
  int t;
  cin >> t;

  while (t--) {
//     cout << endl; MSG(t);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    int l1 = n * (a - b), u1 = n * (a + b);
    int l2 = c - d, u2 = c + d;
//     MSG(l1) MSG(u1)
//     MSG(l2) MSG(u2)

    cout << (l1 <= u2 && l2 <= u1 ? "Yes" : "No") << endl;
  }
  return 0;
}
