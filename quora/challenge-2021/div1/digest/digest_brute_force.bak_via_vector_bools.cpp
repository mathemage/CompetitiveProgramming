 
/* ========================================
   * File Name : digest_brute_force.cpp
   * Creation Date : 06-02-2021
   * Last Modified : So 6. února 2021, 17:12:23
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL :
   * Points/Time :
   * - 2h 3m 40s
   * Total/ETA : 25m
   * Status : 
   * - 76/100 (Execution killed (could be triggered by violating memory limits))
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
#define SETCONTAINS(S,E) ((S).find(E) != (S).end())

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


void print_vector(vector<long long> vec, string name) {
  cerr << name << ": ";
  for (auto & x: vec) {
    cerr << x << "  ";
  }
  cerr << endl;
}

void solve() {
  int n,m;
  cin >> n >> m;
  vector<int> story_authors(n+5);
  FO(k,1,n) {
    cin >> story_authors[k];
  }

  int p,q;
  cin >> p >> q;
  vector<vector<bool>> follows_users(p+5, vector<bool>(m+5,false));
  int i,j,k;
  REP(f,p) {
    cin >> i >> j;
    follows_users[i][j]=true;
  }
  vector<vector<bool>> follows_story(q+5, vector<bool>(n+5,false));
  vector<vector<bool>> follows_story_author(q+5, vector<bool>(m+5,false));
  REP(f,q) {
    cin >> i >> k;
    follows_story[i][k]=true;
    follows_story_author[i][story_authors[k]]=true;
  }

  vector<vector<bool>> follows_story_followed_by(m+5, vector<bool>(m+5,false)); // TODO
  FO(i,1,m) FO(j,i+1,m) {
    FO(k,1,n) {
      if (follows_story[i][k] && follows_story[j][k]) {
        follows_story_followed_by[i][j]=true;
        follows_story_followed_by[j][i]=true;
        break;
      }
    }
  }

  long long aj,bj;
  vector<long long> story_scores;
  vector<pair<long long, int>> top3;
  FO(i,1,m) {
//     MSG(i);
    story_scores.assign(n+5,0LL);
    top3.clear();
//     MSG(top3.size());
//     cerr << "here" << endl;
    FO(k,1,n) {
//       MSG(k);
      if (story_authors[k]==i || follows_story[i][k]) {
        story_scores[k]=-1;
        continue;
      }

      FO(j,1,m) {
//         MSG(j);
        /* aj */
        if (i==j) {
          continue;
        } else if (follows_users[i][j]) {
          aj=3;
        } else if (follows_story_author[i][j]) {
          aj=2;
        } else if (follows_story_followed_by[i][j]) {
          aj=1;
        } else {
          continue;
        }

        /* bj */
        if (story_authors[k]==j) {
          bj=2;
        } else if (follows_story[j][k]) {
          bj=1;
        } else {
          continue;
        }

//         MSG(aj); MSG(bj);
        story_scores[k] += aj*bj;
      }

      top3.PB(MP(-story_scores[k], k));
      sort(ALL(top3));
      if (top3.size() > 3) {
        top3.resize(3);
      }
//       MSG(top3.size());
    }

    /* DEBUG-print */
//     print_vector(story_scores, "story_scores");
    /***************/

    int res_idx = 0;
    for (auto & result: top3) {
      cout << result.S << (++res_idx==3? endl:" ");
    }
//     MSG(res_idx); cerr << endl;
  }
}

int main() {
  int cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}