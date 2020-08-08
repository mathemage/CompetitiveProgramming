 
/* ========================================

   * File Name : 16.cpp

   * Creation Date : 26-07-2020

   * Last Modified : So 8. srpna 2020, 14:04:34

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

  multiset<long long> min_values;
  REP(m,M+1) {
    min_values.insert(0);
  }
  // display min_values
//   MSG(M+1)
//   cout << "min_values: ";
//   for (auto & v: min_values) {
//     cout << v << " ";
//   }
//   cout << endl;

  long long qhead;

  long long Ci;
  cin >> Ci;    // skip the starting city

//   cout << endl;
  long long result = UNDEF;
  FOR(n,1LL,N) {
    cin >> Ci;
//     MSG(Ci) 

    if (result == UNDEF) {
      qhead = (n-1LL) % qlen;
      if (queue[qhead] != INF) {
        min_values.erase(min_values.find(queue[qhead]));
      }

      if (min_values.empty()) {   // no more reachable cities with a gas station
        result = INF;
      } else {
        if (Ci == 0LL) {
          queue[qhead] = INF;
        } else {
          queue[qhead] = *(min_values.begin()) + Ci;
          min_values.insert(queue[qhead]);
        }
      }

//       cout << "min_values: ";
//       for (auto & v: min_values) {
//         cout << v << " ";
//       }
//       cout << endl;
    }

    // display queue
//     cout << n << "(" << Ci << "): ";
//     REP(q,qlen) {
// //     for (long long q = qhead; q != (qhead + qlen - 1) % qlen; q = (q+1) % qlen) {
//       cout << queue[(qhead + 1 + q) % qlen] << " ";
//     }
//     cout << endl;
  }

  return (result == UNDEF) ? *(min_values.begin()) : result;
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
