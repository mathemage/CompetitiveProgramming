/* ========================================
 * Points/Time :
 * Total/ETA : 750
 * Status : unsubmitted
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
const int INF = INT_MAX;
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


class PoisonedSwamp {
public:
  string cross(vector <string> swamp) {
    int n_rows = swamp.size();
    int n_cols = swamp[0].size();
    int N = n_rows * n_cols;

    vector<vector<int>> dist(n_rows, vector<int>(n_cols,INF));
    dist[0][0] = 0;

    // Bellman-Ford
    REP(i,2*N) {
      REP(at,N) {
        int at_r=at/n_cols;
        int at_c=at%n_cols;
        for (auto & dxy: DXY4) {
          int to_r=at_r+dxy.F;
          int to_c=at_c+dxy.S;

          if (0<=to_r && to_r<n_rows &&
              0<=to_c && to_c<n_cols && dist[to_r][to_c]=='#') {
            // relax edges
            int to_cost = 0;
            if (dist[at_r][at_c]>='0' && dist[at_r][at_c]<='9') {
              to_cost=dist[at_r][at_c]-'0';
            }
            int new_cost = dist[at_r][at_c]=='S'? 0 : dist[at_r][at_c]+to_cost;
            MINUPDATE(dist[to_r][to_c], new_cost);
          }
        }
      }
    }

    bool result=dist[n_rows-1][n_cols-1]>=10;
    return result?"possible":"impossible";
  }
};
