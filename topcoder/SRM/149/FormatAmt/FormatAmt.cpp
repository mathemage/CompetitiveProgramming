#include<string>
using namespace std;

class FormatAmt {
public:
	string amount(int dollars, int cents) {
		string res = "$";
		string d = to_string(dollars);
		int len = d.length();
		for (int i = 0; i < len - 1; i++) {
			res += d[i];
			if ((len - i - 1) % 3 == 0) {
				res += ',';
			}
		}
		res += d[len-1];
		res += ".";
		res += (cents < 10) ? "0" : "";
		res += to_string(cents);
		return res;
	}
};
