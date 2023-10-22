// Doing sum of subsets using 0 1 kanpsack

#include <bits/stdc++.h>

using namespace std;

class DPKanpsack {
  int numberOfItems, capacityOfKnapsack;
  vector<pair<int, int>> items;
  vector<int> currRow, prevRow;

 public:
  DPKanpsack(int capacityOfKnapsack, vector<pair<int, int>> items) {
    this->numberOfItems = items.size();
    this->capacityOfKnapsack = capacityOfKnapsack;
    this->items = items;
    sort(this->items.begin(), this->items.end());
    currRow.resize(capacityOfKnapsack + 1);
    prevRow.resize(capacityOfKnapsack + 1, 0);
  }

  int findMaximumProfit() {
    for (int i = 0; i < numberOfItems; i++) {
      int j = 0;
      while (items[i].second > j) {
        currRow[j] = prevRow[j];
        j++;
      }
      while (j <= capacityOfKnapsack) {
        currRow[j] =
            max(prevRow[j], items[i].first + prevRow[j - items[i].second]);
        j++;
      }
      prevRow = currRow;
    }
    return currRow[capacityOfKnapsack];
  }
};

// Decision Problem of Subset Sum
class SumOfSubsetsUsingKanpsack {
  int sizeOfSet, requiedSum;
  unordered_set<int> setOfNumbers;

 public:
  SumOfSubsetsUsingKanpsack(int sizeOfSet, int requiedSum,
                            unordered_set<int> setOfNumbers) {
    this->sizeOfSet = sizeOfSet;
    this->requiedSum = requiedSum;
    this->setOfNumbers = setOfNumbers;
  }

  void findSubset() {
    vector<pair<int, int>> items;
    for (int setElement : setOfNumbers) {
      items.push_back({setElement, setElement});
    }

    DPKanpsack dpKanpsack(requiedSum, items);

    int maximumProfit = dpKanpsack.findMaximumProfit();

    if (maximumProfit == requiedSum) {
      cout << "Yes, there is a subset with sum " << requiedSum << endl;
    } else {
      cout << "No, there is no subset with sum " << requiedSum << endl;
    }
  }
};

int main() {
  int sizeOfSet, requiedSum;
  unordered_set<int> setOfNumbers;
  cout << "Enter the size of set : ";
  cin >> sizeOfSet;
  cout << "Enter the set of numbers : ";
  for (int i = 0; i < sizeOfSet; i++) {
    int temp;
    cin >> temp;
    setOfNumbers.insert(temp);
  }
  cout << "Enter the required sum : ";
  cin >> requiedSum;
  SumOfSubsetsUsingKanpsack sumOfSubsetsUsingKanpsack(sizeOfSet, requiedSum,
                                                      setOfNumbers);
  sumOfSubsetsUsingKanpsack.findSubset();

  return 0;
}
