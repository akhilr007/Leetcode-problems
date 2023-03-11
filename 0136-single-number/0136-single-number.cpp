class Solution {
public:
    int bruteForce(vector<int>& nums){
        
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            
            int num = nums[i];
            int cnt = 0;
            
            for(int j=0; j<n; j++){
                
                if(nums[j] == num)
                    cnt++;
            }
            
            if(cnt == 1)
                return num;
        }
        
        return -1;
    }
    
    int better(vector<int>& nums){
        
        int n = nums.size();
        
        unordered_map<int, int> mpp;
        for(auto &x : nums)
            mpp[x]++;
        
        for(auto &it : mpp){
            
            if(it.second == 1)
                return it.first;
        }
        
        return -1;
        
    }
    
    int singleNumber(vector<int>& nums) {
        return better(nums);
    }
};