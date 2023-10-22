#include <../stringMatching.h>
#include <bits/stdc++.h>

using namespace std;

class KnuthMorrisPrattStringMatcher : public StringMatching {
  vector<int> prefixFunction;
  void calculatePrefixFunction() {
    prefixFunction[0] = -1;
    int currMatch = -1;
    for (int i = 1; i < lengthOfSearchString; i++) {
      while (currMatch >= 0 and searchString[currMatch + 1] != searchString[i])
        currMatch = prefixFunction[currMatch];
      if (searchString[currMatch + 1] == searchString[i]) currMatch++;
      prefixFunction[i] = currMatch;
    }
  }

 public:
  KnuthMorrisPrattStringMatcher(string dataString, string searchString)
      : StringMatching(dataString, searchString) {
    prefixFunction.resize(lengthOfSearchString);
    calculatePrefixFunction();
  }
  void findMatches() {
    int currMatch = -1;
    for (int i = 0; i < lengthOfDataString; i++) {
      while (currMatch >= 0 and searchString[currMatch + 1] != dataString[i])
        currMatch = prefixFunction[currMatch];
      if (searchString[currMatch + 1] == dataString[i]) currMatch++;
      if (lengthOfSearchString - 1 == currMatch) {
        printMessage(i - lengthOfSearchString + 1);
        totalMatches++;
        currMatch = prefixFunction[currMatch];
      }
    }
    cout << "Total matches found: " << totalMatches << endl;
  }
};

int main() {
  string dataString, searchString;
  cout << "Enter search string: ";
  getline(cin, searchString);
  cout << "Enter data string: ";
  getline(cin, dataString);
  KnuthMorrisPrattStringMatcher kmp(dataString, searchString);
  kmp.findMatches();

  return 0;
}
