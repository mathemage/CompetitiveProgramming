 
/* ========================================
   * File Name : B_v4_coding_kata_3.cpp
   * Creation Date : 08-03-2021
   * Last Modified : Po 8. března 2021, 00:32:56
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1493/problem/B
   * Points/Time : 6m10s
   * Total/ETA : 9m
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

int mir(int d) {
  switch (d) {
    case 0:
    case 1:
    case 8: return d;
    case 2: return 5;
    case 5: return 2;
  }
  return -1e6;
}

void solve() {
  int h,m;
  cin >> h >> m;
  int hh,mm;
  char sep;
  cin >> hh >> sep >> mm;
//   MSG(hh) MSG(mm);

  while (1) {
    int rh = 10 * mir(mm%10) + mir(mm/10);
    int rm = 10 * mir(hh%10) + mir(hh/10);

    if (bounded(rh,h) && bounded(rm,m))  {
      cout << hh/10 << hh%10 << sep << mm/10 << mm%10 << endl;
      break;
    }

    hh += ++mm/m;
    hh %= h;
    mm %= m;
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
