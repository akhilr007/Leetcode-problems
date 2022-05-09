class Solution {
public:
    const string code[9] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> helperUtil(string digits){
        
        if(digits.length() == 0){
            vector<string> bans;
            bans.push_back("");
            return bans;
        }
        
        char ch = digits[0];
        string ros = digits.substr(1);
        
        vector<string> rans = helperUtil(ros);
        vector<string> ans;
        
        string charCode = code[ch-'0'-1];
        
        for(int i=0; i<charCode.length(); i++){
            
            char mch = charCode[i];
            
            for(int j=0; j<rans.size(); j++){
                ans.push_back(mch + rans[j]);
            }
        }
        
        return ans;
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if(digits.length() == 0){
            return res;
        }
        
        res = helperUtil(digits);
        return res;
    }
};