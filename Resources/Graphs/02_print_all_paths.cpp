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

vector<bool> visited(1000, false);

void allPaths(vector<vector<Edge*>> &graph, int src, int des, string path_so_far){
    if(src == des){
        cout << path_so_far << endl;
        return;
    }
    
    visited[src] = true;
    
    for(Edge* edge : graph[src]){
        int nei = edge->nbr;
        
        if(!visited[nei]){
            allPaths(graph, nei, des, path_so_far + to_string(nei));
        }
    }
    
    visited[src] = false;
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
    
    int src, des;
    cin >> src >> des;
    
    string s = "";
    allPaths(graph, src, des, s + to_string(src));
    return 0;
}