#include <iostream>
#include <vector>
#include <climits>

#define INFINITY INT_MAX

using namespace std;

struct Graph{
    int V;
    int** matrix;
    vector<bool> included_in_MST;
    vector<int> parents;
    vector<int> edges;
};

void initialize_graph(Graph& g, int V){
    g.V = V;

    g.matrix = (int**)malloc(V*sizeof(int*));
    for(int i=0; i < V; i++)
        g.matrix[i] = (int *)calloc(sizeof(int), V);

    g.included_in_MST.resize(V, false);

    g.parents.resize(V, -1);

    g.edges.resize(V, INFINITY);
}

void add_edge(Graph &g, int u, int v, int weight){
    g.matrix[u][v] = weight;
    g.matrix[v][u] = weight;
}

int min_edge_not_included(Graph& g){
    int min = INFINITY;
    int i_min = -1;

    for(int i = 0; i < g.V ; i++){
        if(!g.included_in_MST[i] && g.edges[i] < min){
            i_min = i;
            min = g.edges[i];
        }
    }
    return i_min;
}

void prim(Graph& g, int u){
    g.edges[u] = 0;

    int node;

    for(int i = 0; i < g.V - 1; i++){
        node = min_edge_not_included(g);

        g.included_in_MST[node] = true;

        for(int v = 0; v < g.V; v++){
            if(g.matrix[node][v] && !g.included_in_MST[v] && g.matrix[node][v] < g.edges[v]){
                g.parents[v] = node;
                g.edges[v] = g.matrix[node][v];
            }
        }
    }
    int cost = 0;

    for(int i = 0; i < g.V; i++)
        //if(i != u)
            cost+= g.edges[i];

    cout << cost << endl;
}

int main ()
{
    Graph g;

    initialize_graph(g, 5);

    add_edge(g, 0, 1, 1);
    add_edge(g, 0, 2, 5);
    add_edge(g, 0, 3, 10);
    add_edge(g, 0, 4, 4);
    add_edge(g, 1, 2, 2);
    add_edge(g, 1, 4, 1);
    add_edge(g, 2, 3, 4);

    prim(g, 0);

    return 0;
}