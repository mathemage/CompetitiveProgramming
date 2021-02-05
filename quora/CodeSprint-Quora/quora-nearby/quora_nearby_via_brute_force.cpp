 
/* ========================================
   * File Name : quora_nearby_via_brute_force.cpp
   * Creation Date : 05-02-2021
   * Last Modified : Pá 5. února 2021, 20:21:22
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://www.hackerrank.com/contests/cs-quora/challenges/quora-nearby
   * Points/Time : 58m +~45m
   * Total/ETA : 15m
   * Status :
   * - WA (3/9) & TLE (4/9)
   * - WA (2/9)
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FO(I,A,B) for(int I = (A); I <= (B); ++I)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MINUPDATE(A,B) A = min((A), (B));
#define MAXUPDATE(A,B) A = max((A), (B));
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;
const double EPS = 0.001;
const double INF = DBL_MAX;

// direction vectors - 4 directions
const vector<int> DX4 = { 0, 0, -1, 1};
const vector<int> DY4 = {-1, 1,  0, 0};
const vector<pair<int,int>> DXY4 = { {0,-1}, {0,1}, {-1,0}, {1,0} };
// direction vectors - 8 directions
const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};


void solve() {
  int T,Q,N;
  cin >> T >> Q >> N;
//   MSG(T); MSG(Q); MSG(N);

  vector<int> Tid(T);
  vector<pair<double, double>> Txy(T);
  REP(i,T) {
    cin >> Tid[i] >> Txy[i].F >> Txy[i].S;
//     MSG(Tid[i]);
  }

  vector<int> Qid(Q);
  map<int, unordered_set<int>> Q2T;
  int n_topics, tid;
  REP(i,Q) {
    cin >> Qid[i] >> n_topics;
    while (n_topics--) {
      cin >> tid;
      Q2T[Qid[i]].insert(tid);
    }
//     MSG(Qid[i]);
  }

  char q_type;
  int n_results;
  pair<double, double> query_xy;
  REP(i,N) {
    cin >> q_type >> n_results >> query_xy.F >> query_xy.S;
//     MSG(q_type);

    /* calculate distances to Ts */
    vector<pair<double, int>> dist_T(T);
    map<int, double> T2dist;
    REP(i,T) {
      T2dist[Tid[i]] = pow(Txy[i].F-query_xy.F, 2) + pow(Txy[i].S-query_xy.S, 2);
      dist_T[i].F = T2dist[Tid[i]];
      dist_T[i].S = -Tid[i];
    }
    sort(ALL(dist_T));
    /*****************************/

    switch (q_type) {
      case 't': {
        MINUPDATE(n_results, (int)dist_T.size());
        REP(j,n_results) {
          cout << -dist_T[j].S << (j<n_results-1? " " : endl);
        }
        break;
      }

      case 'q': {
        vector<pair<double, int>> dist_Q;
        REP(j,Q) {
          double min_dist = INF;
          for (auto & tid: Q2T[Qid[j]]) {
            MINUPDATE(min_dist, T2dist[tid]);
          }
          if (min_dist != INF) {
            dist_Q.PB(MP(min_dist,-Qid[j]));
          }
        }
        sort(ALL(dist_Q));

//         MSG(dist_Q.size()); MSG(n_results);
        MINUPDATE(n_results, (int)dist_Q.size());
        REP(j,n_results) {
          cout << -dist_Q[j].S << (j<n_results-1? " " : endl);
        }
        break;
      }
    }
  }
}

int main() {
  int cases=1;
  while (cases--) {
    solve();
  }
  return 0;
}
