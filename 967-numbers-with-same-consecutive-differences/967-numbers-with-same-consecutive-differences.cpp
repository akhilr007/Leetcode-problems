class Solution {
public:
    void dfs(int n, int k, int curr, int counter, int prev, vector<int>& res){
        
        if(counter == n-1){
            res.push_back(curr);
            return;
        }
        
        int next = prev + k;
        if(next < 10){
            dfs(n, k, (curr*10)+next, counter+1, next, res);
        }
        
        next = prev-k;
        if(k != 0 and next >= 0){
            dfs(n, k, (curr*10)+next, counter+1, next, res);
        }
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> res;
        
        for(int i=1; i<= 9; i++){
            dfs(n, k, i, 0, i, res);
        }
        
        return res;
    }
};