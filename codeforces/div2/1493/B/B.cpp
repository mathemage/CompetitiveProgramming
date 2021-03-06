 
/* ========================================
   * File Name : B.cpp
   * Creation Date : 06-03-2021
   * Last Modified : So 6. března 2021, 17:17:52
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1493/problem/B
   * Points/Time : 
   * Total/ETA : 1250
   * Status :
   * WA #3
   * WA #3
   *
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
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

inline long long cc(char c) {
  return c-'0';
}

inline long long cc2(char c) {
  if (c=='2') {
    c='5';
  }
  if (c=='5') {
    c='2';
  }
  return c-'0';
}

inline string ss(long long hh, long long mm) {
  return to_string(hh/10) + to_string(hh%10) + ":"
       + to_string(mm/10) + to_string(mm%10);
}

void solve() {
  long long h,m;
  cin >> h >> m;
  string s;
  cin >> s;

  REP(i,10*h*m) {
    long long hh=cc(s[0]) * 10 + cc(s[1]);
    long long mm=cc(s[3]) * 10 + cc(s[4]);
    long long rh=cc2(s[4]) * 10 + cc2(s[3]);
    long long rm=cc2(s[1]) * 10 + cc2(s[0]);

//     MSG(s);
    bool ok=true;
    for (auto & c: s) {
      if ( !(c==':' || c=='0' || c=='1' || c=='2' || c=='5' || c=='8') || rh>=h || rm>=m) {
        ok=false;
        break;
      }
    }

    if (ok) {
      cout << s << endl;
//       cerr << endl << endl;
      return;
    }

    mm++;
    if (mm>=m) {
      hh = (hh+1)%h;
      mm %= m;
    }
    s=ss(hh,mm);
//     MSG(hh) MSG(mm)
//     MSG(s); cerr << endl;
  }
//   cerr << "> INVALID ALL" << endl << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cases = 1;
  cin >> cases;
  while (cases--) {
    solve();
  }
  return 0;
}
