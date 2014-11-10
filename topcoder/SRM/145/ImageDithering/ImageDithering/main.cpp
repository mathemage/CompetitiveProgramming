#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class ImageDithering {
public:
  int count(string dithered, vector<string> screen) {
    unsigned d[26];
    for (int i = 0; i < 26; i++) {
      d[i] = 0;
    }
    for (unsigned i = 0; i < dithered.length(); i++) {
      d[dithered[i] - '0'] = 1;
    }
    int count = 0;

    for (vector<string>::iterator str = screen.begin(); str != screen.end(); ++str) {
      for (unsigned i = 0; i < str->length(); i++) {
        count += d[(*str)[i] - '0'];
      }
    }

    return count;
  }
};

int main()
{
  ImageDithering id;
  string sc[] = {
    "AAAAAAAA",
    "ABWBWBWA",
    "AWBWBWBA",
    "ABWBWBWA",
    "AWBWBWBA",
    "AAAAAAAA"
  };
  vector<string> scr1(sc, sc + 6);
  assert( id.count("BW", scr1) == 24);

  return 0;
}

