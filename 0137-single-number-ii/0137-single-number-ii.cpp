class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        unordered_map<int, int> m;
        for(auto num: nums)
            m[num]++;
        
        int result = 0;
        
        for(auto [key, value] : m){
            if(value == 1){
                result = key;
                break;
            }
        }
        return result;
    }
};