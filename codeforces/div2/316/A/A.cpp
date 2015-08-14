 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 13-08-2015

   * Last Modified : Fri 14 Aug 2015 01:31:56 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/570/problem/A

   * Points Gained (in case of online contest) : 458 / 500

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

int main() {
  int n, m;
  cin >> n >> m;
  int x;
  vector<int> cities_max(m,0);
  vector<int> cities_victors(m,0);
  REP(i,m) {
    REP(j,n) {
      cin >> x;
      if (x > cities_max[i]) {
        cities_max[i] = x;
        cities_victors[i] = j;
      }
    }
  }

  vector<int> cand_cnt(n,0);
  REP(i,m) {
    cand_cnt[cities_victors[i]]++;
  }

  int victor = 0;
  int ma = 0;
  REP(j,n) {
    if (cand_cnt[j] > ma) {
      ma = cand_cnt[j];
      victor = j;
    }
  }

  cout << victor+1 << endl;
  
  return 0;
}
