#include <bits/stdc++.h>

using namespace std;

class Node {

public:
  string name;
  list<string> neighbours;
  Node(string name) { this->name = name; }
};

class Graph {
  unordered_map<string, Node *> map;

public:
  Graph(vector<string> cities) {
    for (auto city : cities) {
      map[city] = new Node(city);
    }
  }

  void addEdge(string city1, string city2, bool undirected = false) {
    if (undirected) {
      map[city1]->neighbours.push_back(city2);
      map[city2]->neighbours.push_back(city1);
    } else {
      map[city1]->neighbours.push_back(city2);
    }
  }

  void printList() {
    for (auto cityPair : map) {
      cout << cityPair.second->name << "'s neighbours -> ";
      for (auto neighbours : cityPair.second->neighbours) {
        cout << neighbours << ", ";
      }
      cout << endl;
    }
  }
};

int main() {

  vector<string> cities = {"hubli", "delhi", "mumbai", "goa"};
  Graph g(cities);

  g.addEdge("hubli", "goa");
  g.addEdge("hubli", "delhi");
  g.addEdge("hubli", "mumbai");
  g.addEdge("mumbai", "goa");
  g.addEdge("delhi", "mumbai");
  // g.addEdge("delhi", "mumbai");

  g.printList();
}