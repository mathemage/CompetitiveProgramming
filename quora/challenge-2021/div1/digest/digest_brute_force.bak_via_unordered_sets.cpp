 
/* ========================================
   * File Name : digest_brute_force.cpp
   * Creation Date : 06-02-2021
   * Last Modified : So 6. února 2021, 16:12:30
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL :
   * Points/Time :
   * Total/ETA : 25m
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

void print_queue(queue<long long> q, string name) {
  cerr << name << ": ";
	while (!q.empty()){
		cerr << q.front() << "  ";
		q.pop();
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
  vector<unordered_set<int>> follows_users(p+5);
  int i,j,k;
  REP(f,p) {
    cin >> i >> j;
    follows_users[i].insert(j);
  }
  vector<unordered_set<int>> follows_story(q+5);
  vector<unordered_set<int>> follows_story_author(q+5);
  REP(f,q) {
    cin >> i >> k;
    follows_story[i].insert(k);
    follows_story_author[i].insert(story_authors[k]);
  }

  vector<unordered_set<int>> follows_story_followed_by(m); // TODO
  REP(i,m) REP(j,m) {

  }

  long long result[3] = {UNDEF, UNDEF, UNDEF};
  long long aj,bj;
  REP(i,m) {
    vector<long long> story_scores(n,0LL);
    REP(k,n) {
      if (story_authors[k]==i || SETCONTAINS(follows_story[i],k)) {
        story_scores[k]=-1;
        continue;
      }

      REP(j,m) {
        /* aj */
        if (i==j) {
          continue;
        } else if (SETCONTAINS(follows_users[i],j)) {
          aj=3;
        } else if (SETCONTAINS(follows_story_author[i],j)) {
          aj=2;
        } else if (true) { // TODO
          aj=1;
        } else {
          continue;
        }

        /* bj */
        if (story_authors[k]==j) {
          bj=2;
        } else if (SETCONTAINS(follows_story[j],k)) {
          bj=1;
        } else {
          continue;
        }

        story_scores[k] += aj*bj;
      }
    }

    /* DEBUG-print */
    print_vector(story_scores, "story_scores");
    /***************/
    REP(res_idx,3) {
      cout << result[res_idx] << (res_idx!=2? " " : endl);
    }
  }
}

int main() {
  int cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
