/* ========================================

   ID: mathema6
   TASK: ip
   LANG: C++14

   * File Name : ip.cpp
   * Creation Date : 05-02-2022
   * Last Modified : Sat 05 Feb 2022 06:36:57 PM CET
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : see ./en.pdf
   * Points/Time :
   * Total/ETA :
   * Status :
   * 10/100 :-O WTF??
   * 10/100 :-/
   *
   ==========================================*/

#include <sstream>
#include <string>
#define PROBLEMNAME "ip"

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
// #define endl "\n" << flush  // flush for interactive problems
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define REPi(i,n) for(int i=0;i<(n);i++)
#define FORi(i,a,b) for(int i=(a);i<=(b);i++)
#define FORDi(i,a,b) for(int i=(a);i>=(b);i--)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define F first
#define S second
#define OP first
#define CL second
#define PB push_back
#define MP make_pair
#define MTP make_tuple
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define CONTAINS(S,E) ((S).find(E) != (S).end())
#define SZ(x) ((ll) (x).size())
// #define SZi(x) ((int) (x).size())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define YN(b) cout << ((b)?"YES":"NO") << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define Yn(b) cout << ((b)?"Yes":"No") << endl;
#define Imp cout << "Impossible" << endl;
#define IMP cout << "IMPOSSIBLE" << endl;

using ll = long long;
using ul = unsigned long long;
// using ulul = pair<ul, ul>;
using ld = long double;
using graph_unord = unordered_map<ll, vector<ll>>;
using graph_ord  = map<ll, set<ll>>;
using graph_t    = graph_unord;

#ifdef ONLINE_JUDGE
  #undef MATHEMAGE_DEBUG
#endif

#ifdef MATHEMAGE_DEBUG
  #define MSG(a) cerr << "> " << (#a) << ": " << (a) << endl;
  #define MSG_VEC_VEC(v) cerr << "> " << (#v) << ":\n" << (v) << endl;
  #define LINESEP1 cerr << "-----------------------------------------------                  " << endl;
  #define LINESEP2 cerr << "_________________________________________________________________" << endl;
#else
  #define MSG(a)
  #define MSG_VEC_VEC(v)
  #define LINESEP1
  #define LINESEP2
#endif

ostream& operator<<(ostream& os, const vector<string> & vec) { os << endl; for (const auto & s: vec) os << s << endl; return os; }

template<typename T> 
ostream& operator<<(ostream& os, const vector<T> & vec) { for (const auto & x: vec) os << x << " "; return os; } 

template<typename T> 
ostream& operator<<(ostream& os, const vector<vector<T>> & vec) { for (const auto & v: vec) os << v << endl; return os; } 

template<typename T>
inline ostream& operator<<(ostream& os, const vector<vector<vector<T>>> & vec) {
  for (const auto & row: vec) {
    for (const auto & col: row) {
      os << "[ " << col << "]   ";
    }
    os << endl;
  }
  return os;
}

template<typename T, class Compare>
ostream& operator<<(ostream& os, const set<T, Compare>& vec) { for (const auto & x: vec) os << x << " "; os << endl; return os; } 

template<typename T, class Compare>
ostream& operator<<(ostream& os, const multiset<T, Compare>& vec) { for (const auto & x: vec) os << x << " "; os << endl; return os; }

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& vec) { for (const auto & x: vec) os << x.F << ":" << x.S << " | "; return os; }

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const unordered_map<T1, T2>& vec) { for (const auto & x: vec) os << x.F << ":" << x.S << " | "; return os; }

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << "(" << p.F << ", " << p.S << ")"; }

template<typename T>
istream& operator>>(istream& is, vector<T> & vec) { for (auto & x: vec) is >> x; return is; }

template<typename T>
inline bool bounded(const T & x, const T & u, const T & l=0) { return min(l,u)<=x && x<max(l,u); }

template<class T> bool umin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// inline bool eqDouble(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool eqDouble(ld a, ld b) { return fabs(a-b) < 1e-9; }
inline bool isCollinear(ld x, ld y, ld x1, ld y1, ld x2, ld y2) {
  // (x-x1)/(y-y1) == (x-x2)/(y-y2)
  // (x-x1)*(y-y2) == (x-x2)*(y-y1)
  return eqDouble((x-x1)*(y-y2), (x-x2)*(y-y1));
}
inline bool isBetween(ld x, ld y, ld x1, ld y1, ld x2, ld y2) {
  return min(x1,x2)<=x && x<=max(x1,x2)
      && min(y1,y2)<=y && y<=max(y1,y2);
}
inline bool onLine(ld x, ld y, ld x1, ld y1, ld x2, ld y2) {
  return isCollinear(x, y, x1, y1, x2, y2) && isBetween(x, y, x1, y1, x2, y2);
}


