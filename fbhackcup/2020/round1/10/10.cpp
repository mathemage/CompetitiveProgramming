 
/* ========================================

   * File Name : 10.cpp

   * Creation Date : 16-08-2020

   * Last Modified : Ne 16. srpna 2020, 13:45:45

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

int N, K, W;
long long AL, BL, CL, DL;
long long AH, BH, CH, DH;

int get_result(const vector<int> & L, const vector<int> & H) {
//   REP(k,K) MSG(L[k]);
//   REP(k,K) MSG(H[k]);

  // streamline via the recurrence
  deque<int> deqL;
  deqL.push_back(L[K-2]);
  deqL.push_back(L[K-1]);

  deque<int> deqH;
  deqH.push_back(H[K-2]);
  deqH.push_back(H[K-1]);

  FOR(i,K,N) {
//     cout << endl; MSG(i);
//     MSG(deqL.size()); for (auto & v: deqL) cout << v << " "; cout << endl;
//     MSG(deqH.size()); for (auto & v: deqH) cout << v << " "; cout << endl;

    deqL.push_back( (AL * (long long) deqL[0] + BL * (long long) deqL[1] + CL) % DL + 1);
    deqL.pop_front();

    deqH.push_back( (AH * (long long) deqH[0] + BH * (long long) deqH[1] + CH) % DH + 1);
    deqH.pop_front();

//     MSG(deqL.size()); for (auto & v: deqL) cout << v << " "; cout << endl;
//     MSG(deqH.size()); for (auto & v: deqH) cout << v << " "; cout << endl;
  }

  int result = -1;    // mock result
  return result;
}

int main() {
  int T;
  cin >> T;
//   MSG(T);

  REP(t,T) {
    cin >> N >> K >> W;
//     cout << endl; MSG(N); MSG(K); MSG(W);

    vector<int> L(N);
    REP(k,K) {
      cin >> L[k];
    }
    cin >> AL >> BL >> CL >> DL;
//     MSG(AL); MSG(BL); MSG(CL); MSG(DL);

    vector<int> H(N);
    REP(k,K) {
      cin >> H[k];
    }
    cin >> AH >> BH >> CH >> DH;
//     MSG(AH); MSG(BH); MSG(CH); MSG(DH);

    cout << "Case #" << t + 1 << ": " << get_result(L, H) << endl;
  }

  return 0;
}
