class Solution {
private:
    vector<vector<int>> ans;
public:
    void helper(int i, int t, vector<int>& combinations, int k){
        
        if(t==0 and k==0){
            ans.push_back(combinations);
            return;
        }
        
        if(t<0) return;
        
        if(i == 10) return;
        
        // skip the element
        helper(i+1, t, combinations, k);
        
        // pick the element
        combinations.push_back(i);
        helper(i+1, t-i, combinations, k-1);
        combinations.pop_back();
    }
    
    vector<vector<int>> combinationSum3(int k, int t) {
        
        vector<int> combinations;
        helper(1, t, combinations, k);
        return ans;
        
    }
};