class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>>umap;
        
        for(auto &x : edges){
            vector<int>temp = x;
            int i = temp[0];
            int j = temp[1];
            
            umap[i].push_back(j);
            umap[j].push_back(i);
        }
        
        vector<bool>vis(n+1, false);
        queue<int>q;
        
        vis[source] = true;
        q.push(source);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            vector<int>temp = umap[front];
            
            for(auto &i : temp){
                if(!vis[i]){
                    vis[i] = true;
                    q.push(i);
                }
            }
            
            if(vis[destination] == true){
                return true;
            }
        }
        return vis[destination];
    }
};