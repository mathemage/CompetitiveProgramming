#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cstdio>

using namespace std;

bool isRepeated(string seq) {
  short pos[26][3];
  vector<short> posSizes(26);
  short c;
  for (int i = 0; i < seq.size(); i++) {
    c = seq[i] - 'a';
    if (posSizes[c] <= 3) {
      pos[c][ ++posSizes[c]-1 ] = i;
    } else {
      return true;
    }
  }

  int a, b;
  for (int i = 0; i < 26; i++) {
    if (posSizes[i] < 2) continue;
    for (int j = i + 1; j < 26; j++) {
      if (posSizes[j] < 2) continue;

      a = i; b = j;
      if (pos[a][0] > pos[b][0]) {
        swap(a, b);
      }

      if (pos[b][0] < pos[a][1]
          && pos[a][1] < pos[b][ posSizes[b]-1 ])
        return true;
    }
  }
  return false;
}

int main()
{
  assert(isRepeated("abab") == true);
  printf("abab is repeated.\n");
  assert(isRepeated("abba") == false);
  printf("abba is not repeated.\n");
  assert(isRepeated("acbdaghfb") == true);
  printf("acbdaghfb is repeated.\n");
  assert(isRepeated("abcdacb") == true);
  printf("abcdacb is repeated.\n");
  return 0;
}
