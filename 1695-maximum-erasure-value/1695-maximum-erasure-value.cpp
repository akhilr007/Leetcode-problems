class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_set<int> s;
        
        int start=0;
        int end=0;
        
        int runningSum=0;
        int maxSum=0;
        
        while(end<nums.size()){
            
            int curEl = nums[end];
            
            if(s.find(curEl) == s.end()){
                runningSum += curEl;
                s.insert(curEl);
                maxSum = max(runningSum, maxSum);
                end++;
            }
            else{
                int deleteEl = nums[start];
                s.erase(deleteEl);
                runningSum -= deleteEl;
                start++;
            }
        }
        
        return maxSum;
    }
};