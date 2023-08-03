class Solution {
public:
    const vector<string> digitToCharMapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void dfs(int i, string curString, string& digits, vector<string>& result){
        
        if(curString.length() == digits.length()){
            result.push_back(curString);
            return;
        }
        
        int digitIndex = digits[i]-'0';
        for(char ch: digitToCharMapping[digitIndex]){
            dfs(i+1, curString+ch, digits, result);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.length()==0)
            return {};
        
        vector<string> result;
        
        dfs(0, "", digits, result);
        return result;
        
    }
};