#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Graph{
    vector<vector<int>> adjacency_list;
    vector<bool> visited;
    int V;
    vector<int> parents;
    vector<int> times;
    vector<int> lower_times;
    set<int> articulation_points;
    int time;
};

void initialize_graph(Graph &g, int V){
    g.adjacency_list.resize(V);
    g.visited.resize(V, false);
    g.V = V;
    g.parents.resize(V, -1);
    g.times.resize(V, -1);
    g.lower_times.resize(V, -1);
    g.time = 0;
}

void add_edge(Graph &g, int u, int v){
    g.adjacency_list[u].push_back(v);
    g.adjacency_list[v].push_back(u);
}

void DFS(Graph &g, int u){

    g.visited[u] = true;
    g.times[u] = g.lower_times[u] = g.time;

    g.time++;

    int children = 0;

    auto begin = g.adjacency_list[u].begin();
    auto end = g.adjacency_list[u].end();

    while (begin != end) {
        if (!g.visited[*begin]) {
            g.parents[*begin] = u;

            DFS(g, *begin);

            children++;

            g.lower_times[u] = min(g.lower_times[*begin], g.lower_times[u]);

            if (g.parents[u] == -1 && children > 1)
                g.articulation_points.insert(u);

            if (g.parents[u] != -1 && g.times[u] <= g.lower_times[*begin])
                g.articulation_points.insert(u);
        }
        else if (*begin != g.parents[u]) {
            g.lower_times[u] = min(g.lower_times[u], g.times[*begin]);
        }
        begin++;
    }
}

void find_articulation_points(Graph &g)
{
    DFS(g, 3);

    for (int x : g.articulation_points)
        cout << x << " ";

    cout << endl;
}

int main (){
    Graph g;

    initialize_graph(g, 8);

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 4, 5);
    add_edge(g, 4, 6);
    add_edge(g, 5, 6);
    add_edge(g, 5, 7);
    add_edge(g, 2, 6);

    find_articulation_points(g);

    return 0;
}