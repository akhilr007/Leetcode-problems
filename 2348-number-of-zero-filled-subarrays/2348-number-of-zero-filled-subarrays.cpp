class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int i=0, j=0;
        long long res = 0;

        while(j<nums.size()){

            if(nums[j] != 0){
                i = j+1;
            }

            res += j-i+1;
            j++;
        }

        return res;
    }
};