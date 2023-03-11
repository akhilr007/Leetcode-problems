class Solution {
public:
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
    
    int missingNumber(vector<int>& nums) {
        
        return better(nums);
    }
};