/* ========================================
 * Points/Time :
 * Total/ETA :
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

#ifdef ONLINE_JUDGE
  #undef MATHEMAGE_DEBUG
#endif

#ifdef MATHEMAGE_DEBUG
  #define MSG(a) cerr << "> " << (#a) << ": " << (a) << endl;
  #define MSG_VEC(v) print_vector((v), (#v));
  #define MSG_VEC_PAIRS(v) print_vector_pairs((v), (#v));
  #define LINESEP1 cerr << "-----------------------------------------------                  " << endl;
  #define LINESEP2 cerr << "_________________________________________________________________" << endl;
#else
  #define MSG(a)
  #define MSG_VEC(v)
  #define MSG_VEC_PAIRS(v)
  #define LINESEP1
  #define LINESEP2
#endif

template<typename T>
void print_vector(const vector<T> & vec, const string & name) {
  cerr << "> " << name << ": ";
  for (const auto & x: vec) cerr << x << "  ";
  cerr << endl;
}

template<typename T1, typename T2>
void print_vector_pairs(const vector<pair<T1, T2>> & vec, const string & name) {
  cerr << "> " << name << ": ";
  for (const auto & x: vec) cerr << "(" << x.F << ", " << x.S << ")\t";
  cerr << endl;
}

template<typename T>
inline bool bounded(const T & x, const T & u, const T & l=0) {
  return min(l,u)<=x && x<max(l,u);
}

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

const vector<int> DX4 = { 0, 0, -1, 1};
const vector<int> DY4 = {-1, 1,  0, 0};
const vector<pair<int,int>> DXY4 = { {0,-1}, {0,1}, {-1,0}, {1,0} };
const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};

class MoveAllMarbles {
public:
  vector <int> move(int R, int C, int N) {
    LINESEP2;

    vector <int> result;

    // oldr, oldc, newr, newc
    MSG(N);

    // load
    int nn=0;
    bool allStones=false;
    FORD(er,R-1,0) {
      FORD(ec,C-1,0) {
        if ((er==0 && ec==0) || (er==R-1 && ec==C-1)) {
          continue;
        }

        int sr=0, sc=0;
        while (sc<ec) {
          MSG(sr) MSG(sc); LINESEP1;
          result.PB(sr), result.PB(sc);
          result.PB(sr), result.PB(++sc);
          MSG(sr) MSG(sc); LINESEP1;
        }
        while (sr<er) {
          MSG(sr) MSG(sc); LINESEP1;
          result.PB(sr), result.PB(sc);
          result.PB(++sr), result.PB(sc);
          MSG(sr) MSG(sc); LINESEP1;
        }
        MSG(nn);
        if (++nn>=N) {
          allStones=true;
          break;
        }
        MSG(nn); MSG(N);
      }

      if (allStones) {
        break;
      }
    }
    MSG("loaded")

    // dispatch
    nn=0;
    allStones=false;
    FORD(er,R-1,0) {
      FORD(ec,C-1,0) {
        if ((er==0 && ec==0) || (er==R-1 && ec==C-1)) {
          continue;
        }

        int sr=er, sc=ec;
        while (sc<C-1) {
          MSG(sr) MSG(sc); LINESEP1;
          result.PB(sr), result.PB(sc);
          result.PB(sr), result.PB(++sc);
          MSG(sr) MSG(sc); LINESEP1;
        }
        while (sr<R-1) {
          MSG(sr) MSG(sc); LINESEP1;
          result.PB(sr), result.PB(sc);
          result.PB(++sr), result.PB(sc);
          MSG(sr) MSG(sc); LINESEP1;
        }

        MSG(nn);
        if (++nn>=N) {
          allStones=true;
          break;
        }
        MSG(nn); MSG(N);
      }

      if (allStones) {
        break;
      }
    }
    MSG("dispatched");

    LINESEP1;
    nn=0;
    MSG(nn);
    MSG(++nn>=N);
    MSG(nn); MSG(N);
    return result;
  }
};
