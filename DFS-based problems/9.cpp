#include <iostream>
#include <vector>

using namespace std;

struct Graph{
    vector<vector<int>> adjacency_list;
    int V;
    vector<bool> visited;
    int num_of_nodes;
};

void initialize_graph(Graph &g, int V){
    g.V = V;
    g.adjacency_list.resize(V);
    g.visited.resize(V, false);
    g.num_of_nodes = 0;
}

void add_edge(Graph &g, int u, int v){
    g.adjacency_list[u].push_back(v);
}

void DFS(Graph &g, int u, int level, int current_level){
    g.visited[u] = true;

    if(current_level == level){
        g.num_of_nodes++;
        return;
    }

    auto begin = g.adjacency_list[u].begin();
    auto end = g.adjacency_list[u].end();

    while (begin != end){
        if(!g.visited[*begin])
            DFS(g, *begin, level, current_level+1);
        begin++;
    }
    return;
}

int main(){
    Graph g;
    
    initialize_graph(g, 8);

    add_edge(g, 0, 1);
    add_edge(g, 0, 4);
    add_edge(g, 0, 7);
    add_edge(g, 4, 6);
    add_edge(g, 4, 5);
    add_edge(g, 4, 2);
    add_edge(g, 7, 3);

    int level; //trazeni nivo

    cin >> level;

    DFS(g, 0, level, 0);
    
    cout << g.num_of_nodes << endl;

    return 0;
}