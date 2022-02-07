class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int i=0;
        int j=0;
        
        // 0 to j-1 -> even nos
        // j to i-1 -> odd nos
        // i to n-1 -> unknown
        
        while(i<nums.size()){
            
            if(nums[i] % 2 == 0){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        return nums;
        
    }
};