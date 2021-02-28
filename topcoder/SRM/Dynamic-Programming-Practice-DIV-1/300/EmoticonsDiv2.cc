/* ========================================
 * Points/Time : 173.12
 * Total/ETA : 300
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

// const int INF = INT_MAX;
const int INF = 1e6;
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

class EmoticonsDiv2 {
public:
  int printSmiles(int smiles) {
    vector<vector<int>> dp(smiles+1, vector<int>(smiles+1,INF));

    dp[1][0]=0;

    FOR(row,1,smiles) {  // # on screen
      FOR(col,0,row) {   // # in clipboard
        // copy-paste
        if (row+row<smiles+1) {
          MINUPDATE(dp[row+row][row], dp[row][col]+2);
        }

        // just paste
        if (row+col<smiles+1) {
          MINUPDATE(dp[row+col][col], dp[row][col]+1);
        }
      }
    }
//     REP(row,smiles+1) {
//       print_vector(dp[row], "dp[" + to_string(row) + "]");
//     }

    int result=INF;
    REP(col,smiles+1) {
      MINUPDATE(result, dp[smiles][col]);
    }
    return result;
  }
};
