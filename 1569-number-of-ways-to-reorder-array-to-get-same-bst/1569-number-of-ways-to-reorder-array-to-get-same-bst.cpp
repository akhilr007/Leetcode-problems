class Solution {
public:
    vector<vector<long long>> tables;
    long long MOD = 1e9 + 7;
    
    long long dfs(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 3)
            return 1;
        
        vector<int> leftNodes, rightNodes;
        int root = nums[0];
        
        for(int i=1; i<n; i++){
            if(nums[i] < root){
                leftNodes.push_back(nums[i]);
            }
            else{
                rightNodes.push_back(nums[i]);
            }
        }
        
        long long leftWays = dfs(leftNodes) % MOD;
        long long rightWays = dfs(rightNodes) % MOD;
        
        return (((leftWays * rightWays) % MOD) * (tables[n-1][leftNodes.size()])) % MOD;
    }
    
    int numOfWays(vector<int>& nums) {
        
        int n = nums.size();
        tables.resize(n+1);
        
        for(int i=0; i<=n; i++){
            tables[i] = vector<long long> (i+1, 1);
            for(int j=1; j<i; j++){
                tables[i][j] = (tables[i-1][j-1] + tables[i-1][j]) % MOD;
            }
        }
        
        return (dfs(nums)-1) % MOD;
    }
};