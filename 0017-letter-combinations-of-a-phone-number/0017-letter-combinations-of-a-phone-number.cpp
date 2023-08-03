class Solution {
public:
    const string digitToCharMapping [10] = {"", "", "abc", 
                                            "def", "ghi", "jkl",
                                            "mno", "pqrs", "tuv", "wxyz"};
    
    void dfs(int index, string& curString, string& digits, vector<string>& result){
        
        if(index >= digits.size()){
            result.push_back(curString);
            return;
        }
        
        int digitIndex = digits[index]-'0'; //'2' -> 2
        for(char ch: digitToCharMapping[digitIndex]){
            curString.push_back(ch);
            dfs(index+1, curString, digits, result);
            curString.pop_back();
        }
    }
    
    vector<string> letterCombinations(string& digits) {
        
        if(digits.length()==0)
            return {};
        
        vector<string> result;
        string curString;
        
        dfs(0, curString, digits, result);
        return result;
    }
};