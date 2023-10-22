#include <../stringMatching.h>
#include <bits/stdc++.h>

using namespace std;

class NaiveAlgorithm : public StringMatching {
  bool matchString(int indexToSearch) {
    for (int i = 0; i < lengthOfSearchString; i++) {
      if (dataString[indexToSearch + i] != searchString[i]) return false;
    }
    return true;
  }

 public:
  NaiveAlgorithm(string dataString, string searchString)
      : StringMatching(dataString, searchString) {}

  void findMatches() {
    for (int i = 0; i < lengthOfDataString - lengthOfSearchString + 1; i++) {
      if (matchString(i)) {
        printMessage(i);
        totalMatches++;
      }
    }
    cout << "Total matches are : " << totalMatches << endl;
  }
};

int main() {
  string dataInput, searchInput;
  cout << "Enter Data String : ";
  getline(cin, dataInput);
  cout << "Enter String to Search in Data : ";
  getline(cin, searchInput);

  cout << endl << "By Naive Algorithm : " << endl;
  NaiveAlgorithm naiveAlgorithm(dataInput, searchInput);
  naiveAlgorithm.findMatches();

  return 0;
}
