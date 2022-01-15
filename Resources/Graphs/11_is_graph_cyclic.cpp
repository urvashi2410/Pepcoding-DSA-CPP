#include <bits/stdc++.h>
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


bool isGraphCyclic(vector<vector<Edge*>> &graph, int src, vector<bool> &visited){
    queue<int> q;
    q.push(src);
    
    while(q.size() > 0){
        int nei = q.front();
        q.pop();
        
        if(visited[nei]){
            return true;
        }
        
        visited[nei] = true;
        
        for(Edge* edge : graph[src]){
            if(!visited[edge->nbr]){
                q.push(edge->nbr);
            }
        }
    }
    
    return false;
}


bool helper(vector<vector<Edge*>> &graph){
    vector<bool> visited(graph.size(), false);
    
    for(int i = 0; i < graph.size(); i++){
        if(!visited[i]){
            if(isGraphCyclic(graph, i, visited)){
                return true;
            }
        }
    }
    
    return false;
}


int main() {
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
	
	if(helper(graph)){
	    cout << "true" << endl;
	}
	else{
	    cout << "false" << endl;
	}
	
	return 0;
}
