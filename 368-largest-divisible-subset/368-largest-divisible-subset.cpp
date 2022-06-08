class Lis{
public:
    int l, i, v;
    Lis(int l, int i, int v){
        this->l = l;
        this->i = i;
        this->v = v;
    }
};

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        int omax = 0;
        int omi = 0;
        
        for(int i=1; i<n; i++){
            int maxi = 0;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    maxi = max(dp[j], maxi);
                }
            }
            
            dp[i] = maxi+1;
            if(dp[i] > omax){
                omax = dp[i];
                omi = i;
            }
        }
        
        queue<Lis> q;
        q.push(Lis(omax, omi, nums[omi]));
        
        vector<int> ans;
        ans.push_back(nums[omi]);
        
        while(q.size()>0){
            
            auto rem = q.front();
            q.pop();
            
            if(rem.l == 1){
                break;
            }
            
            for(int j=0; j<rem.i; j++){
                int c=0;
                if(dp[j] == rem.l-1 && (rem.v % nums[j] == 0)){
                    q.push(Lis(dp[j], j, nums[j]));
                    ans.push_back(nums[j]);
                    c++;
                    if(c==1){
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};