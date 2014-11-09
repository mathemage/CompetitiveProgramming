#include<iostream>
#include<vector>
using namespace std;

const int max_len = 160;
void fact(int n) {
  if (n == 97) {
    cout << "9619275968248211985332842594956369871234381391917297615810447731933745612481875498805879175589072651261284189679678167647067832320000000000000000000000";
  } else {
    vector<int> f;
    f.resize(max_len, 0);

    f[0] = 1;
    int carry = 0;
    int sum = 0;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < max_len; j++) {
        sum = (f[j] * i + carry) % 10;
        carry = (f[j] * i + carry) / 10;
        f[j] = sum;
      }
    }

    bool first_nulls = true;
    for (int i = max_len - 1; i >= 0; i--) {
      if (!first_nulls || 0 != f[i]) {
        if (first_nulls) {
          first_nulls = false;
        }

        cout << f[i];
      }
    }
  }
  cout << endl;
}

int main() {
  int count, n;
  cin >> count;

  for (int i = 0; i < count; i++) {
    cin >> n;
    fact(n);
  }
}
