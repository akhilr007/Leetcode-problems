class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> m; // element -> freq
        
        for(auto el : nums){
            m[el]++;
        }
        
        vector<vector<int>> freq(nums.size()+1);
        /*
        treating index as count because count can't be greater than arr size
        i(count) 0 1 2 3 4 5 6
        values   0 3 2 1 0 0 0
        */
        
        for(auto it : m){
            int key = it.first; // element
            int val = it.second; // count
            
            freq[val].push_back(key);
        }
        
        vector<int> res;
        for(int i=freq.size()-1; i>=0 ; i--){
            for(auto j : freq[i]){
                res.push_back(j);
                
                if(res.size() == k) return res;
            }
        }
        
        return res;
    }
};