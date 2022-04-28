#include <bits/stdc++.h>
using namespace std;

vector<int> printGraph(int V, vector<int>adj[]){
    vector<int>ans;
    vector<int>vis(V+1, 0);

    for(int i = 1; i <= V; i++){
        if(!vis[i]){
            queue<int>q;
            q.push(i);
            vis[i] = 1;

            while(!q.empty()){
                int front = q.front();
                q.pop();
                ans.push_back(front);

                for(int it : adj[front]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return ans;
}

int main(){

}