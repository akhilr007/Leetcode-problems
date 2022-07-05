class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int first=nums.size()-1;
        
        while(first >= 1 && nums[first-1] >= nums[first]){
            first--;
        }
        
        if(first==0){
            sort(nums.begin(), nums.end());
            return;
        }
        
        first--;
        
        int second = nums.size()-1;
        while(first<second && nums[first] >= nums[second]){
            second--;
        }
        
        swap(nums[first], nums[second]);
        reverse(nums.begin()+first+1, nums.end());
    }
};