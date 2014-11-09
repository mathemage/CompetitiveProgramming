#include <iostream>
using namespace std;

int main() {
	int num = 0;
	while (!cin.eof() && 42 != num) {
		cin >> num;
		if (num < 100 && num != 42) {
			cout << num;
		}
	}
	
	return 0;
}
