/* ========================================

   ID: mathema6
   TASK: 40
   LANG: C++11
   (...for USACO solutions)

   * File Name : 40.cpp

   * Creation Date : 18-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL :

   * Points Gained (in case of online contest) :

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

#define ERR(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c))
    v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
  err(++it, args...);
}

//#define DEB
int main() {
  int n,t;
  cin >> t;
  REP(i,t) {
    cin >> n;
    vector<int> par(n);
    vector<vector<int>> kids(n);
    vector<int> rank(n,0);
    REP(j,n) {
      cin >> par[j];
      if (j > 0) {
        par[j]--;
        kids[par[j]].emplace_back(j);
        rank[par[j]]++;
      }
    }
    if (n == 1) {
      printf("Case #%d: 1\n", i+1);
      continue;
    }

#ifdef DEB
    cout << "parents: ";
    REP(j,n) {
      cout << par[j] << " ";
    }
    cout << "\nkids: " << endl;
    REP(j,n) {
      cout << j << ": ";
      for (int k = 0; k <  kids[j].size(); ++k) {
        cout << kids[j][k] << " ";
      }
      cout << endl;
    }
    cout << "ranks: ";
    REP(j,n) {
      cout << rank[j] << " ";
    }
    cout << endl << endl;
#endif

    queue<int> q;
    REP(j,n)
      if (rank[j] == 0)
        q.push(j);

    vector<long long> val(n);
    vector<int> lowest_pos(n);
    vector<vector<long long>> mins(n);
    while (q.size()) {
      int l = q.front();
      q.pop();
      int r = par[l];
      if (--rank[r] == 0)
        q.push(r);

      int d = kids[l].size()+1;
      if (d == 1) {
        mins[l] = {1, 2};
      } else {
        REP(v,d) val[v] = v+1;
        long long ground = 0;
        REP(ki,d-1) {
          int k = kids[l][ki];
          ground += mins[k][0];
          if (mins[k].size() > 1 && lowest_pos[k] < d) {
            val[lowest_pos[k]] += mins[k][1] - mins[k][0];
          }
        }

        // find 2 largest
        mins[l].emplace_back(val[0]);
        lowest_pos[l] = 0;
        FOR(a,1,d) {
          if (val[a] < mins[l][0]) {
            mins[l][0] = val[a];
            lowest_pos[l] = a;
          }
        }
        mins[l][0] += ground;

        int m2 = val[(lowest_pos[l]==0) ? 1 : 0];
        FOR(a,0,d)
          if (a != lowest_pos[l] && val[a] < m2)
            m2 = val[a];
        m2 += ground;

        if (m2 > mins[l][0])
          mins[l].emplace_back(m2);
      }
      /*
      ERR(l,d,lowest_pos[l],mins[l][0]);
      if (mins[l].size() > 1)
        ERR(mins[l][1]);
      cout << endl;  */
    }

#ifdef DEB
    REP(j,n) {
      cout << j << ": ";
      REP(k,mins[j].size()) cout << mins[j][k] << " ";
      cout << endl;
    }
#endif
    printf("Case #%d: %ld\n", i+1, mins[0][0]);
  }

  return 0;
}
