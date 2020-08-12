 
/* ========================================

   * File Name : 15.cpp

   * Creation Date : 12-08-2020

   * Last Modified : St 12. srpna 2020, 22:55:34

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/codingcompetitions/hacker-cup/2018/round-1/problems/A

   * Points Gained (in case of online contest) :

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

#define MOD 1000000007

int get_result(int N, const vector<string> & G) {
  if (N % 2) return 0;

  // free passage thru mid row
  for (auto & c: G[1]) {
    if (c != '.') return 0;
  }

  // cells next to entrance/exit are empty
  if (G[0][0] != '.' || G[2][N-1] != '.') return 0;

  int result = 1;
  FOR(i,1,N-1) {
    int current_ways = 0;
    for (auto & row: {0, 2}) {
      if (G[row][i] == '.' && G[row][i + 1] == '.') {
        current_ways++;
      }
    }
    result *= current_ways;
    result %= MOD;
  }
  return result;
}

int main() {
  int T;
  cin >> T;
//   MSG(T);

  REP(t,T) {
    int N;
    cin >> N;
//     cout << endl; MSG(N);

    vector<string> G(3);
    REP(l,3) {
      cin >> G[l];
//       MSG(G[l]);
    }

    cout << "Case #" << t+1 << ": " << get_result(N, G) << endl;
  }

  return 0;
}
