#include <iostream>
#include <unordered_map>
#include <vector>

struct Edge {
  int to;
  int weight;
};

int findLoop(const std::vector<std::vector<Edge>>& graph, int N) {
  std::unordered_map<int, int> sums;
  int closestSum = INT_MAX;

  for (int start = 0; start < graph.size(); start++) {
    std::vector<bool> visited(graph.size(), false);
    std::vector<int> stack{start};
    sums[start] = 0;
    while (!stack.empty()) {
      int curr = stack.back();
      stack.pop_back();
      visited[curr] = true;
      if (sums.count(curr) > 0) {
        int loopSum = sums[curr];
        if (std::abs(loopSum - N) < std::abs(closestSum - N)) {
          closestSum = loopSum;
        }
      }
      for (const Edge& edge : graph[curr]) {
        if (!visited[edge.to]) {
          stack.push_back(edge.to);
          sums[edge.to] = sums[curr] + edge.weight;
        }
      }
    }
  }

  return closestSum;
}

int main() {
  std::vector<std::vector<Edge>> graph(4);
  graph[0].push_back({1, 3});
  graph[1].push_back({2, 1});
  graph[2].push_back({3, 2});
  graph[3].push_back({0, 4});
  graph[3].push_back({1, 5});

  std::cout << findLoop(graph, 7) << std::endl;
}
