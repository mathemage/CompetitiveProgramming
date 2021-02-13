/* ========================================
 * Points/Time :
 * - 281.04 (30m 40s)
 * Total/ETA : 500 (15m)
 * Status :
 * - WA #3
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
    sort(ALL(num));
    map<int, int> freq;
    for (auto & n: num) {
      if (!SETCONTAINS(freq, n)) {
        freq[n] = 0;
      }
      freq[n]++;
    }

    int max_exp=UNDEF;
    int min_exp=2e9;
    for (auto & n: num) {
      if (!SETCONTAINS(freq, n)) {
        freq[n+1] = 0;
      }
      freq[n+1] += freq[n]/a;
      freq[n] %= a;

      if (freq[n]) {
        MINUPDATE(min_exp, n);
        MAXUPDATE(max_exp, n);
      }
      if (freq[n+1]) {
        MINUPDATE(min_exp, n+1);
        MAXUPDATE(max_exp, n+1);
      }
//       MSG(n); MSG(freq[n]); MSG(freq[n+1]); MSG(min_exp); MSG(max_exp);
    }

    if (max_exp != min_exp || freq[max_exp]>1) {
      return max_exp+1;
    } else {
      return max_exp;
    }
  }
};
