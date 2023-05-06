class Solution {
public:
    const int MOD = (int)1e9+7;
    long long power(long long n, long long k){
        
        long long ans = 1;
        while(k > 0){
            
            if(k % 2 == 1){
                ans = (ans * n)%MOD;
                k--;
            }
            else{
                n = (n * n)%MOD;
                k = k/2;
            }
        }
        
        return ans;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        int l=0;
        int r=n-1;
        
        int res=0;
        while(l<=r){
            
            if(nums[l] + nums[r] > target)
                r--;
            
            else{
                // for l there will be 2^(r-l) options to make subsequences
                int p = power(2, r-l);
                res = (res + p)%MOD;
                
                l++;
            }
        }
        
        return res;
    }
};