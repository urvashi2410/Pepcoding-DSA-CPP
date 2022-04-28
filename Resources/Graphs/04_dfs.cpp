#include <bits/stdc++.h>
using namespace std;

void dfsRec(vector<int>adj[], int s, vector<bool>&vis){
    vis[s] = true;
    cout << s << " ";
    for(auto &i : adj[s]){
        if(!vis[i]){
            dfsRec(adj, i, vis);
        }
    }
}

void dfs(vector<int>adj[], int v){
    vector<bool>vis(v+1, false);
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfsRec(adj, i, vis);
        }
    }
}
int main(){
    
}