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


class Pair{
    public:
    int src = 0;
    int level = 0;
    
    Pair(int src, int level){
        this->src = src;
        this->level = level;
    }
};

bool bipartite(vector<vector<Edge*>> graph, int src, vector<int> &visited){
    queue<Pair> q;
    q.push(Pair(src, 0));
    
    while(q.size()){
        
        Pair element = q.front();
        q.pop();
        
        // if visited pehle se mtlb hum kisi or edge k through aaye hn dubara 
        // to hum check krenge ki level same h kya agar hn to even h means bipartite
        if(visited[element.src] != -1){
            if(visited[element.src] != element.level){
                return false;
            }
        }
        else{
            visited[element.src] = element.level;
        }
    
        for(Edge* edge : graph[element.src]){
            if(visited[edge->nbr] == -1){
                q.push(Pair(edge->nbr, element.level + 1));
            }
        }
    }
    return true;
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
    
    vector<int> visited(v, -1);
    
    for(int i = 0; i < v; i++){
        if(visited[i] == -1){
            bool ans = bipartite(graph, i, visited);
            
            if(ans == false){
                cout << "false" << endl;
                return 0;
            }
        }
    }
    
    cout << "true" << endl;
    return 0;
}