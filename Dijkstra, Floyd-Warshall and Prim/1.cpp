#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#define INFINITY INT_MAX

using namespace std;

struct compare{
  bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    return p1.first > p2.first;
};

struct Graph{
  vector<vector<pair<int, int>>> adjacency_list;
  int V;
  vector<int> distances; //duzina najkraceg puta do tog trenutka
  vector<bool> path_found;
};

void initialize_graph (Graph &g, int V){
  g.V = V;
  g.adjacency_list.resize(V);
  g.distances.resize(V, INFINITY);  
  g.path_found.resize(V, false);
}

void add_edge(Graph &g, int u, int v, int weight){
  g.adjacency_list[u].push_back(make_pair(weight, v));
  g.adjacency_list[v].push_back(make_pair(weight, u));
}

void dijkstra(Graph &g, int u){

  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> heap;

  g.distances[u] = 0;

  heap.push(make_pair(g.distances[u], u));

  pair<int, int> tmp;

  while (!heap.empty()) {

    tmp = heap.top();
    heap.pop();

    if (g.path_found[tmp.second])
      continue;

    g.path_found[tmp.second] = true;

    // Prolazimo kroz listu suseda cvora tmp
    // tmp je par ciji je prvi element cvor a drugi cena najkraceg puta do tog cvora, tako da svuda gde nam treba cvor imamo tmp.first
    for (const pair<int, int> &neighbour : g.adjacency_list[tmp.second]) {
      // Ako preko cvora tmp imamo kraci put do nekog suseda onda azuriramo najkraci put do tog suseda i dodajemo ga na heap
      if (g.distances[neighbour.second] > g.distances[tmp.second] + neighbour.first) {
        // Azuriramo tezinu puta do cvora neighbour
        g.distances[neighbour.second] = g.distances[tmp.second] + neighbour.first;
        // Dodajemo cvor neighbour zajedno sa novom tezinom puta u heap
        heap.push(make_pair(g.distances[neighbour.first], neighbour.second));
      }
    }
  }

  cout << u << " -> " << 4 << " = " << g.distances[4] << "\n";
}

int main ()
{
  Graph g;

  initialize_graph(g, 9);

  add_edge(g, 0, 1, 4);
  add_edge(g, 0, 7, 8);
  add_edge(g, 1, 7, 11);
  add_edge(g, 1, 2, 8);
  add_edge(g, 2, 8, 2);
  add_edge(g, 2, 3, 7);
  add_edge(g, 7, 8, 7);
  add_edge(g, 7, 6, 1);
  add_edge(g, 8, 6, 6);
  add_edge(g, 2, 5, 4);
  add_edge(g, 6, 5, 2);
  add_edge(g, 3, 5, 14);
  add_edge(g, 3, 4, 9);
  add_edge(g, 4, 5, 10);

  dijkstra(g, 0);

  return 0;
}
