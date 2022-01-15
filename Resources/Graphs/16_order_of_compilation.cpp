#include <bits/stdc++.h>

using namespace std;

class Edge
{
public:
  int src = 0;
  int nbr = 0;

  Edge(int src, int nbr)
  {
    this->src = src;
    this->nbr = nbr;

  }
};

void TopologicalSort(vector<vector<Edge*>> graph, int &src, vector<bool> &visited, stack<int> &st){
    visited[src] = true;
    
    for(Edge* edge : graph[src]){
        if(visited[edge->nbr] == false){
            TopologicalSort(graph, edge->nbr, visited, st);
        }
    }
    st.push(src);
}

int main() {

  int vtces;
  cin >> vtces;
  vector<vector<Edge*>> graph(vtces, vector<Edge*>());


  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v;
    cin >> u >> v;
    
    Edge* e = new Edge(u, v);
    graph[u].push_back(e);
  }

  vector<bool> visited(vtces, false);
  
  stack<int> st;
  for(int i = 0; i < vtces; i++){
      if(visited[i] == false){
          TopologicalSort(graph, i, visited, st);
      }
  }
  
  while(!st.empty()){
      cout << st.top() << endl;
      st.pop();
  }
  
  return 0;
}