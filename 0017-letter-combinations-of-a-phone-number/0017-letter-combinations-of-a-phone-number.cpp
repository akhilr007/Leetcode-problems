class Solution {
public:
    const vector<string> digitToCharMapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void dfs(int i, string& curString, string& digits, vector<string>& result){
        
        if(i >= digits.length()){
            result.push_back(curString);
            return;
        }
        
        int digitIndex = digits[i]-'0';
        for(char ch: digitToCharMapping[digitIndex]){
            curString[i] = ch;
            dfs(i+1, curString, digits, result);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.length()==0)
            return {};
        
        vector<string> result;
        string curString(digits.length(), ' ');
        dfs(0, curString, digits, result);
        return result;
        
    }
};