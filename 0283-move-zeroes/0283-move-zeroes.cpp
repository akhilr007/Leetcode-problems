class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     
        int n = nums.size();

        vector<int> res;
        for(auto &x : nums){
            if(x != 0)
                res.push_back(x);
        }

        int numberOfZeros = n - res.size();
        for(int i=0; i<numberOfZeros; i++){
            res.push_back(0);
        }
        
        for(int i=0; i<n; i++)
            nums[i] = res[i];
    }
};