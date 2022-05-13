class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int,int>>maxh;
        for(int i = 0; i < n; i++){
            maxh.push(make_pair(abs(arr[i] - x), arr[i]));
            
            if(maxh.size() > k){
                maxh.pop();
            }
        }
        
        vector<int>ans;
        while(!maxh.empty()){
            int top = maxh.top().second;
            maxh.pop();
            ans.push_back(top);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};