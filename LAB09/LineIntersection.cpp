#include <bits/stdc++.h>
#define lineType pair<pair<int, int>, pair<int, int>>
#define pointType pair<int, int>
using namespace std;

class LineIntersection {
  lineType linePQ, lineRS;
  bool isOnSegment(lineType lineSegment, pointType pointToCheck) {
    if (pointToCheck.first >=
            min(lineSegment.first.first, lineSegment.second.first) and
        pointToCheck.first <=
            max(lineSegment.first.first, lineSegment.second.first))
      if (pointToCheck.second >=
              min(lineSegment.first.second, lineSegment.second.second) and
          pointToCheck.second <=
              max(lineSegment.first.second, lineSegment.second.second))
        return true;
    return false;
  }
  int findDirection(lineType lineSegment, pointType pointToCheck) {
    int directionValue =
        ((pointToCheck.first - lineSegment.first.first) *
         (lineSegment.second.second - lineSegment.first.second));
    directionValue -= ((pointToCheck.second - lineSegment.first.second) *
                       (lineSegment.second.first - lineSegment.first.second));
    return directionValue / abs(directionValue);
  }

 public:
  LineIntersection(lineType linePQ, lineType lineRS)
      : linePQ(linePQ), lineRS(lineRS) {}

  bool isIntersecting() {
    int directionPQR = findDirection(linePQ, lineRS.first);
    int directionPQS = findDirection(linePQ, lineRS.second);
    int directionRSP = findDirection(lineRS, linePQ.first);
    int directionRSQ = findDirection(lineRS, linePQ.second);

    if (directionPQR * directionPQS < 0 and directionRSP * directionRSQ < 0)
      return true;

    if (directionPQR == 0 and isOnSegment(linePQ, lineRS.first)) return true;
    if (directionPQS == 0 and isOnSegment(linePQ, lineRS.second)) return true;
    if (directionRSP == 0 and isOnSegment(lineRS, linePQ.first)) return true;
    if (directionRSQ == 0 and isOnSegment(lineRS, linePQ.second)) return true;

    return false;
  }
};

int main() {
  int x1, y1, x2, y2, x3, y3, x4, y4;
  cout << "Enter the coordinates of the first line segment: ";
  cin >> x1 >> y1 >> x2 >> y2;
  cout << "Enter the coordinates of the second line segment: ";
  cin >> x3 >> y3 >> x4 >> y4;
  LineIntersection lineIntersection(
      make_pair(make_pair(x1, y1), make_pair(x2, y2)),
      make_pair(make_pair(x3, y3), make_pair(x4, y4)));
  if (lineIntersection.isIntersecting())
    cout << "The two line segments intersect." << endl;
  else
    cout << "The two line segments do not intersect." << endl;
  return 0;
}
