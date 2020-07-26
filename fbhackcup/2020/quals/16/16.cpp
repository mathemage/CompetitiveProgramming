 
/* ========================================

   * File Name : 16.cpp

   * Creation Date : 26-07-2020

   * Last Modified : Ne 26. července 2020, 17:55:01

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/codingcompetitions/hacker-cup/2020/qualification-round/problems/D1

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

#define INF -1

int main() {
  int T;
  cin >> T;
//   MSG(T) 

  long N, M;
  unsigned long long Ci;
  REP(t,T) {
    cin >> N >> M;
//     MSG(N) MSG(M) 

    vector<long long> queue(M + 1, 0);
    long long qlen = queue.size();
//     MSG(qlen)
//     REP(q,qlen) {
//       MSG(queue[q])
//     }

    long long min_idx = 0; // index of smallest (non-INF) value in queue
    long long qhead;

    cin >> Ci;    // skip the starting city
    REP(n,N-1) {
      cin >> Ci;
//       MSG(Ci) 

      qhead = (n-1) % qlen;

      do {
        min_idx = (min_idx + 1) % qlen;
        if (min_idx == qhead) {   // no reachable city with a gas station
          // TODO break and return INF
          return EXIT_FAILURE;
        }
      } while (queue[min_idx] == INF);

      queue[qhead] = (Ci != 0) ? (queue[min_idx] + Ci) : INF;
    }

    long long result = INF; // mock output
    cout << "Case #" << t + 1 << ": " << result << endl;
  }

  return 0;
}
