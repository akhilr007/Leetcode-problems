class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        long long cnt=0;
        long long freq=0;
        
        for(int i=0; i<n; i++){
            
            if(nums[i] == 0){
                freq++;
            }
            else{
                cnt += (freq * (freq + 1)) / 2;
                freq = 0;
            }
        }
        
        if(freq){
            cnt += (freq * (freq + 1)) / 2;
        }
        
        return cnt;
    }
};