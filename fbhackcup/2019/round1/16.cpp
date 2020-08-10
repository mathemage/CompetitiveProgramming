 
/* ========================================

   * File Name : 16.cpp

   * Creation Date : 09-08-2020

   * Last Modified : Po 10. srpna 2020, 19:02:19

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/codingcompetitions/hacker-cup/2019/round-1/problems/B

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

int get_result(const string & V, int K) {
  int N = V.size();

  int init_balance = 0;    // n_B - n_A
  int balance = -2 * K; // i.e. -INF
  FOR(i, N-K, N) {
    init_balance += (V[i] == 'A') ? (-1) : 1;
    balance = max(balance, init_balance);
  }
//   MSG(balance)

  int result = 0;
  FOR(j, N-K, 0) {
//     MSG(j)
    // TODO: iterate backwards and count penalties
  }

  return result;
}

int main() {
  int T;
  cin >> T;
//   MSG(T)

  REP(t,T) {
    int N, K;
    cin >> N >> K;
//     MSG(N) MSG(K)

    string V;
    V.reserve(N);
    cin >> V;
//     MSG(V) cout << endl;

    cout << "Case #" << t+1 << ": " << get_result(V, K) << endl;
  }

  return 0;
}
