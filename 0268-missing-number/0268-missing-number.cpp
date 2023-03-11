class Solution {
public:
    // time complexity -> O(n2) space complexity -> O(1)
    int bruteForce(vector<int>& nums){
        
        int n = nums.size();
        for(int i=0; i<=n; i++){
            
            int flag = 0;
            for(int j=0; j<n; j++){
                
                if(nums[j] == i){
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0)
                return i;
        }
        
        return -1;
    }
    
    // time complexity -> O(n) space complxity -> O(n)
    int better(vector<int>& nums){
        
        int n = nums.size();
        vector<int> hashNums(n+1, 0);
        
        for(int i=0; i<n; i++)
            hashNums[nums[i]]++;
        
        for(int i=0; i<=n; i++){
            
            if(hashNums[i] == 0)
                return i;
        }
        
        return -1;
    }
    
    int optimal1(vector<int>& nums){
        
        int n = nums.size();
        
        int totalSum = 0;
        totalSum = (n * (n+1))/2;
        
        int sumOfNums = 0;
        for(auto &x : nums)
            sumOfNums += x;
        
        return totalSum - sumOfNums;
    }
    
    int missingNumber(vector<int>& nums) {
        
        return optimal1(nums);
    }
};