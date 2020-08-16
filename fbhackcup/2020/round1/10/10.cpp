 
/* ========================================

   * File Name : 10.cpp

   * Creation Date : 16-08-2020

   * Last Modified : Ne 16. srpna 2020, 12:53:14

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/codingcompetitions/hacker-cup/2020/round-1/problems/A1

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

int main() {
  int T;
  cin >> T;
//   MSG(T);

  REP(t,T) {
    int N, K, W;
    cin >> N >> K >> W;
//     cout << endl; MSG(N); MSG(K); MSG(W);

    vector<int> L(N);
    REP(k,K) {
      cin >> L[k];
//       MSG(L[k]);
    }
    int AL, BL, CL, DL;
    cin >> AL >> BL >> CL >> DL;
//     MSG(AL); MSG(BL); MSG(CL); MSG(DL);

    vector<int> H(N);
    REP(k,K) {
      cin >> H[k];
//       MSG(H[k]);
    }
    int AH, BH, CH, DH;
    cin >> AH >> BH >> CH >> DH;
//     MSG(AH); MSG(BH); MSG(CH); MSG(DH);
  }

  return 0;
}
