#include<cassert>
#include<string>
using namespace std;

class CCipher {
public:
  string decode(string cipherText, int shift) {
    string orig;
    for (char c : cipherText) {
      orig += 'A' + (c - 'A' - shift + 26) % 26 ;
    }
    return orig;
  }
};

int main() {
  CCipher cc;
  assert(cc.decode("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10) == "QRSTUVWXYZABCDEFGHIJKLMNOP");
}
