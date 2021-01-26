 
/* ========================================
   * File Name : upvotes.cpp
   * Creation Date : 22-01-2021
   * Last Modified : Út 26. ledna 2021, 20:50:51
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://www.hackerrank.com/contests/quora-haqathon/challenges/upvotes
   * Points/Time : (57m 24 s + )
   * Total :
   * Status :
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
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
// const int UNDEF = -42;
const int UNDEF = INT_MAX;
const int INF = INT_MAX;

void solve_via_brute_force() {
  int N, K;
  cin >> N >> K;

  vector<int> upvotes(N);
  vector<int> signs(N, UNDEF);
  REP(i,N) {
    cin >> upvotes[i];
    if (i>0) {
      signs[i] = SGN(upvotes[i]-upvotes[i-1]);
    }
//     MSG(upvotes[i]); MSG(signs[i]); cerr << endl;
    cerr << signs[i] << " ";
  }

  for (int win_start=0, win_end=win_start+K-1 ; win_end < N; win_start++, win_end++) {
    cerr << endl << endl; MSG(win_start); MSG(win_end);
    long long result = 0LL;
    FO(start,win_start,win_end) FO(end,start+1,win_end) {
      int min_sign = INF;
      int max_sign = -INF;
      FO(i,start+1,end) {
        MINUPDATE(min_sign, signs[i]);
        MAXUPDATE(max_sign, signs[i]);
      }

      if (min_sign == 0 && max_sign == 1) { result++; }
      if (min_sign == -1 && max_sign == 0) { result--; }
      cerr << endl; MSG(start); MSG(end); MSG(min_sign); MSG(max_sign); MSG(result);
    }
    cout << result << endl;
  }
}

void solve() {
  int N, K;
  cin >> N >> K;

  vector<int> upvotes(N);
  vector<int> signs(N, UNDEF);
  REP(i,N) {
    cin >> upvotes[i];
    if (i>0) {
      signs[i] = SGN(upvotes[i]-upvotes[i-1]);
    }
//     MSG(upvotes[i]); MSG(signs[i]); cerr << endl;
  }

  vector<pair<int, int>> non_zero_signs;
  FO(i,1,N) {
    if (signs[i] != 0) {
      non_zero_signs.PB(MP(i, signs[i]));
    }
  }
  cerr << "non_zero_signs: ";
  for (auto & sg: non_zero_signs) {
    cerr << sg.F << "(" << sg.S << ")\t";
  }
  cerr << endl;

//   // get maximal monotonous intervals
//   vector<int> left_ends(N, UNDEF);
//   vector<int> right_ends(N, UNDEF);
//   FO(i,1,N) {
//     if (abs(signs[i]) == 1) {
//       for (auto & di: {-1,1}) {
//         int pos = i + di;
//         while (0 < pos && pos < N) {
// 
//         }
//       }
//     }
//   }

//   long long result = 0LL;
//   for (int start = 1; start + k - 1 < signs.size(); start += 1) {
//     FO(pos,start,start + k - 1) {
//       result += signs[pos];   // TODO maximal intervals needed here
//     }
//   }
}

int main() {
  int cases;
//   cin >> cases;
  cases = 1;
  while (cases--) {
    solve_via_brute_force();
  }
  return 0;
}
