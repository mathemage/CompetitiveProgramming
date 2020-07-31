 
/* ========================================

   * File Name : 21.cpp

   * Creation Date : 27-07-2020

   * Last Modified : Pá 31. července 2020, 18:24:35

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/codingcompetitions/hacker-cup/2020/qualification-round/problems/C

   * Points Gained (in case of online contest) : 0 (AC)

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

  REP(t,T) {
    long N;
    cin >> N;
//     MSG(N)

    vector<pair<long, long>> PH(N);
    REP(n,N) {
      cin >> PH[n].first >> PH[n].second;
    }
//     MSG(PH.size())

    sort(ALL(PH));
//     REP(n,N) {
//       cout << PH[n].first << " " << PH[n].second << endl;
//     }

    unordered_map<long, long> left_end_of; 
    long longest_interval = 0;
    for (auto & ph: PH) {
      long p = ph.first;
      long h = ph.second;

//       cout << "map before:" << endl;
//       for (auto m: left_end_of) {
//         cout << m.first << " -> " << m.second << endl;
//       }

      // fall left
      long left_fall = p - h;
      auto l_query = left_end_of.find(left_fall);
      long l_ans = (l_query == left_end_of.end()) ? left_fall : l_query->second;
//       MSG(l_query == left_end_of.end())
//       MSG((l_query == left_end_of.end()) ? left_fall : l_query->second)

      // fall right
      long right_fall = p + h;
      auto r_query = left_end_of.find(p);
      long r_ans = (r_query == left_end_of.end()) ? p : r_query->second;

      if (left_end_of.find(p) != left_end_of.end()) {
        l_ans = min(l_ans, left_end_of[p]);
      }
      left_end_of[p] = l_ans;
      long len1 = p - left_end_of[p];
//       MSG(p) MSG(left_end_of[p])

      if (left_end_of.find(right_fall) != left_end_of.end()) {
        r_ans = min(r_ans, left_end_of[right_fall]);
      }
      left_end_of[right_fall] = r_ans;
      long len2 = right_fall - left_end_of[right_fall];
//       MSG(right_fall) MSG(left_end_of[right_fall])

//       cout << "map after:" << endl;
//       for (auto m: left_end_of) {
//         cout << m.first << " -> " << m.second << endl;
//       }

      longest_interval = max(longest_interval, max(len1, len2));
//       MSG(p) MSG(longest_interval) MSG(len1) MSG(len2) cout << endl;
    }

    long result = longest_interval;
    cout << "Case #" << t + 1 << ": " << result << endl;
  }
  return 0;
}
