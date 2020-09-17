#include <iostream>
#include <vector>

using namespace std;

struct Graph{
    vector<vector<int>> adjacency_list;
    int V;
    vector<bool> visited;
};

void initialize_graph(Graph &g, int V){
    g.V = V;
    g.adjacency_list.resize(V);
    g.visited.resize(V, false);
}

void add_edge(Graph &g, int u, int v){
    g.adjacency_list[u].push_back(v);
    g.adjacency_list[v].push_back(u);
}

bool DFS(Graph &g, int u, int parent){
    g.visited[u] = true;

    auto begin = g.adjacency_list[u].begin(); 
    auto end = g.adjacency_list[u].end();

    while(begin != end){
        if(g.visited[*begin]){
            if(*begin != parent)
                return true;
        }
        else if(DFS(g, *begin, u))
            return true;
        begin++;
    }

    return false;
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

    if(DFS(g, 0, -1))
        cout << "Graf ima ciklus\n";
    else
        cout << "Graf nema ciklus\n";

    return 0;
}