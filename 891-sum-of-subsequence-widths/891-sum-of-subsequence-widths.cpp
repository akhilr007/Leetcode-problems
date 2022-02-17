class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        long ans = 0;
        long mod = 1e9+7;
        
        int n=nums.size();
        vector<long> pow(n);
        pow[0] = 1;
        
        for(int i=1; i<n; i++){
            pow[i] = (pow[i-1]*2)%mod;
        }
        
        for(int i=0; i<n; i++){
            ans = (ans + nums[i] * (pow[i] - pow[n-i-1]))%mod;
        }
        
        return (int)ans;
    }
};