#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline bool bounded(const T & x, const T & u, const T & l=0) {
  return min(l,u)<=x && x<max(l,u);
}

int mir(int d) {
  switch (d) {
    case 0:
    case 1:
    case 8: return d;
    case 2: return 5;
    case 5: return 2;
  }
  return -1e6;
}

int main() {
  int cases = 1;
  cin >> cases;
  while (cases--) {
    int h,m,hh,mm;
    cin >> h >> m;
    char sep;
    cin >> hh >> sep >> mm;
    while (!bounded(10*mir(mm%10)+mir(mm/10), h) || !bounded(10*mir(hh%10)+mir(hh/10), m)) {
      hh += ++mm/m;
      hh %= h;
      mm %= m;
    }
    cout << hh/10 << hh%10 << sep << mm/10 << mm%10 << endl;
  }
  return 0;
}
