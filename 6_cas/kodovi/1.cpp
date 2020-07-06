#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct Graph{
    vector<vector<int>> adjacency_list;
    int V;
    vector<bool> visited;
    vector<int> parent;
};

void initialize_graph(Graph &g, int V){
    g.V = V;
    g.adjacency_list.resize(V);
    g.visited.resize(V, false);
    g.parent.resize(V, -1);
}

void add_edge(Graph &g, int u, int v){
    g.adjacency_list[u].push_back(v);
    g.adjacency_list[v].push_back(u);
}

void BFS(Graph &g, int u, int v){
    
    queue<int> nodes;
    nodes.push(u);

    g.visited[u] = true;
    
    int pom;

    while(!nodes.empty()){
        
        pom = nodes.front();
        nodes.pop();
        
        if(pom == v)
            return ;
        
        auto begin = g.adjacency_list[pom].begin();
        auto end = g.adjacency_list[pom].end();

        while(begin != end){
            if(!g.visited[*begin]){
                g.visited[*begin] = true;
                g.parent[*begin] = pom;
                nodes.push(*begin);
            }
            begin++;
        }
    }
}

void print_path(Graph &g, int u, int v){
    stack<int> path;

    BFS(g, u, v);

    if(g.parent[v] == -1){
        cout << "The path doesn't exist" << endl;
        return;
    }

    path.push(v);

    while(g.parent[v] != -1){
        v = g.parent[v];
        path.push(v);
    }

    int n = path.size();
    int x;

    while(n){
        x = path.top();
        path.pop();

        if(n > 1)
            cout << x << " -> ";
        else
            cout << x << endl;
        n--;
    }
}

int main(){
    
    Graph g;

    initialize_graph(g,8);
    
    add_edge(g, 0, 1);
    add_edge(g, 0, 3);
    add_edge(g, 1, 2);
    add_edge(g, 3, 4);
    add_edge(g, 3, 7);
    add_edge(g, 4, 5);
    add_edge(g, 4, 6);
    add_edge(g, 4, 7);
    add_edge(g, 5, 6);
    add_edge(g, 6, 7);

    int u, v;

    cin >> u >> v;

    print_path(g, u, v);

    return 0;
}