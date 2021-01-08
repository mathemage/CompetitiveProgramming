 
/* ========================================
   * File Name : B.cpp
   * Creation Date : 08-01-2021
   * Last Modified : Pá 8. ledna 2021, 17:35:10
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1467/problem/B
   * Points :
   * Total : 1000
   * Status : WA (pre #3)
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
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto & ai : a) {
    cin >> ai;
  }

  long long result = 0LL;
  string desc(n,'0');
  FO(j,1,n-2) {
    if (a[j] > a[j+1] && a[j] > a[j-1]) {
      desc[j] = 'H';
      result++;
    } else if (a[j] < a[j+1] && a[j] < a[j-1]) {
      desc[j] = 'V';
      result++;
    }
  }
//   MSG(desc);

  if (desc.find("HVH") != string::npos
   || desc.find("VHV") != string::npos) {
    result -= 3;
  } else if (desc.find("VH") != string::npos
          || desc.find("HV") != string::npos) {
    result -= 2;
  } else if (desc.find("H") != string::npos
          || desc.find("V") != string::npos) {
    result -= 1;
  }

  cout << result << endl;
}

int main() {
  int cases;
  cin >> cases;
//   cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
