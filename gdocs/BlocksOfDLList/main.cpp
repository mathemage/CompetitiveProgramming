#include<iostream>
#include<unordered_set>
#include<cassert>
using namespace std;
#define MSG(a) cout << #a << " == " << a << endl;

struct lnode {
  lnode *prev, *next;
};

int countBlocks(lnode *head, lnode *refs[], int refSize) {
  unordered_set<lnode*> refSet(refs, refs+refSize);
  bool inBlock = false;
  int blocks = 0;
  for (lnode *cur = head; cur != NULL; cur = cur->next) {
    if (refSet.find(cur) != refSet.end()) {
      if (!inBlock) blocks++;
      inBlock = true;
    } else {
      inBlock = false;
    }
  }
  return blocks;
}

#define sz 4
#define rsz 3
int main()
{
  lnode dLList[sz];
  dLList[0].prev = dLList[sz-1].next = NULL;
  for (int i = 0; i < sz; i++) {
    if (i > 0) dLList[i].prev = &dLList[i-1];
    if (i < sz-1) dLList[i].next = &dLList[i+1];
  }

  lnode *refs0[rsz] = { dLList, dLList + 2, dLList + 3 };
  assert(countBlocks(dLList, refs0, rsz) == 2);
  cout << countBlocks(dLList, refs0, rsz) << " block(s)" << endl;

  lnode *refs1[rsz] = { dLList, dLList + 1, dLList + 2 };
  assert(countBlocks(dLList, refs1, rsz) == 1);
  cout << countBlocks(dLList, refs1, rsz) << " block(s)" << endl;

  lnode *refs2[4] = { dLList, dLList + 1, dLList + 2, dLList + 3 };
  assert(countBlocks(dLList, refs2, 4) == 1);
  cout << countBlocks(dLList, refs2, 4) << " block(s)" << endl;

  lnode *refs3[0] = {};
  cout << countBlocks(dLList, refs3, 0) << " block(s)" << endl;
  assert(countBlocks(dLList, refs3, 0) == 0);

  return 0;
}
