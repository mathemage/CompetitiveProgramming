#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define MSG(a) cout << #a << " == " << a << endl;

int main()
{
  int N;
  scanf("%d\n", &N);
  for (int i = 0; i < N; i++) {
    vector<string> words;
    string sentence, word;
    getline(cin, sentence);
    //MSG(sentence)
    for (char c : sentence) {
      if (c != ' ') word += c;
      else {
        //MSG(word)
        words.push_back(word);
        word.clear();
      }
    }
    words.push_back(word);

    reverse(words.begin(), words.end());

    cout << "Case #" << i+1 << ":";
    for (string w : words) {
      cout << " " << w;
    }
    cout << endl;

    words.clear();
  }

  return 0;
}

