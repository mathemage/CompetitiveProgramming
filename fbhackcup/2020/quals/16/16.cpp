 
/* ========================================

   * File Name : 16.cpp

   * Creation Date : 26-07-2020

   * Last Modified : Po 27. července 2020, 15:15:42

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

#define INF -1LL
#define UNDEF -2LL

long long get_result(long long N, long long M) {
  vector<long long> queue(M + 1LL, 0LL);
  long long qlen = queue.size();
//   MSG(qlen)
//   REP(q,qlen) {
//     MSG(queue[q])
//   }

  long long min_idx = 0LL; // index of smallest (non-INF) value in queue
  long long qhead = qlen - 1LL;
  long long dist_head2min = (min_idx - qhead + qlen) % qlen;
//   MSG(dist_head2min)

  long long Ci;
  cin >> Ci;    // skip the starting city

//   cout << endl;
  long long result = UNDEF;
  FOR(n,1LL,N) {
    cin >> Ci;
//     MSG(Ci) 

    if (result == UNDEF) {
      qhead = (n-1LL) % qlen;
      dist_head2min--;

//       cout << endl;
//       MSG(min_idx)
      if (dist_head2min == 0LL) {
        do {
          min_idx = (min_idx + 1LL) % qlen;
          dist_head2min++;
          if (dist_head2min >= qlen) {   // no more reachable city with a gas station
            result = INF;
            break;
          }
        } while (queue[min_idx] == INF);
      }
//       MSG(min_idx) MSG(queue[min_idx])

      queue[qhead] = (Ci != 0LL) ? (queue[min_idx] + Ci) : INF;
    }

    // display queue
//     cout << n << "(" << Ci << "): ";
//     REP(q,qlen) {
// //     for (long long q = qhead; q != (qhead + qlen - 1) % qlen; q = (q+1) % qlen) {
//       cout << queue[(qhead + 1 + q) % qlen] << " ";
//     }
//     cout << endl;
  }

  return (result == UNDEF) ? queue[min_idx] : result;
}

int main() {
  long long T;
  cin >> T;
//   MSG(T) 

  long long N, M;
  REP(t,T) {
    cin >> N >> M;
//     MSG(N) MSG(M) 

    cout << "Case #" << t + 1LL << ": " << get_result(N, M) << endl;
  }

  return 0;
}
