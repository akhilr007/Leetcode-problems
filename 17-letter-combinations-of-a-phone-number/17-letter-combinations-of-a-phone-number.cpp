class Solution {
private:
    string keys[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> helper(string& digits){
        
        if(digits.length() == 0){
            vector<string> bans;
            bans.push_back("");
            return bans;
        }
        
        char ch = digits[0];
        string ros = digits.substr(1);
        
        vector<string> rans = helper(ros);
        vector<string> ans;
        
        string chars = keys[ch-'0'];
        
        for(int i=0; i<chars.length(); i++){
            char mch = chars[i];
            for(int j=0; j<rans.size(); j++){
                ans.push_back(mch + rans[j]);
            }
        }
        
        return ans;
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if(digits.length() == 0) return res;
        
        res = helper(digits);
        return res;
    }
};