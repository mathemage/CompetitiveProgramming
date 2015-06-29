 
/* ========================================

   * File Name : C.cpp

   * Creation Date : 27-06-2015

   * Last Modified : Mon 29 Jun 2015 11:14:16 AM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/556/problem/C

   * Points Gained (in case of online contest) : 504 / 1000, RE-RE-AC

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
  long long n, k;
  cin >> n >> k;
  vector<long long> succ(2 * n,0);
  vector<long long> pred(2 * n,0);
  REP(i,k) {
    long long m;
    cin >> m;
    vector<long long> chain(2 * m,0);
    long long prev = 0;
    REP(j,m) {
      cin >> chain[j];
      pred[chain[j]] = prev;
      prev = chain[j];
    }
    REP(j,m-1) {
      succ[chain[j]] = chain[j+1];
    }
  }

  /* 
  cout << "\nsucc: ";
  for (auto & x : succ) {
    cout << x << " ";
  }
  cout << "\npred: ";
  for (auto & x : pred) {
    cout << x << " ";
  }
  cout << endl;
 */
  long long secs = 0;
  FOR(i,1,n) {
    if (succ[i] == i+1) {
      continue;
    }

    // separate head
    long long cur = i;
    while (succ[cur] != 0) {
      cur = succ[cur];
      succ[pred[cur]] = 0;
      pred[cur] = 0;
      secs++;
    }

    // separate tail
    // after segment
    cur = i+1;
    while (succ[cur] != 0) {
      cur = succ[cur];
      succ[pred[cur]] = 0;
      pred[cur] = 0;
      secs++;
    }
    // before segment
    if (pred[i+1] != 0) {
      succ[pred[i+1]] = 0;
      pred[i+1] = 0;
      secs++;
    }

    // merge head -> tail
    succ[i] = i+1;
    pred[i+1] = i;
    secs++;
  }

  cout << secs << endl;
  return 0;
}
