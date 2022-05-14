class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>>minh;
        for(auto &i : mp){
            minh.push(make_pair(i.second, i.first));
            if(minh.size() > k){
                minh.pop();
            }
        }
        
        vector<int>ans;
        while(!minh.empty()){
            int top = minh.top().second;
            minh.pop();
            ans.push_back(top);
        }
        return ans;
    }
};