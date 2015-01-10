/* ========================================

   ID: mathema6
   TASK: 55
   LANG: C++11
   (...for USACO solutions)

   * File Name : 55.cpp

   * Creation Date : 10-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/hackercup/problems.php?pid=1523599254559737&round=742632349177460

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;
// #define MSG(a) ;

int t, m, n, pos;
vector<string> maze;
vector<bool> visited;

const int tag = -1;
const vector<pair<int, int>> directions = { {0,1}, {1,0}, {0,-1}, {-1,0} };
const string laser = "<^>v";

void setVisit(int p, int steps) {
  visited[4*p + (steps%4)] = true;
}

bool isSafe(int p, int steps) {
  REP(i,4) {
    pair<int, int> d = directions[i];
    int x = p / n, y = p % n;

    x += d.first;
    y += d.second;
    while (x >= 0 && x < m && y >= 0 && y < n) {
      if (maze[x][y] == laser[(i + 4-steps%4) % 4])
        return false;
      if (maze[x][y] != '.' && maze[x][y] != 'G')
        break;

      x += d.first;
      y += d.second;
    }
  }
  return true;
}

int main() {
  cin >> t;
  REP(i,t) {
    cout << "Case #" << i+1 << ": ";

    cin >> m >> n;
    maze.resize(m);
    visited.assign(4*m*n, false);
    queue<int> q;
    int steps = 0;

    REP(j,m) {
      cin >> maze[j];
      REP(k,n) {
        if (maze[j][k] == 'S') {
          q.push(j*n + k);
          setVisit(j*n + k, steps);

          q.push(tag);
          maze[j][k] = '.';
        }
      }
    }

    while (!q.empty()) {
      pos = q.front();
      q.pop();
      if (pos == tag) {
        steps++;
        if (!q.empty())
          q.push(tag);
        continue;
      }

      if (maze[pos/n][pos%n] == 'G') {
        break;
      }

      for (pair<int, int> d : directions) {
        int x = pos / n + d.first, y = pos % n + d.second;
        if (x < 0 || x >= m) continue;
        if (y < 0 || y >= n) continue;
        if (maze[x][y] != '.' && maze[x][y] != 'G') continue;
        int npos = x * n + y;

        if (!visited[4*npos + (steps+1)%4] && isSafe(npos, steps+1)) {
          q.push(npos);
          setVisit(npos, steps+1);
        }
      }
    }

    if (pos != -1 && maze[pos/n][pos%n] == 'G')
      cout << steps;
    else
      cout << "impossible";
    cout << endl;
  }
  return 0;
}
