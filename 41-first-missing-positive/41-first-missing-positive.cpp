class Solution {
public:
    
    int segregate(vector<int>& nums){
        
        // j to n-1 -> unknown
        // i to j-1 -> -ve nos
        // 0 to i-1 -> +ve nos
        
        int i=0;
        int j=0;
        
        while(j<nums.size()){
            
            if(nums[j] <= 0){
                j++;
            }
            else{
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
        
        return i-1;
    }
    int firstMissingPositive(vector<int>& nums) {
        
        // return the last index of +ve no
        int pi = segregate(nums);
        
        for(int i=0; i<=pi; i++){
            int idx = abs(nums[i])-1;
            
            if(idx<=pi && nums[idx]>0){
                nums[idx] = -nums[idx];
            }
        }
        
        for(int i=0; i<=pi; i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        
        return pi+2;
    }
};