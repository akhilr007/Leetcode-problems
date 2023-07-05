class Solution {
public:
    int better(vector<int>& nums){
        int n = nums.size();
        
        int result = 0;
        int zeroCount = 0;
        
        int i=0;
        for(int j=0; j<n; j++){
            
            if(nums[j] == 0)
                zeroCount++;
            
            while(zeroCount > 1){
                if(nums[i]==0)
                    zeroCount--;
                
                i++;
            }
            
            result = max(result, j-i);
        }
        return result;
    }
    
    int longestSubarray(vector<int>& nums) {
        
        int i=0;
        int j=0;
        
        int lastZeroIndex=-1;
        
        int result = 0;
        
        while(j<nums.size()){
            
            if(nums[j] == 0){
                i = lastZeroIndex+1;
                lastZeroIndex = j;
            }
            
            result = max(result, j-i);
            j++;
        }
        return result;
    }
};