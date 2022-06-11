class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int totalSum=0;
        for(auto el : nums){
            totalSum += el;
        }
        
        int target = totalSum-x;
        
        unordered_map<int, int> m;
        m[0]=-1;
        
        int maxLenSubArray=-1;
        
        int prefixSum=0;
        for(int i=0; i<nums.size(); i++){
            
            prefixSum += nums[i];
            
            m[prefixSum] = i;
            
            if(m.find(prefixSum - target) != m.end()){
                int curLenSubArray = i - m[prefixSum - target];
                maxLenSubArray = max(maxLenSubArray, curLenSubArray);
            }
        }
        
        if(maxLenSubArray == -1) return -1;
        
        int len = nums.size();
        return len - maxLenSubArray;
    }
};