class Solution {
public:
    void helperUtil(string output, int open, int close, vector<string>& res){
        
        if(open == 0 and close == 0){
            res.push_back(output);
            return;
        }
        
        if(open != 0){
            helperUtil(output+"(", open-1, close, res);
        }
        
        if(close > open){
            helperUtil(output+")", open, close-1, res);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        int open = n;
        int close = n;
        helperUtil("", open, close, res);
        return res;
    }
};