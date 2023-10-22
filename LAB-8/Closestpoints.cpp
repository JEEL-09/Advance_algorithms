#include <bits/stdc++.h>

using namespace std;

class ClosestPoints {
  vector<pair<int, int>> points;
  int minDistance;
  pair<int, int> answer;
  int findDistance(pair<int, int> point1, pair<int, int> point2) {
    return pow(point1.first - point2.first, 2) +
           pow(point1.second - point2.second, 2);
  }

 public:
  ClosestPoints(vector<pair<int, int>> points) {
    this->points = points;
    minDistance = INT_MAX;
  }
  void findClosestPoints() {
    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        if (findDistance(points[i], points[j]) < minDistance) {
          minDistance = findDistance(points[i], points[j]);
          answer = {i, j};
        }
      }
    }
    cout << "Minimum distance: " << minDistance << endl;
    cout << "Closest points: (" << points[answer.first].first << ", "
         << points[answer.first].second << "), (" << points[answer.second].first
         << ", " << points[answer.second].second << ")" << endl;
  }
};

int main() {
  vector<pair<int, int>> points;
  int n;
  cout << "Enter number of points: ";
  cin >> n;
  cout << "Enter points: " << endl;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    points.push_back({x, y});
  }
  ClosestPoints cp(points);
  cp.findClosestPoints();
  return 0;
}
