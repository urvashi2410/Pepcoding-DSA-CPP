class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
	    queue<int>q;
	    vector<int>inDegree(V, 0);
	    
	    for(int i = 0; i < V; i++){
	        vector<int>data = adj[i];
	        for(auto x : data){
	            inDegree[x]++;
	        }
	    }
	    
	    for(int i = 0; i < V; i++){
	        if(inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
	        ans.push_back(front);
	        
	        for(auto j : adj[front]){
	            inDegree[j]--;
	            if(inDegree[j] == 0){
	                q.push(j);
	            }
	        }
	    }
	    return ans;
	}
};