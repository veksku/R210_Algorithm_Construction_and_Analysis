#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph{
    vector<vector<int>> adjacency_list;
    int V;
    vector<bool> visited;
    int number_of_nodes;
    vector<int> level;
};

void initialize_graph(Graph &g, int V){
    g.adjacency_list.resize(V);
    g.V = V;
    g.visited.resize(V);
    g.number_of_nodes = 0;
    g.level.resize(V, -1);
}

void add_edge(Graph &g, int u, int v){
    g.adjacency_list[u].push_back(v);
}

void BFS(Graph &g, int u, int wanted_level){
    queue<int> nodes;
    nodes.push(u);

    g.visited[u] = true;
    
    g.level[u] = 0;
    if(wanted_level == 0){
        g.number_of_nodes = 1;
        return;
    }
    
    int pom;

    while(!nodes.empty()){
        pom = nodes.front();
        nodes.pop();

        auto begin = g.adjacency_list[pom].begin();
        auto end = g.adjacency_list[pom].end();

        while(begin != end){
            if(!g.visited[*begin]){
                g.level[*begin] = g.level[pom] + 1;
                g.visited[*begin] = true;
                if(g.level[*begin] < wanted_level)
                    nodes.push(*begin);
                else if(g.level[*begin] == wanted_level)
                    g.number_of_nodes++;
                //slucaj g.level[*begin] > wanted_level se ignorise, nije bitan za ovaj konkretan zadatak
            }
            begin++;
        }
    }
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
    add_edge(g, 7, 2);

    int level;

    cin >> level;

    BFS(g, 0, level);

    cout << "The amount of nodes on the level " << level << " is: " << g.number_of_nodes << endl;

    return 0;
}