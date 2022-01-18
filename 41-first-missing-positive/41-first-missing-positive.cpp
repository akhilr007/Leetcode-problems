class Solution {
public:
    
    int segregate(vector<int>& nums){
        
        int i=0;
        int j=0;
        
        while(j<nums.size()){
            
            if(nums[j]<=0){
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
        
        
        // segregate all the positive and negative nos in an array and return the last positive index
        int pi = segregate(nums);
        
        //mark all the +ve numbers with their respective indexes with -ve value
        for(int i=0; i<=pi; i++){
            
            int idx = abs(nums[i])-1;
            
            // mark it if it lies in positive nos and it has not been marked -ve
            if(idx <= pi && nums[idx] > 0){
                nums[idx] = -nums[idx];
            }
        }
        
        // find the first +ve no and return it
        for(int i=0; i<=pi; i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        
        // if all +ve nos are present
        // eg-> 1 2 3 4 then o/p will be 5 our pi will be 3 so pi+2
        return pi+2;
    }
};