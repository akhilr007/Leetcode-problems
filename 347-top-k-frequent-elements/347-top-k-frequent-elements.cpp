class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> m;
        
        for(auto el : nums){
            m[el]++;
        }
        
        for(auto it : m){
            if(pq.size()<k){
                pq.push({it.second , it.first});
            }
            else{
                if(it.second > pq.top().first){
                    pq.pop();
                    pq.push({it.second, it.first});
                }
            }
        }
        
        vector<int> ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};