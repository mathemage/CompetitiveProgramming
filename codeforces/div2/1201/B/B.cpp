 
/* ========================================
   * File Name : B.cpp
   * Creation Date : 09-02-2021
   * Last Modified : Út 9. února 2021, 01:04:06
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1201/problem/B
   * Points/Time :
   * - 20m 30s
   *
   * Total/ETA : 20m
   * Status :
   * - WA #5
   *
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FO(I,A,B) for(int I = (A); I <= (B); ++I)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
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
  cerr << "> " << name << ": ";
  for (const auto & x: vec) cerr << x << "  ";
  cerr << endl;
}

const int CLEAN = -1;
const int UNDEF = -42;

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

int n;
vector<int> a;

void solve() {
  cin >> n;
  a.resize(n);
  REP(i,n) {
    cin >> a[i];
  }

  sort(ALL(a));
  long long sum = accumulate(ALL(a), 0LL);
//   print_vector(a, "a");

  int i=0, j=n-1;
  while (i < j) {
    int d = min(a[i], a[j]);
    a[i]-=d;
    a[j]-=d;
    sum-=2*d;

    if (a[i]==0) { i++; }
    if (a[j]==0) { j--; }
    sort(&a[i], &a[j]+1);
//     print_vector(a, "a");
  }

//   MSG(sum);
  cout << (sum==0?"YES":"NO") << endl;
}

int main() {
  int cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
