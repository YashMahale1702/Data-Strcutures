#include <bits/stdc++.h>

using namespace std;

class Graph {
  int vertices;
  list<int> *l; // array of doubly ll

public:
  Graph(int vertices) {
    this->vertices = vertices;
    this->l = new list<int>[vertices];
  }

  void addEdge(int i, int j, bool undirected = true) {
    if (!undirected) {
      l[i].push_back(j);
    } else {
      l[i].push_back(j);
      l[j].push_back(i);
    }
  }

  void printAdjacencyList() {
    for (int i = 0; i < vertices; i++) {
      cout << i << " -> ";
      for (auto node : l[i]) {
        cout << node << " ";
      }
      cout << endl;
    }
  }

  void breadthFirstSearch(int source) {
    queue<int> que;
    bool visited[vertices] = {false};

    que.push(source);
    visited[source] = true;

    // there are no neighbours left
    while (!que.empty()) {
      // print
      int temp = que.front();
      cout << temp << " ";
      que.pop();

      // push neighbours
      for (auto neighbour : l[temp]) {
        if (visited[neighbour] == false) {
          que.push(neighbour);
          visited[neighbour] = true;
        }
      }
    }
  }

  void dfsHelper(int node, bool *visited) {
    visited[node] = true;
    cout << node << " ";

    // call for neighbours
    for (int neighbour : l[node]) {
      if (visited[neighbour] == false) {
        dfsHelper(neighbour, visited);
      }
    }
    return;
  }

  void dfs(int source) {
    bool *visited = new bool[vertices]{0};
    dfsHelper(source, visited);
  }
};

int main() {
  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(3, 5);
  g.addEdge(4, 5);
  g.addEdge(5, 6);
  g.addEdge(0, 4);

  g.printAdjacencyList();
  g.breadthFirstSearch(5);
  cout << "\n";
  g.dfs(0);
}