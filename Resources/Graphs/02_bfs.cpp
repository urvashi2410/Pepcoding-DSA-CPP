#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int>adj[], int V, int s){
    vector<bool>vis(V+1, false);
    vis[s] = true;
    queue<int>q;
    q.push(s);
    vector<int> bfs;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        bfs.push_back(front);
        for(auto i : adj[front]){
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
            }
        }
    }
    return bfs;
}

void _bfs(vector<int>adj[], int s, vector<bool>&vis){
    queue<int>q;
    vis[s] = true;
    q.push(s);

    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout << front << " ";

        for(auto i : adj[front]){
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
            }
        }
    }
}

void startNotGiven(vector<int>adj[], int V){
    vector<bool>vis(V+1, false);

    for(int i = 0; i < V; i++){
        if(!vis[i]){
            _bfs(adj, i, vis);
        }
    }
}

int countDiscontinuous(vector<int>adj[], int V){
    vector<bool>vis(V+1, false);
    int count = 0;

    for(int i = 0; i < V; i++){
        if(!vis[i]){
            count++;
            _bfs(adj, i, vis);
        }
    }
    return count;
}

int main(){

}