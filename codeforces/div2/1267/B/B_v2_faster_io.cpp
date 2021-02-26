 
/* ========================================
   * File Name : B_v2_faster_io.cpp
   * Creation Date : 26-02-2021
   * Last Modified : Pá 26. února 2021, 22:19:58
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/problemset/problem/1267/B
   * Points/Time :
   * Total/ETA :
   * Status :
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


void solve() {
  string s;
  cin >> s;

  vector<int> cnt;
  vector<char> colors;
  for (auto & c: s) {
    if (colors.empty() || c!=colors.back()) {
      cnt.PB(1);
      colors.PB(c);
    } else {
      cnt.back()++;
    }
  }
//   print_vector(cnt, "cnt");
//   print_vector(colors, "colors");

  int l=0, r=SZ(colors)-1;
  while (l<r) {
    if (colors[l]==colors[r] && cnt[l]+cnt[r]>=3) {
//       MSG(l) MSG(r) 
      l++, r--;
    } else {
      break;
    }
  }

  long long result = 0LL;
  if (l==r && cnt[l]>=2) {
    result=cnt[l]+1;
  }
  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
