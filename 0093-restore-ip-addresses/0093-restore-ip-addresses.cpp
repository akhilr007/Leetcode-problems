class Solution {
public:
    bool isValid(string& s, int idx, int len){
        
        if(idx + len > s.size())
            return false;
        
        string str = s.substr(idx, len);
        
        if(str.size()>1 and str[0] == '0')
            return false;
        
        int val = stoi(str);
        if(val > 255)
            return false;
        
        return true;
    }
    
    void solve(string& s, int idx, int partition, string cur, vector<string>& result, int n){
        
        if(idx == n and partition == 4){
            cur.pop_back(); // last me dot hatane ke liye
            result.push_back(cur);
            return;
        }
        
        if(isValid(s, idx, 1))
            solve(s, idx+1, partition + 1, cur + s.substr(idx, 1) + ".", result, n);
        
        if(isValid(s, idx, 2))
            solve(s, idx+2, partition + 1, cur + s.substr(idx, 2) + ".", result, n);
        
        if(isValid(s, idx, 3))
            solve(s, idx+3, partition + 1, cur + s.substr(idx, 3) + ".", result, n);
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        int n = s.length();
        vector<string> result;
        
        int partition = 0;
        string cur = "";
        
        solve(s, 0, partition, cur, result, n);
        return result;
    }
};