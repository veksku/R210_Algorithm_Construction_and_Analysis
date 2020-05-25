#include <iostream>
#include <vector>

using namespace std;

struct Graph{
    vector<vector<int>> adjacency_list;
    int V;
    vector<bool> visited;
    vector<int> vertix_color;
};

void initialize_graph(Graph &g, int V){
    g.V = V;
    g.adjacency_list.resize(V);
    g.visited.resize(V, false);
    g.vertix_color.resize(V, -1);
}

void add_edge(Graph &g, int u, int v){
    g.adjacency_list[u].push_back(v);
    g.adjacency_list[v].push_back(u);
}

bool DFS(Graph &g, int u, int color){
    g.visited[u] = true;
    g.vertix_color[u] = color;

    auto begin = g.adjacency_list[u].begin();
    auto end = g.adjacency_list[u].end();

    while(begin != end){
        if(g.vertix_color[*begin] == g.vertix_color[u])
            return false;
        if(!g.visited[*begin])
            if(!DFS(g, *begin, !color))
                return false;
        begin++;
    }

    return true;
}

int main(){
    Graph g;

    initialize_graph(g, 6);

    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 4, 5);
    add_edge(g, 5, 0);
    add_edge(g, 2, 0);

    if(DFS(g, 0, 0))
        cout << "Graf je bipartitan!";
    else
        cout << "Graf nije bipartitan!";
    cout << endl;

    return 0;
}