class Solution {
public:
    bool isValid(string &s, int idx, int len){
        
        if(idx + len > s.size()) return false;
        
        string str = s.substr(idx, len);
        
        if(str.size() > 1 && str[0] == '0') return false;
        
        int val = stoi(str);
        
        if(val > 255) return false;
        
        return true;
        
        
    }
    
    
    void helper(string &s, int idx, int par, vector<string>& res, string ans){
        
        if(idx == s.size() && par == 4){
            ans.pop_back();
            res.push_back(ans);
            return;
        }
        
        if(isValid(s, idx, 1)){
            helper(s, idx+1, par+1, res, ans + s.substr(idx, 1) + ".");
        }
        
        if(isValid(s, idx, 2)){
            helper(s, idx+2, par+1, res, ans + s.substr(idx, 2) + ".");
        }
        
        if(isValid(s, idx, 3)){
            helper(s, idx+3, par+1, res, ans + s.substr(idx, 3) + ".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        
        if(s.size()>12) return {};
        
        vector<string> res;
        string ans="";
        helper(s, 0, 0, res, ans);
        return res;
    }
};