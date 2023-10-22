#include <bits/stdc++.h>
#define Edge pair<int, int>
#define Vertex pair<int, int>
using namespace std;

class GreedyMinimumVertexCover {
  vector<Edge> edges;
  unordered_map<int, int> edgesRemaining;
  priority_queue<Vertex> vertices;
  set<int> answer;
  void reduceCount(int vertex) {
    vector<Edge> temp;
    for (Edge edge : edges) {
      if (edge.first == vertex) {
        edgesRemaining[edge.second]--;
        edgesRemaining[edge.first]--;
      } else if (edge.second == vertex) {
        edgesRemaining[edge.first]--;
        edgesRemaining[edge.second]--;
      } else {
        temp.push_back(edge);
      }
    }
    edges = temp;
    makeQueue();
  }
  void makeQueue() {
    vertices = priority_queue<Vertex>();
    for (pair<int, int> vertex : edgesRemaining) {
      if (0 >= vertex.second) continue;
      vertices.push(make_pair(vertex.second, vertex.first));
    }
  }
  void initialize() {
    for (Edge edge : edges) {
      edgesRemaining[edge.first]++;
      edgesRemaining[edge.second]++;
    }
    makeQueue();
  }

 public:
  GreedyMinimumVertexCover(vector<Edge> edges) : edges(edges) {}
  void findMVC() {
    initialize();
    while (!vertices.empty()) {
      Vertex currVertex = vertices.top();
      vertices.pop();
      reduceCount(currVertex.second);
      answer.insert(currVertex.second);
    }
    for (int vertex : answer) {
      cout << vertex << " ";
    }
  }
};

int main() {
  //   vector<Edge> edges = {{0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3,
  //   4}};
  vector<Edge> edges = {
      {1, 9},  {1, 10}, {1, 11}, {1, 12}, {1, 13}, {1, 14}, {2, 9},
      {2, 10}, {2, 11}, {2, 12}, {2, 13}, {3, 9},  {3, 10}, {3, 11},
      {3, 12}, {4, 9},  {4, 10}, {4, 11}, {5, 12}, {5, 13}, {5, 14},
      {6, 9},  {6, 10}, {7, 11}, {7, 12}, {8, 13}, {8, 14},
  };
  // above example fails in the greedy algorithm
  // actual answer is 9, 10, 11, 12, 13, 14
  // but the answer generated is 1, 2, 3, 4, 5, 6, 7, 8

  GreedyMinimumVertexCover greedyMVC(edges);
  greedyMVC.findMVC();
  return 0;
}
