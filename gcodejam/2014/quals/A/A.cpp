/* ========================================

   * File Name : A.cpp

   * Creation Date : 10-04-2015

   * Last Modified : Fri 10 Apr 2015 10:25:08 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://code.google.com/codejam/contest/2974486/dashboard

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()

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
  int t, a, x;
  cin >> t;
  REP(i,t) {
    printf("Case #%d: ", i+1);
    vector<bool> cards(16);
    cin >> a;
    REP(i,4) {
      REP(j,4) {
        cin >> x;
        if (i == a-1) {
          cards[x-1] = true;
        }
      }
    }

    vector<int> sol;
    cin >> a;
    REP(i,4) {
      REP(j,4) {
        cin >> x;
        if (i == a-1 && cards[x-1]) {
          sol.emplace_back(x);
        }
      }
    }

    if (!sol.size()) {
      cout << "Volunteer cheated!";
    } else if (sol.size() > 1) {
      cout << "Bad magician!";
    } else {
      cout << sol[0];
    }
    cout << endl;
  }
  return 0;
}
