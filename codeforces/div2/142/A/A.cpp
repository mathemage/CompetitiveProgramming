 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 03-11-2015

   * Last Modified : Tue 03 Nov 2015 09:59:42 AM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : /home/mathemage/prog/CompetitiveProgramming/codeforces/div2/142/A

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
  int s, n;
  cin >> s >> n;
  vector< pair<int, int> > z(n);
  REP(i,n) {
    cin >> z[i].first >> z[i].second;
  }
  sort(ALL(z));
  for (auto & d : z) {
    if (d.first >= s) {
      cout << "NO" << endl;
      return 0;
    }
    s += d.second;
  }
  cout << "YES" << endl;
  return 0;
}
