#include <iostream>
#include <vector>

using namespace std;

struct Graph{
	vector<vector<int>> adjacency_list;
	int V;
	vector<bool> visited;
	int min;
};

void initialize_graph(Graph &g, int V){
	g.V = V;
	g.adjacency_list.resize(V);
	g.visited.resize(V,false);
	g.min = INT32_MAX;
}

void add_edge(Graph &g, int u, int v){
	g.adjacency_list[u].push_back(v);
}

void DFS(Graph &g, int u, int v, int current_min){
    if(u == v){
        if (current_min < g.min)
            g.min = current_min;
    }
    g.visited[u] = true;

    auto begin = g.adjacency_list[u].begin();
    auto end = g.adjacency_list[u].end();

    while(begin != end){
        if(!g.visited[*begin])
            DFS(g, *begin, v, current_min+1);
        begin++;
    }
    g.visited[u] = false;
}

int main(){
	int u,v;
	Graph g;
	cin >> u >> v;

  	initialize_graph(g, 5);

 	add_edge(g, 0, 1);
 	add_edge(g, 1, 0);
  	add_edge(g, 0, 4);
	add_edge(g, 4, 0);
 	add_edge(g, 1, 2);
	add_edge(g, 2, 1);
  	add_edge(g, 2, 4);
	add_edge(g, 4, 2);
	add_edge(g, 2, 3);
  	add_edge(g, 3, 2);
  	add_edge(g, 3, 4);
  	add_edge(g, 4, 3);

	DFS(g, u, v, 0);


    if(g.min == INT32_MAX)
        cout << "Ne postoji putanja izmedju ova dva cvora\n";
    else
	    cout << g.min << endl;

	return 0;
}