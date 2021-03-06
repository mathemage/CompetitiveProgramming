 
/* ========================================
   * File Name : B_v3_coding_kata_2.cpp
   * Creation Date : 07-03-2021
   * Last Modified : Ne 7. března 2021, 00:37:13
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1493/problem/B
   * Points/Time : 10m10s
   * Total/ETA : 1250 (15m)
   * Status : AC
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

inline int cc(char c) {
  return c-'0';
}

inline int cr(char c) {
  if (c=='2') {
    return 5;
  } else if (c=='5') {
    return 2;
  }
  return cc(c);
}

void solve() {
  int h,m;
  cin>>h>>m;
  string s;
  cin>>s;

  string valid=":01258";
  while (true) {
    int rh=cr(s[4])*10 + cr(s[3]);
    int rm=cr(s[1])*10 + cr(s[0]);

    bool ok=true;
    for (auto & c: s) {
      if (count(ALL(valid), c)==0 || rh>=h || rm>=m) {
        ok=false;
        break;
      }
    }

    if (ok) {
      cout << s << endl;
      return;
    }

    int hh=cc(s[0])*10 + cc(s[1]);
    int mm=cc(s[3])*10 + cc(s[4]);
    hh=(hh+ ++mm/m)%h;
    mm%=m;

    s = to_string(hh/10) + to_string(hh%10) + ":" + to_string(mm/10) + to_string(mm%10);
  }
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
