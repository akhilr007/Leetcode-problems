class Solution {
public:
    bool isPalindrome(string& s, int l, int r){
        
        while(l<r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        
        return true;
    }
    
    void backtrack(string& s, int idx, vector<string> ds, vector<vector<string>>& result, int n){
        
        if(idx >= s.length()){
            result.push_back(ds);
            return;
        }
        
        for(int i=idx; i<n; i++){
            if(isPalindrome(s, idx, i)){
                ds.push_back(s.substr(idx, i-idx+1));
                backtrack(s, i+1, ds, result, n);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        int n = s.length();
        
        vector<vector<string>> result;
        vector<string> ds;
        
        backtrack(s, 0, ds, result, n);
        return result;
    }
};