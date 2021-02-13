/* ========================================
 * Points/Time :
 * - 281.04 (30m 40s)
 * - 150.00 (39m 40s)
 * - 150.00 (55m 00s)
 *
 * Total/ETA : 500 (15m)
 * Status :
 * - WA #3
 * - WA #32
 * - AC !!!!!!
 *
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
#define MINUPDATE(A,B) A = min((A), (B));
#define MAXUPDATE(A,B) A = max((A), (B));
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define SETCONTAINS(S,E) ((S).find(E) != (S).end())

#define MSG(a) cerr << "> " << #a << ": " << (a) << endl;
template<typename T>
void print_vector(const vector<T> & vec, const string & name) {
  cerr << name << ": ";
  for (const auto & x: vec) cerr << x << "  ";
  cerr << endl;
}

const int CLEAN = -1;
const int UNDEF = -42;
const int INF = 2e9;
const long long MOD = 1000000007;

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


class PlanningTrips {
public:
  int find(int a, vector <int> num) {
//     sort(ALL(num));
    map<int, int> freq;
    for (auto & n: num) {
      if (!SETCONTAINS(freq, n)) {
        freq[n] = 0;
      }
      freq[n]++;
    }

//     for (auto & nf: freq) { cerr << "> " << nf.F << ": " << nf.S << "\t"; } cerr << endl;

    int min_exp=INF;
    int max_exp=-INF;
    int n;
    int f;
    while (!freq.empty()) {
      n=(*freq.begin()).F;
      f=(*freq.begin()).S;
      freq.erase(freq.begin());

      if (f%a!=0) {
        MINUPDATE(min_exp, n);
        MAXUPDATE(max_exp, n);
      }

      if (f/a!=0) {
        if (!SETCONTAINS(freq, n+1)) {
          freq[n+1] = 0;
        }
        freq[n+1] += f/a;
      }

//       MSG(n); MSG(f); MSG(f/a); MSG(min_exp); MSG(max_exp);
//       for (auto & nf: freq) { cerr << "> " << nf.F << ": " << nf.S << "\t"; } cerr << endl;
    }

//     MSG(min_exp); MSG(max_exp);
    if (max_exp != min_exp || f>1) {
      return max_exp+1;
    } else {
      return max_exp;
    }
  }
};
