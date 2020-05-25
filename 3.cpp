#include <iostream>
#include <vector>

using namespace std;

struct Graph{
    vector<vector<int>> adjacency_list;
    int V;
    vector<bool> visited;

    int cluster;
}

initialize_graph(Graph &g, V){
    g.V = V;
    g.visited.resize(V);
    g.adjacency_list.resize(V);
}

add_edge(Graph &g, u, v){
    g.adjacency_list[u].push_back(v);
}

int main(){
    int u, v;
    
    cin >> u >> v;

    Graph g;

    initialize_graph(g, 6)

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 0);
    add_edge(g, 2, 3);
    add_edge(g, 3, 3);
    add_edge(g, 4, 5);
    add_edge(g, 4, 4);
    add_edge(g, 5, 4);


}