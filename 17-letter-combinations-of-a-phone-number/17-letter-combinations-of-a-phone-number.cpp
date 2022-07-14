class Solution {
public:
    void dfs(int i, string curStr, string digits, vector<string>& digitToChar, vector<string>& res){
        
        if(curStr.length() == digits.length()){
            res.push_back(curStr);
            return;
        }
        
        int digitIndex = digits[i]-'0';
        for(auto c : digitToChar[digitIndex]){
            dfs(i+1, curStr+c, digits, digitToChar, res);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if(digits.length() == 0) return res;
        
        vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        dfs(0, "", digits, digitToChar, res);
        return res;
    }
};