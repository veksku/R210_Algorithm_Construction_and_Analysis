#include <iostream>
#include <vector>

using namespace std;

struct Graph{
    vector<vector<int>> adjacency_list;
    int V;
    vector<bool> visited;
    bool has_cycle;
};

void initialize_graph(Graph &g, int V){
    g.V = V;
    g.adjacency_list.resize(V);
    g.visited.resize(V,false);
    g.has_cycle = false;
}

void add_edge(Graph &g, int u, int v){
    g.adjacency_list[u].push_back(v);
}

void DFS(Graph &g, int u){
    g.visited[u] = true;

    auto begin = g.adjacency_list[u].begin();
    auto end = g.adjacency_list[u].end();

    while(begin != end){
        if(g.visited[*begin]){
            g.has_cycle = true;
            return;
        }
        else
            DFS(g, *begin);

        begin++;
    }
}

int main(){
    Graph g;

    initialize_graph(g, 4);

    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 2, 0);

    DFS(g, 0);

    if(g.has_cycle)
        cout << "postoji ciklus!";
    else
        cout << "ne postoji ciklus!";
    cout << endl;

    return 0;
}