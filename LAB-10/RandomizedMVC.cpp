#include <bits/stdc++.h>
#define Edge pair<int, int>
using namespace std;

class RandomizedMinimumVertexCover {
  vector<Edge> edges;
  int edgesRemaining;
  set<int> answer;
  void reduceEdges(int vertex) {
    vector<Edge> temp;
    for (Edge edge : edges) {
      if (edge.first == vertex or edge.second == vertex) {
        edgesRemaining--;
      } else {
        temp.push_back(edge);
      }
    }
    edges = temp;
  }

 public:
  RandomizedMinimumVertexCover(vector<Edge> edges, int vertexCount)
      : edges(edges) {
    edgesRemaining = edges.size();
  }
  void findMVC() {
    srand(time(NULL));
    while (0 < edgesRemaining) {
      int currIndex = rand() % edgesRemaining;
      Edge currEdge = edges[currIndex];
      answer.insert(currEdge.first);
      answer.insert(currEdge.second);
      reduceEdges(currEdge.first);
      reduceEdges(currEdge.second);
    }
    for (int vertex : answer) {
      cout << vertex << " ";
    }
  }
};

int main() {
  vector<Edge> edges = {{0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}};
  //   vector<Edge> edges = {{0, 1}, {1, 2}, {2, 3}};
  RandomizedMinimumVertexCover randMVC(edges, 5);
  randMVC.findMVC();
  return 0;
}
