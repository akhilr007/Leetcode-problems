class Solution {
public:
    bool isOverlap(unordered_set<char>& set, string& curString){
        
        unordered_set<char> selfCheck;
        for(int i=0; i<curString.length(); i++){
            char ch = curString[i];
            if(selfCheck.find(ch) != selfCheck.end()) return true;
            selfCheck.insert(ch);
        }
        
        for(int i=0; i<curString.length(); i++){
            char ch = curString[i];
            if(set.find(ch) != set.end()) return true;
        }
        
        return false;
    }
    
    int helper(int idx, vector<string>& arr, unordered_set<char>& set, int len){
        
        if(idx >= arr.size()) return len;
        
        string curString = arr[idx];
        if(isOverlap(set, curString) == true){
            return helper(idx+1, arr, set, len);
        }
        else{
            for(int i=0; i<curString.length(); i++){
                set.insert(curString[i]);
            }
            len += curString.length();
            int op1 = helper(idx+1, arr, set, len);
            
            // skip
            for(int i=0; i<curString.length(); i++){
                set.erase(curString[i]);
            }
            len -= curString.length();
            int op2 = helper(idx+1, arr, set, len);
            
            return max(op1, op2);
        }
    }
    int maxLength(vector<string>& arr) {
        
        unordered_set<char> set;
        return helper(0, arr, set, 0);
    }
};