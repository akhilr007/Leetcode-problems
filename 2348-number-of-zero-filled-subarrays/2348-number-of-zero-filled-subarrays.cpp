class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        long long cnt = 0;
        
        for(int i=0, j=0; i<n; i++){
            
            if(nums[i] != 0){
                j = i+1;
            }
            
            cnt += i-j+1;
        }
        
        return cnt;
    }
};