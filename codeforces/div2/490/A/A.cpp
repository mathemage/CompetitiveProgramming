 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 05-11-2015

   * Last Modified : Thu 05 Nov 2015 10:43:05 AM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/problemset/problem/490/A

   * Points Gained (in case of online contest) : AC

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
  int n, t;
  cin >> n;
  vector <vector<int> > arr(3);
  REP(i,n) {
    cin >> t;
    arr[t-1].emplace_back(i+1);
  }
  int m = min(arr[0].size(), min(arr[1].size(), arr[2].size()));
  cout << m << endl;
  REP(i,m) {
    REP(j,3) {
      cout << arr[j][i] << " ";
    }
    cout << endl;
  }
  return 0;
}
