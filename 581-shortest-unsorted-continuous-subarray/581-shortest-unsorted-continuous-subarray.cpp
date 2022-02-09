class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int Min = INT_MAX;
        int Max = INT_MIN;
        
        int n = nums.size();
        
        for(int i=1; i<n; i++){
            // check for decreasing order
            if(nums[i] < nums[i-1]){
                Min = min(Min, nums[i]);
            }
        }
        
        for(int i=n-2; i>=0; i--){
            // check for increasing order
            if(nums[i] > nums[i+1]){
                Max = max(Max, nums[i]);
            }
        }
        
        if(Min == INT_MAX && Max == INT_MIN) return 0;
        
        int start=0;
        int end=n-1;
        
        for(; start < n; start++){
            if(nums[start] > Min) break;
        }
        
        for(; end>=0; end--){
            if(nums[end] < Max) break;
        }
        
        return end-start+1;
    }
};