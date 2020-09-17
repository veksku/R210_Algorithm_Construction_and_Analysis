#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph{
    vector<vector<int>> adjacency_list;
    int V;
    vector<bool> visited;
    vector<int> in_degrees;
};

void initialize_graph (Graph &g, int V){
    g.V = V;
    g.adjacency_list.resize(V);
    g.visited.resize(V, false);
    g.in_degrees.resize(V, 0);
}

void add_edge(Graph &g, int u, int v){
    g.adjacency_list[u].push_back(v);
    g.in_degrees[v]++;
}

void topological_sorting(Graph &g){
    queue<int> nodes;

    for(int i=0; i<g.V; i++)
        if(g.in_degrees[i] == 0)
            nodes.push(i);

    int tmp;

    while(!nodes.empty()){
        tmp = nodes.front();
        nodes.pop();

        cout << tmp << " ";

        for(int node : g.adjacency_list[tmp]){
            g.in_degrees[node]--;
            if(g.in_degrees[node] == 0)
                nodes.push(node);
        }
    }
    cout << endl;
}

int main (){
    Graph g;

    initialize_graph(g, 6);

    add_edge(g, 0, 1);
    add_edge(g, 1, 4);
    add_edge(g, 2, 4);
    add_edge(g, 3, 0);
    add_edge(g, 3, 2);
    add_edge(g, 5, 2);
    add_edge(g, 5, 4);

    topological_sorting(g);

    return 0;
}
