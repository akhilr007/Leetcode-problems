class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int count=0; //zero count
        
        int i=0;
        int j=0;
        
        int ans=0;
        
        while(j<nums.size()){
            
            if(nums[j]==0){
                count++;
            }
            
            while(count > k){
                if(nums[i]==0){
                    count--;
                }
                i++;
            }
            
            ans = max(ans, j-i+1);
            j++;
            
        }
        
        return ans;
    }
};