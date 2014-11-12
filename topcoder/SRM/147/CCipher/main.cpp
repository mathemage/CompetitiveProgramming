#include<string>
using namespace std;

class CCipher {
public:
	string decode(string cipherText, int shift) {
		string orig;
		for (char c : cipherText) {
			orig += 'A' + (c - 'A' - shift) % 26 ;
			//orig.append();
		}
		return orig;
	}
};
