 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 25-11-2020

   * Last Modified : St 25. listopadu 2020, 00:13:43

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/977/B

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
  int n;
  cin >> n;

  string s;
  cin >> s;

  unordered_map<string, int> counts;
  int max_cnt = 0;
  REP(i,n-1) {
    max_cnt = max(max_cnt, ++counts[s.substr(i, 2)]);
//     MSG(counts[s.substr(i, 2)]);
//     MSG(max_cnt);
  }

  for (auto & g: counts) {
    if (g.second == max_cnt) {
      cout << g.first;
      break;
    }
  }

  return 0;
}
