#include<bits/stdc++.h>
using namespace std;

class Edge {
public:
  int src = 0;
  int nbr = 0;
  int wt = 0;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt  = wt;
  }
};

void hamiltonianPath(vector<vector<Edge>> graph, int src, int osrc, int noEdges, vector<bool>&visited, string psf){
    if(noEdges == graph.size() - 1);
    {
        for(Edge e : graph[src]){
            if(e.nbr == osrc){
                cout << psf << "*" << endl;
            }
            else{
                cout << psf << "." << endl;
            }
        }
    }
    
    visited[src] = true;
    for(Edge e : graph[src]){
        if(visited[e.nbr] == false){
            hamiltonianPath(graph, e.nbr, osrc, noEdges + 1, visited, psf + to_string(src));
        }
    }
    
    visited[src] = false;
}

int main() {
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());


  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w;
    cin >> u >> v >> w;

    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));

  }
  int src;
  cin >> src;

  vector<bool> vis(vtces, false);
  hamiltonianPath(graph, src, src, 0, vis, "" + to_string(src));
  return 0;
}