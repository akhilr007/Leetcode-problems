class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int i=0;
        int j=nums.size()-1;
        
        vector<int> res(2);
        
        while(i<=j){
            
            if(nums[i] + nums[j] == target){
                res[0]=i+1;
                res[1]=j+1;
                break;
            }
            else if(nums[i] + nums[j] > target){
                j--;
            }
            else{
                i++;
            }
        }
        
        return res;
    }
};