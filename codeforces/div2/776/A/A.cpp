 
/* ========================================
   * File Name : A.cpp
   * Creation Date : 04-01-2021
   * Last Modified : Po 4. ledna 2021, 18:11:04
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/problemset/problem/776/A
   * Points : 
   * Total :
   * Status : AC
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

int main() {
  vector<string> alive(2);
  cin >> alive[0] >> alive[1];

  cout << alive[0] << " " << alive[1] << "\n";
  string murdered, replacement;

  int n;
  cin >> n;
  while (n--) {
    cin >> murdered >> replacement;
    for (auto & person : alive) {
      if (person == murdered) {
        person = replacement;
      }
    }
    cout << alive[0] << " " << alive[1] << "\n";
  }
  return 0;
}
