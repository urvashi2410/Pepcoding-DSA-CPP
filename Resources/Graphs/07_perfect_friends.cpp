#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src;
    int nbr;
    
    Edge(int src, int nbr){
        this->src = src;
        this->nbr = nbr;
    }
};

void perfectFriends(vector<vector<Edge*>> graph, int src, vector<int> &comp, vector<bool> &visited){
    visited[src] = true;
    
    comp.push_back(src);
    
    for(Edge* edge : graph[src]){
        int nei = edge->nbr;
        if(!visited[nei]){
            perfectFriends(graph, nei, comp, visited);
        }
    }
}

int main(){
    int v, e;
    cin >> v >> e;
    
    vector<vector<Edge*>> graph(v, vector<Edge*>());
    
    for(int i = 0; i < e; i++){
        int v1, v2;
        cin >> v1 >> v2;
        
        Edge* e1 = new Edge(v1, v2);
        Edge* e2 = new Edge(v2, v1);
        
        graph[v1].push_back(e1);
        graph[v2].push_back(e2);
    }
    
    vector<bool> visited(v, false);
    vector<vector<int>> components;
    
    for(int i = 0; i < graph.size(); i++){
        if(!visited[i]){
            vector<int> comp;
        
            perfectFriends(graph, i, comp, visited);
            components.push_back(comp);
        }
    }
    
    int count = 0;
    for(int i = 0; i < components.size(); i++){
        for(int j = i + 1; j < components.size(); j++){
            count += components[i].size() * components[j].size();
        }
    }
    
    cout << count << endl;
}
