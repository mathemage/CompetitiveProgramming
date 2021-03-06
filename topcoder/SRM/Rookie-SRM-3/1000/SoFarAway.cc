/* ========================================
 * Points/Time : 876.48
 * Total/ETA : 1000
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MTP make_tuple
#define MINUPDATE(A,B) A = min((A), (B));
#define MAXUPDATE(A,B) A = max((A), (B));
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define CONTAINS(S,E) ((S).find(E) != (S).end())
#define SZ(x) ((int) (x).size())

#define MSG(a) cerr << "> " << #a << ": " << (a) << endl;
template<typename T>
void print_vector(const vector<T> & vec, const string & name) {
  cerr << name << ": ";
  for (const auto & x: vec) cerr << x << "  ";
  cerr << endl;
}

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

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

class SoFarAway {
public:
  int distance(vector <string> plan) {
    int n_r=SZ(plan);
    int n_c=SZ(plan[0]);

    queue<int> qr;
    queue<int> qc;
    vector<vector<int>> dist(n_r, vector<int>(n_c, INF));
    REP(r,n_r) REP(c,n_c) {
      if (plan[r][c]=='S') {
        qr.push(r);
        qc.push(c);
        dist[r][c]=0;
      }
    }

    while (!qr.empty()) {
      int r=qr.front(), c=qc.front();
      qr.pop(), qc.pop();
      if (plan[r][c]=='D') {
        return dist[r][c];
      }

      for (auto & dxy: DXY4) {
        int rr=r+dxy.F, cc=c+dxy.S;
        if (0<=min(rr,cc) && rr<n_r && cc<n_c && plan[rr][cc]!='X' && dist[rr][cc]==INF) {
          dist[rr][cc]=dist[r][c]+1;
          qr.push(rr), qc.push(cc);
        }
      }
    }

    return -1;
  }
};
