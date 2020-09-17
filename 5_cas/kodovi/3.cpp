#include <iostream>
#include <vector>

using namespace std;

struct Graph{
    vector<vector<int>> adjacency_list;
    int V;
    vector<bool> visited;
    bool found;
};

void initialize_graph(Graph &g, int V){
    g.V = V;
    g.visited.resize(V,false);
    g.adjacency_list.resize(V);
    g.found = false;
}

void add_edge(Graph &g, int u, int v){
    g.adjacency_list[u].push_back(v);
}

bool DFS(Graph& g, int u, int v, vector<int>& result){
    if(u == v){
        result.push_back(u);
        g.found = true;
        return true;
    }

    g.visited[u] = true;

    result.push_back(u);

    auto begin = g.adjacency_list[u].begin();
    auto end = g.adjacency_list[u].end();

    while(begin != end){
        bool ret_val = false;

        if(!g.visited[*begin] && !g.found)
            ret_val = DFS(g, *begin, v, result);

        if(ret_val)
            return true;

        result.pop_back();
        begin++;
    }
    return false;
}

int main(){
    int u, v;
    
    cin >> u >> v;

    Graph g;

    initialize_graph(g, 5);

    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 3, 4);

    vector<int> result;

    DFS(g, u, v, result);

    if (!g.found)
        cout << "Nema puta!\n";
    else{
        int i;
        for (i = 0; i < result.size() - 1; i++)
            cout << result[i] << " -> ";
        cout << result[i] << endl;
    }

    return 0;
}