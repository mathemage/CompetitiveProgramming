 
/* ========================================

   ID: mathema6
   TASK: gen_max_test
   LANG: C++11

   * File Name : gen_max_test.cxx
   * Creation Date : 07-01-2021
   * Last Modified : Út 2. března 2021, 17:05:59
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL :
   * Points :
   * Total :
   * Status :
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

void solve() {
  long long result = 0LL;
  cout << result << endl;
}

int main() {
  // t
  int cases = 1000;
  cout << cases << endl;

  // n, m...
  int lim = 200000;
  cout << lim << " " << lim << endl;

  int cur;

  srand(42);

  // box positions
  cur=-1e9;
  REP(i,lim/2) {
    cur += rand() % 100 + 1;
    cout << cur << " ";
  }
  cur=1e9;
  REP(i,lim/2) {
    cur -= rand() % 100 + 1;
    cout << cur << " ";
  }
  cout << endl;

  // specials
  cur=-1e9;
  REP(i,lim/2) {
    cur += rand() % 100 + 1;
    cout << cur << " ";
  }
  cur=1e9;
  REP(i,lim/2) {
    cur -= rand() % 100 + 1;
    cout << cur << " ";
  }
  cout << endl;

  return 0;
}

// const int fill_size = 10; 
// const int min = 1;        // min random number
// const int max = 100;      // max random number
// 
// std::vector<int> vec;
// while (vec.size() != fill_size) {
//   vec.emplace_back(ran(min, max)); // create new random number
//   std::sort(begin(vec), end(vec)); // sort before call to unique
//   auto last = std::unique(begin(vec), end(vec));
//   vec.erase(last, end(vec));       // erase duplicates
// }
// 
