class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> m;
        for(auto val : nums){
            m[val]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // frequency item
        
        for(auto p : m){
            
            pq.push({p.second, p.first});
            if(pq.size()>k) pq.pop();
        }
        
        vector<int> res;
        while(pq.size()>0){
            auto rem = pq.top();
            pq.pop();
            res.push_back(rem.second);
        }
        
        return res;
    }
};