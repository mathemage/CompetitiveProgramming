 
/* ========================================

   * File Name : 45.cpp

   * Creation Date : 22-07-2020

   * Last Modified : St 22. července 2020, 14:06:51

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/codingcompetitions/hacker-cup/2019/qualification-round/problems/D

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

string get_result(int N, int M, vector<int> X, vector<int> Y, vector<int> Z) {
  string result = "Impossible";
  return result;
}

int main() {
  int T;
  cin >> T;
//   MSG(T)

  int N, M;
  REP(i,T) {
    cin >> N >> M;
//     MSG(N) MSG(M)

    vector<int> X(M), Y(M), Z(M);
    REP(j,M) {
      cin >> X[j] >> Y[j] >> Z[j];
//       MSG(X[j]) MSG(Y[j]) MSG(Z[j])
    }

    cout << "Case #" << i + 1 << ": " << get_result(N, M, X, Y, Z) << endl;
  }

  return 0;
}
