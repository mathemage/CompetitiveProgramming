/* ========================================
 * Points/Time : 188.61
 * Total/ETA : 400
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


class SlotMachineHacking {
public:
  int win(vector <string> reels, vector <int> steps) {
    int n=reels.size();

    vector<int> reel_sizes(n);
    vector<int> pos_c(n);
    REP(j,n) {
      reel_sizes[j] = reels[j].size();

      for (int i = 0; i < reel_sizes[j]; i += 1) {
        if (reels[j][i]=='c') {
          pos_c[j] = i;
          break;
        }
      }

      steps[j]%=reel_sizes[j];
    }

    bool passed;
    FOR(k,1,1e5+20) {
      passed=true;
      REP(i,n) {
        if ( (k * steps[i] - pos_c[i]) % reel_sizes[i] != 0) {
          passed=false;
          break;
        }
      }
      if (passed) {
        return k-1;
      }
    }

    return -1;
  }
};
