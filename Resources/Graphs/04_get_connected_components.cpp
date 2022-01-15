#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src;
    int nbr;
    int wt;
    
    Edge(int src, int nbr, int wt){
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

void getAllConnectedComponents(vector<vector<Edge*>> graph, int src, vector<int> &component, vector<bool> &visited){
    
    visited[src] = true;
    
    component.push_back(src);
    for(Edge* edge: graph[src]){
        int nei = edge->nbr;
        
        if(!visited[nei]){
            getAllConnectedComponents(graph, nei, component, visited);
        }
    }
}

int main(){
    int v, e;
    cin >> v >> e;
    
    vector<vector<Edge*>> graph(v, vector<Edge*>());
    
    for(int i = 0; i < e; i++){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        
        Edge* e1 = new Edge(v1, v2, wt);
        Edge* e2 = new Edge(v2, v1, wt);
        
        graph[v1].push_back(e1);
        graph[v2].push_back(e2);
    }
    
    vector<vector<int>> ans;
    vector<bool> visited(graph.size(), false);
    
    for(int i = 0; i < graph.size(); i++){
        if(!visited[i]){
            vector<int>component;
            getAllConnectedComponents(graph, i, component, visited);
            ans.push_back(component);
        }
    }
}