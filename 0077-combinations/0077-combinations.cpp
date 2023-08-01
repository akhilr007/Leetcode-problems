class Solution {
public:
    void solve(int i, int n, int k, vector<int> ans, vector<vector<int>>& result)
    {
        if(k == 0){
            result.push_back(ans);
            return;
        }
        
        for(int j=i; j<=n; j++){
            ans.push_back(j);
            solve(j+1, n, k-1, ans, result);
            ans.pop_back();
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> result;
        vector<int> ans;
        solve(1, n, k, ans, result);
        return result;
    }
};