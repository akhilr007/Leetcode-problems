class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
        k = k%nums.size();
        
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
    
    void reverse(vector<int>& nums, int lo, int hi){
        
        while(lo<hi){
            swap(nums[lo], nums[hi]);
            lo++;
            hi--;
        }
    }
};