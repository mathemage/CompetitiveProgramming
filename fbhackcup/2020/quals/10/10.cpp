 
/* ========================================

   * File Name : 10.cpp

   * Creation Date : 24-07-2020

   * Last Modified : Pá 24. července 2020, 21:15:59

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/codingcompetitions/hacker-cup/2020/qualification-round/problems/A

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

const char default_char = 'N';

vector<vector<char>> get_result(int N, string I, string O) {
  vector<vector<char>> reachability(N, vector<char>(N, default_char));
  REP(d,N) reachability[d][d] = 'Y';

  REP(d,N-1) {
    REP(i, N) REP(j, N) {
      if (reachability[i][j] == 'N' || O[j] == 'N') {
        continue;
      }

      int neigh;
      for (auto & delta: {-1, 1}) {
//         MSG(delta)
        neigh = j + delta;

        if (0 <= neigh && neigh < N && I[neigh] == 'Y') {
          reachability[i][neigh] = 'Y';
        }
      }
    }
  }

  return reachability;
}

int main() {
  int T;
  cin >> T;
//   MSG(T)

  REP(i,T) {
    int N;
    cin >> N;
//     MSG(N)

    string I, O;
    cin >> I;
    cin >> O;
//     MSG(I) MSG(O)

    cout << "Case #" << i + 1 << ":" << endl;
    vector<vector<char>> result = get_result(N, I, O);
    REP(r,N) {
      REP(c,N) {
        cout << result[r][c];
      }
      cout << endl;
    }

  }
  return 0;
}
