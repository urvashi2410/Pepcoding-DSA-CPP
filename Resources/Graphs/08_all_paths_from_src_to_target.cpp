class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& path, int src){
        path.push_back(src);
        if(src == graph.size()-1){
            ans.push_back(path);
        }
        else{
            for(auto x : graph[src]){
                dfs(graph, ans, path, x);
            }
        }
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;
        dfs(graph, ans, path, 0);
        return ans;
    }
};