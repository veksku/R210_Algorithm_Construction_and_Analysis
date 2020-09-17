#include <iostream>
#include <vector>

using namespace std;

struct Graph{
    vector<vector<int>> adjacency_list;
    int V;
    vector<bool> visited;
    int clusters;
};

void initialize_graph(Graph &g, int V){
    g.V = V;
    g.visited.resize(V, false);
    g.adjacency_list.resize(V);
    g.clusters = 0;
}

//ZA NEUSMERENE GRAFOVE ADD EDGE IMA I [V].PUSH_BACK(U)!!!!!!!!!!!!!!!!!!!!!
void add_edge(Graph &g, int u, int v){
    g.adjacency_list[u].push_back(v);
    g.adjacency_list[v].push_back(u);
}

void DFS(Graph &g, int u){
    g.visited[u]=true;

    auto begin = g.adjacency_list[u].begin();
    auto end = g.adjacency_list[u].end();

    while(begin != end){
        if(!g.visited[*begin])
            DFS(g, *begin);
        begin++;
    }
}

int count_clusters(Graph &g){
    int i, n=g.V;
    for(i=0; i<n; i++){
        if(!g.visited[i]){
            g.clusters++;
            DFS(g, i);
        }
    }
    return g.clusters;
}

int main(){

    Graph g;

    initialize_graph(g, 6);

    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 5, 4);

    cout << count_clusters(g) << endl;

    return 0;
}