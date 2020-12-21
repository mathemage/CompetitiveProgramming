 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 21-12-2020

   * Last Modified : Po 21. prosince 2020, 23:39:40

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/1011/A

   * Points Gained (in case of online contest) : AC

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
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  string rocket;
  int r_size = 0;
  int ans = 0;
  sort(ALL(s));
  for (auto & c: s) {
    if (r_size == 0 || c - rocket[r_size - 1] >= 2) {
      rocket.push_back(c);
      ans += c - 'a' + 1;
      if (++r_size >= k) {
        break;
      }
    }
  }

  cout << (r_size == k ? ans : -1);
  return 0;
}
