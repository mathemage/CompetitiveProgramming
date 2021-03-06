 
/* ========================================

   * File Name : 15.cpp

   * Creation Date : 25-07-2020

   * Last Modified : So 25. července 2020, 14:13:10

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/codingcompetitions/hacker-cup/2020/qualification-round/problems/B

   * Points Gained (in case of online contest) :

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << (a) << endl;

const int CLEAN = -1;

template <typename T>
string NumberToString ( T Number ) {
  ostringstream ss;
  ss << Number;
  return ss.str();
}

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
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << endl;
  err(++it, args...);
}

int main() {
  int T;
  cin >> T;
//   MSG(T)

  long long N;
  char Ci;
  REP(i,T) {
    cin >> N;
//     MSG(N)

    long long n_A = 0;
    long long n_B = 0;
    REP(j,N) {
      cin >> Ci;
//       MSG(Ci)

      switch (Ci) {
        case 'A':
          n_A++;
          break;
        case 'B':
          n_B++;
          break;
        default:
          return EXIT_FAILURE;
      }
    }
//     MSG(n_A) MSG(n_B) 
//     MSG(max(n_A, n_B)) MSG(min(n_A, n_B))
    
    char result = (max(n_A, n_B) - min(n_A, n_B) == 1) ? 'Y' : 'N';
    cout << "Case #" << i + 1 << ": " << result << endl;
  }

  return 0;
}
