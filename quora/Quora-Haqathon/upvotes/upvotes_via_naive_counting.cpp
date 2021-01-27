 
/* ========================================
   * File Name : upvotes.cpp
   * Creation Date : 22-01-2021
   * Last Modified : St 27. ledna 2021, 21:08:32
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://www.hackerrank.com/contests/quora-haqathon/challenges/upvotes
   * Points/Time : (1h 31 m 10 s (previous) + ) = 
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
const int UNDEF = INT_MAX;
const int INF = INT_MAX;

void solve_via_naive_counting() {
  int N, K;
  cin >> N >> K;
  if (N == 1) {
    cout << 0 << endl;
    return;
  }

  vector<int> upvotes(N);
  vector<int> signs(N, UNDEF);
  REP(i,N) {
    cin >> upvotes[i];
    if (i>0) {
      signs[i] = SGN(upvotes[i]-upvotes[i-1]);
    }
//     MSG(upvotes[i]); MSG(signs[i]); cerr << endl;
//     cerr << signs[i] << " ";
  }
//   cerr << endl;

  vector<int> pm_l_end_pos, pm_l_end_sgn;
  vector<int> pm_r_end_pos, pm_r_end_sgn;

  vector<pair<int, int>> pm_sgn;
  pm_l_end_pos.PB(1); pm_l_end_sgn.PB(signs[1]);
  FO(i,1,N) {
    if (signs[i] != 0) {
      if (!pm_sgn.empty() && pm_sgn.back().S == -signs[i]) {
        pm_r_end_pos.PB(i-1);
        pm_r_end_sgn.PB(pm_sgn.back().S);

        pm_l_end_pos.PB(pm_sgn.back().F+1);
        pm_l_end_sgn.PB(signs[i]);
      }

      pm_sgn.PB(MP(i, signs[i]));
    }
  }
  pm_r_end_pos.PB(N-1);
  pm_r_end_sgn.PB(pm_sgn.back().S);

//   cerr << "pm_sgn: ";
//   for (auto & sg: pm_sgn) {
//     cerr << sg.F << "(" << sg.S << ")\t";
//   }
//   cerr << endl;
//   cerr << "pm_lr_end_pos_sgn: ";
//   for (int j = 0; j < pm_l_end_pos.size(); j += 1) {
//     cerr << "[" << pm_l_end_pos[j] << ","  << pm_r_end_pos[j] << "]";
//     cerr << "(" << pm_l_end_sgn[j] << ","  << pm_r_end_sgn[j] << ")\t";
//   }
//   cerr << endl;

  int win_start = 0, win_end=win_start+K-1;
//   int i_l = 0;
//   int i_r = 0;
//   while (! (pm_l_end_pos[i_r] <= win_end && win_end <= pm_r_end_pos[i_r]) ) {
//     i_r++;  // TODO test
//   }

  for (win_start=1, win_end=win_start+K-1 ; win_end < N; win_start++, win_end++) {
//     cerr << endl << endl; MSG(win_start); MSG(win_end);
    long long result = 0LL;
    FO(start,win_start,win_end) FO(end,start+1,win_end) {
      int min_sign = INF;
      int max_sign = -INF;
      FO(i,start+1,end) {
        MINUPDATE(min_sign, signs[i]);
        MAXUPDATE(max_sign, signs[i]);
      }

      if (min_sign >= 0 && max_sign == 1) { result++; }
      if (min_sign == -1 && max_sign <= 0) { result--; }
//       cerr << endl; MSG(start); MSG(end); MSG(min_sign); MSG(max_sign); MSG(result);
    }

//   // get maximal monotonous intervals
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

    cout << result << endl;
  }
}

int main() {
  int cases;
//   cin >> cases;
  cases = 1;
  while (cases--) {
    solve_via_naive_counting();
  }
  return 0;
}
