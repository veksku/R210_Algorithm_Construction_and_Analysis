#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph{
    vector<vector<int>> adjacency_list;
    int V;
    vector<bool> visited;
    vector<int> color;
};

void initialize_graph(Graph &g, int V){
    g.V = V;
    g.adjacency_list.resize(V);
    g.visited.resize(V, false);
    g.color.resize(V, -1);
}

void add_edge(Graph &g, int v, int u){
    g.adjacency_list[u].push_back(v);
    g.adjacency_list[v].push_back(u);
}

bool BFS(Graph &g, int u){
    queue<int> nodes;
    nodes.push(u);

    g.visited[u] = true;
    g.color[u] = 0;
    int pom;

    while(!nodes.empty()){
        pom = nodes.front();
        nodes.pop();

        auto begin = g.adjacency_list[pom].begin();
        auto end = g.adjacency_list[pom].end();

        while(begin != end){
            if(g.color[*begin] == g.color[pom])
                return false;
            if(!g.visited[*begin]){
                g.visited[*begin] = true;
                g.color[*begin] = !g.color[pom];
                nodes.push(*begin);
            }
            begin++;
        }
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
    // Dodati ovu granu u graf i videti rezultat
    add_edge(g, 2, 0);

    BFS(g, 0)? cout << "The graph is bipartite\n" : cout << "The graph is not bipartite\n";
    return 0;
}