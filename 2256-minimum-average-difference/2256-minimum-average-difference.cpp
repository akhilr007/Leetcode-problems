class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int n = nums.size();

        long totalSum = 0;
        for(int val: nums) totalSum += val;
        
        long curSum=0;
        int mini=1e8;
        int minimumIndex=0;
        for(int i=0; i<n; i++){
            curSum += nums[i];
            int leftPart = curSum/(i+1);
            int rightPart;
            if(i!=n-1) rightPart = (totalSum - curSum)/(n-i-1);
            else rightPart = (totalSum - curSum)/1;
            
            int absDiff = abs(leftPart - rightPart);
            if(absDiff < mini){
                mini = absDiff;
                minimumIndex=i;
            }
        }
        
        return minimumIndex;
    }
};