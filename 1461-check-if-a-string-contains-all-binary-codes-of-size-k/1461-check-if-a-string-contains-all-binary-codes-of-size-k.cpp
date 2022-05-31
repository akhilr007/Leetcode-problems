class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        if(k > s.length()) return false;
        
        unordered_set<string> codeSet;
        
        for(int i=0; i<=s.length()-k; i++){
            string substring = s.substr(i, k);
            codeSet.insert(substring);
        }
        
        int len = codeSet.size();
        if(len == pow(2, k)){
            return true;
        }
        else return false;
    }
};