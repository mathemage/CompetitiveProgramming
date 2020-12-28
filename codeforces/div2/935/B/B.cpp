 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 28-12-2020

   * Last Modified : Po 28. prosince 2020, 13:28:00

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/935/B

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
  int n;
  cin >> n;
  string S;
  cin >> S;

  int coins = 0;
  int kingdom = CLEAN;
  pair<int, int> pos = {0, 0};
  for (auto & move : S) {
    switch (move) {
      case 'R':
        pos.first++;
        break;
      case 'U':
        pos.second++;
        break;
    }

    if (pos.second < pos.first) {
      if (kingdom == 2) {
        coins++;
      }
      kingdom = 1;
    } else if (pos.second > pos.first) {
      if (kingdom == 1) {
        coins++;
      }
      kingdom = 2;
    }
  }
  cout << coins << "\n";

  return 0;
}
