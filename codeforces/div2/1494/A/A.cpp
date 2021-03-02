 
/* ========================================
   * File Name : A.cpp
   * Creation Date : 02-03-2021
   * Last Modified : Út 2. března 2021, 16:15:03
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1494/problem/0
   * Points/Time : 27m 37s
   * Total/ETA :
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


bool solve() {
  string s;
  cin >> s;
//   MSG(s);

  vector<char> options={'(', ')'};
  for (auto & a: options) {
    for (auto & b: options) {
      for (auto & c: options) {
        vector<char> s2;
        for (auto & it: s) {
          if (it=='A') {
            s2.PB(a);
          }
          if (it=='B') {
            s2.PB(b);
          }
          if (it=='C') {
            s2.PB(c);
          }
        }
//         print_vector(s2, "s2");

        bool result=true;
        int lvl=0;
        for (auto & it: s2) {
//           MSG(it) MSG(lvl)
          if (it=='(') {
            lvl++;
          } else {
            if (lvl>0) {
              lvl--;
            } else {
              result=false;
              break;
            }
          }
//           MSG(lvl)
        }

        result&=lvl==0;
        if (result) {
          return true;
        }
      }
    }
  }
//   cerr << endl;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cases = 1;
  cin >> cases;
  while (cases--) {
    cout << (solve()?"YES":"NO") << endl;
  }
  return 0;
}
