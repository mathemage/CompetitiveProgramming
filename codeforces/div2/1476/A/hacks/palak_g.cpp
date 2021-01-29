#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int test_cases;
    cin >> test_cases;
 
    for (int q = 0; q < test_cases; q++) {
        int n, k;
        cin >> n >> k;
        int i = 2, x = k;
        while (n > x) {
            x = k * i;
            i++;
        }
        k = x;
        if (k % n == 0) {
            cout << k / n << endl;
        }
        else {
            cout << (k / n) + 1 << endl;
        }
    }
}
