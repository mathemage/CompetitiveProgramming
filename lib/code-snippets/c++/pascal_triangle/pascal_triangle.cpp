 
/* ========================================
   * File Name : pascal_triangle.cpp
   * Creation Date : 16-01-2021
   * Last Modified : So 16. ledna 2021, 00:47:32
   * Created By : Karel Ha <mathemage@gmail.com>
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
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

typedef unsigned long long ull; 

const int N_MAX=55;
vector<vector<ull>> pascal(int n_max=N_MAX) {
  vector<vector<ull>> nCr(1+n_max, vector<ull>(1+n_max, 0));
  FO(n,0,n_max) {
    nCr[n][0] = 1;
    FO(r,1,n_max) {
      nCr[n][r] = n ? nCr[n-1][r-1] + nCr[n-1][r] : 0;
    }
  }
  return nCr;
}

int main() {
  int n_max = 10;
  vector<vector<ull>> nCr = pascal(n_max);
  for (auto & line: nCr) {
    for (auto & val : line) {
      cout << val << "\t";
    }
    cout << endl;
  }
  return 0;
}
