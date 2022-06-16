class Solution {
private: 
    // TC -> O(n^3) & SC -> O(1)
    int bruteForce(vector<int>& nums){
        
        int n=nums.size();
        
        int maxi=INT_MIN;
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int sum=0;
                for(int k=i; k<=j; k++){
                    sum += nums[k];
                    maxi = max(sum, maxi);
                }
            }
        }
        
        return maxi;
    }
    
    // TC -> O(n^2) & SC -> O(1)
    int efficient(vector<int>& nums){
        
        int n=nums.size();
        
        int maxi=INT_MIN;
        
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                maxi = max(maxi, sum);
            }  
        }
        
        return maxi;
    }
    
public:
    int kadaneAlgorithm(vector<int>& nums){
        
        int maxSub = nums[0];
        int curSum = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(curSum < 0) curSum=0;
            curSum += nums[i];
            maxSub = max(maxSub, curSum);
        }
        
        return maxSub;
    }
    
    int maxSubArray(vector<int>& nums) {
        
        return kadaneAlgorithm(nums);
    }
};