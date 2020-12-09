 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 08-12-2020

   * Last Modified : St 9. prosince 2020, 20:23:38

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/807/A

   * Points Gained (in case of online contest) : WA (#6) - WA (#6) - AC - AC

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cerr << #a << " == " << (a) << endl;

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
  int n;
  cin >> n;

  int r_before, r_after;
  int prev_r = INT_MAX;
  string result = "maybe";
  while (n--) {
//     MSG(n); cerr << endl;
    cin >> r_before >> r_after;
//     MSG(r_before); MSG(r_after); 

    if (r_before != r_after) {
      cout << "rated";
      return 0;
    }

    if (r_before > prev_r) {
      result = "unrated";
    }
    prev_r = r_before;
//     MSG(result); cerr << endl; cerr << endl;
  }

  cout << result;
  return 0;
}
