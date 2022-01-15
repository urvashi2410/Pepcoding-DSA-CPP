#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt)
  {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};

class Pair{
    public:
    int v;
    int p;
    int wt;
    
    Pair(int v, int p, int wt){
        this->v = v;
        this->p = p;
        this->wt = wt;
    }
    
    bool operator<(const class Pair& other) const
    {
        return this->wt > other.wt;
    }
};

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

  int src = 0;
  priority_queue<Pair> q;
  
  q.push({src, -2, 0});
  vector<int>visited(vtces, -1);
  while(q.size()){
      Pair element = q.top();
      q.pop();
      
      if(visited[element.v] != -1){
          continue;
      }
      
      visited[element.v] = element.p;
      
      if(element.p != -2){
          cout << "[" << element.v << "-" << element.p << "@" << element.wt << "]" << endl;
      }
      
      for(Edge edge : graph[element.v]){
          if(visited[edge.nbr] == -1){
              q.push({edge.nbr, element.v, edge.wt});
          }
      }
      
  }
  return 0;
}