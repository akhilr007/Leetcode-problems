class Solution {
public:
    bool isPalindrome(string& s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    void dfs(int i, string& s, vector<string>& ans, vector<vector<string>>& res){
        
        if(i >= s.length()){
            res.push_back(ans);
            return;
        }
        
        for(int j=i; j<s.length(); j++){
            if(isPalindrome(s, i, j)){
                ans.push_back(s.substr(i, j-i+1));
                dfs(j+1, s, ans, res);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        vector<string> ans;
        
        dfs(0, s, ans, res);
        return res;
    }
};