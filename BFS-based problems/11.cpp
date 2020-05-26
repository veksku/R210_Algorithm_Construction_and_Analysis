#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph{
    vector<vector<int>> adjacency_list;
    int V;
    vector<bool> visited;
    vector<int> parents;
};

void initialize_graph(Graph &g, int V){
    g.V = V;
    g.adjacency_list.resize(V);
    g.visited.resize(V, false);
    g.parents.resize(V, -1);
}
//neusmereni graf
void add_edge(Graph &g, int u, int v){
    g.adjacency_list[u].push_back(v);
    g.adjacency_list[v].push_back(u);
}

void BFS(Graph &g, int u){
    queue<int> nodes;
    nodes.push(u);

    int pom;

    g.visited[u] = true;

    while(!nodes.empty()){
        pom = nodes.front();
        nodes.pop();

        auto begin = g.adjacency_list[pom].begin();
        auto end = g.adjacency_list[pom].end();
        // Ukoliko cvor nije posecen zelimo da ga posetimo (dodajemo ga u red) i kazemo da je trenutni cvor njegov roditelj
        if (!g.visited[*begin]) {
            g.visited[*begin] = true;
            g.parents[*begin] = pom;
            nodes.push(*begin);
        }
        // Inace ako je vec posecen i ako mu je roditelj razlicit od cvora koji se razmatra onda znaci da imamo ciklus i samo vracamo true
        else if (g.parents[pom] != *begin)
            return true;

        // Krecemo se kroz kolekciju
        begin++;
    }
}

int main(){
    Graph g;

    initialize_graph(g, 4);

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 0);
    add_edge(g, 2, 3);
    add_edge(g, 3, 3);

    // Graph g;
    // initialize_graph(g, 3);
    // add_edge(g, 0, 1);
    // add_edge(g, 1, 2);

    cout << BFS(g, 0) << endl;

  return 0;
}