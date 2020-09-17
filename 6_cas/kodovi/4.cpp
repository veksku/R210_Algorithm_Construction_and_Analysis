#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph {
    vector<vector<int>> adjacency_list;
    int V;
    vector<bool> visited;
    vector<int> in_degrees;
    vector<int> parent;
};

void initialize_graph(Graph& g, int V){
    g.V = V;
    g.adjacency_list.resize(V);
    g.visited.resize(V, false);
    g.in_degrees.resize(V, 0);
    g.parent.resize(V, -1);
}

void add_edge(Graph& g, int u, int v){
    g.adjacency_list[u].push_back(v);
    g.in_degrees[v]++;
}

bool has_cycle(Graph &g, int u){
    g.visited[u] = true;

    auto begin = g.adjacency_list[u].begin();
    auto end = g.adjacency_list[u].end();

    while(begin != end){
        if(g.visited[*begin])
            return true;
        else if(has_cycle(g, *begin))
            return true;
        begin++;
    }
    return false;
}

void topological_sort(Graph& g){
    queue<int> nodes;
    
    for(int i=0; i<g.V; i++){
        if(g.in_degrees[i] == 0)
            nodes.push(i);
    }

    int pom;
    cout << "Topological sorting: ";
    while(!nodes.empty()){
        pom = nodes.front();
        nodes.pop();
        cout << pom << " ";
        
        for(int node : g.adjacency_list[pom]){
            g.in_degrees[node]--;
            if(g.in_degrees[node] == 0)
                nodes.push(node);
        }
    }
    cout << endl;
}

void find(Graph& g){
    if(has_cycle(g, 0)){
        cout << "The graph has a cycle\n";
        return;
    }

    topological_sort(g);
}

int main(){
    Graph g;

    initialize_graph(g, 6);

    // add_edge(g, 0, 2);
    // add_edge(g, 2, 1);
    // add_edge(g, 1, 3);
    // add_edge(g, 3, 4);
    // add_edge(g, 4, 1);
    // add_edge(g, 4, 2);
    
    //add_edge(g, 0, 1);
    //add_edge(g, 1, 4);
    //add_edge(g, 2, 4);
    //add_edge(g, 3, 0);
    //add_edge(g, 3, 2);
    //add_edge(g, 5, 2);
    //add_edge(g, 5, 4);

     add_edge(g, 0, 1);
     add_edge(g, 1, 2);
     add_edge(g, 2, 3);
     add_edge(g, 3, 4);
     add_edge(g, 4, 3);
     add_edge(g, 4, 5);
     add_edge(g, 5, 6);

    find(g);

    return 0;
}