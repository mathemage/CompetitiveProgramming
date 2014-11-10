#include <vector>
#include <iostream>
#include <string>
using namespace std;

class BinaryCode {
public:
  vector <string> decode(string message) {
    vector <string> result;
    unsigned len = message.length() + 2;
    int P[len];
    int Q[len];
    Q[0] = Q[len-1] = 0;
    for (unsigned i = 0; i < message.length(); i++) {
      Q[i+1] = message[i] - '0';
    }

    for (int init = 0; init <= 1; init++) {
      P[0] = 0;
      P[1] = init;
      for (unsigned i = 2; i < len; i++) {
        P[i] = Q[i-1] - P[i-1] - P[i-2];
      }

      string orig;
      if (P[len-1] != 0) {
        orig = "NONE";
      } else {
        for (unsigned i = 1; i <= message.length(); i++) {
          //cout << char('0' + P[i]) << " added..." << endl;
          if (P[i] == 0 || P[i] == 1) {
            orig += ('0' + P[i]);
          } else {
            orig = "NONE";
            break;
          }
        }
      }

      result.push_back(orig);
    }
    return result;
  }

  void disp(string message) {
    cout << decode(message)[0] << endl
         << decode(message)[1] << endl;
  }
};

int main() {
  BinaryCode bc;
  bc.disp("123210122");
  bc.disp("22111");
}