#ifndef MATHEMAGE_LOCAL
void setIO(string filename) {    // the argument is the filename without the extension
	freopen((filename+".in").c_str(), "r", stdin);
	freopen((filename+".out").c_str(), "w", stdout);
  MSG(filename);
}
#endif

const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};

const vector<int> DX4 = {0, 1,  0, -1};
const vector<int> DY4 = {1, 0, -1,  0};
const vector<pair<int,int>> DXY4 = { {0,1}, {1,0}, {0,-1}, {-1,0} };
const string dues="NESW";

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;
const double EPS = 1e-8;
const ld PI = acos((ld)-1);

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;


const int WIDTH = 32;
const int OCT = WIDTH/4;

using i_t = bitset<WIDTH>;
// using i_t = int32_t;
// using i_t = int;
using ip_t = pair<i_t, int>;

auto cmp = [](ip_t a, ip_t b) {
  if (a.F == b.F) {
    return a.S < b.S;
  } else {
    return a.F.to_string() < b.F.to_string();
//     return to_string(a.F) < to_string(b.F);
  }
};

template<class Compare>
ostream& operator<<(ostream& os, const set<ip_t, Compare>& vec) { os << endl; for (const auto & x: vec) os << x << endl; return os; } 

ostream& operator<<(ostream& os, const vector<ip_t>& vec) { os << endl; for (const auto & x: vec) os << x << endl; return os; } 

void solve() {
  ll n; cin >> n;
  MSG(n);

  string line, token;
  vector<ip_t> pool;
  REP(_,n) {
    cin >> line;
    MSG(line);

    istringstream ss(line);
    i_t addr=0;
    REP(i,4) {
      std::getline(ss, token, (i==3 ? '/' : '.'));
      int octet = stoi(token);
//       MSG(octet);
      assert(octet < (1<<OCT));

      addr <<= OCT;
      addr |= octet;
    }
    MSG(addr);

    std::getline(ss, token, '/');
    int mask = stoi(token);
    MSG(mask);

    pool.PB({addr, mask});
    LINESEP1;
  }
  MSG(pool);
  LINESEP1;

  std::stable_sort(ALL(pool), cmp );
  MSG(pool);
  LINESEP1;

  ll countDown = 100*n;
  while (--countDown>0) {
    vector<ip_t> newPool;

    bool changed=0;
    for (ll i = 0; i < SZ(pool); i += 1) {
      if (i-1>=0 && pool[i]==pool[i-1]) {
        continue;
      }

      i_t addr1 = pool[i].F;
      int mask1 = pool[i].S;
      MSG(addr1); MSG(mask1);

      if (i+1<SZ(pool) && mask1>0) {
        i_t addr2 = pool[i+1].F;
        int mask2 = pool[i+1].S;
        MSG(addr2); MSG(mask2);

        if (mask2>0) {
          i_t pref1=addr1>>(32-mask1+1);
          i_t pref2=addr2>>(32-mask2+1);
          MSG(pref1); MSG(pref2); MSG(pref1==pref2);

          int pos1=32-mask1;
          int pos2=32-mask2;
          MSG(pos1); MSG(pos2);
          MSG(addr1[pos1]); MSG(addr2[pos2]);

          if (pref1==pref2
              && addr1[pos1]==0 && addr2[pos2]==1) {
            MSG("merge");
            MSG(addr1); MSG(addr2);

            mask1--;
            changed=1;
            i++;
            LINESEP1;
          }
        }
      }

      ip_t newIp = {addr1, mask1};

      newPool.PB(newIp);
      LINESEP1;
    }

    pool = newPool;
    if (!changed) { break; }
  }
  assert(countDown>0);

  for (auto & [addr, mask]: pool) {
//     MSG(addr);
    int octet=0;
    REP(i,WIDTH) {
      int pos=WIDTH-1-i;

      octet <<= 1;
      octet |= addr[pos];
//       MSG(i); MSG(pos); MSG(addr[i]); MSG(octet);

      if (i%OCT==OCT-1) {
        cout << octet << (i!=WIDTH-1 ? "." : "/");
        octet=0;
      }
//       LINESEP1;
    }

    cout << mask << endl;
    LINESEP1;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << std::setprecision(10) << std::fixed;

#ifndef MATHEMAGE_LOCAL
//   setIO(PROBLEMNAME);
#endif

  int cases = 1;
  FOR(tt,1,cases) {
//     cout << "Case #" << tt << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
