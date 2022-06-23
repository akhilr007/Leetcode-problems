class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mp; // value -> indexes
        vector<int> result;
        
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i]) != mp.end()){
                result.push_back(mp[target-nums[i]]);
                result.push_back(i);
                return result;
            }
            
            mp[nums[i]] = i;
            
        }
        
        return result;
    }
};