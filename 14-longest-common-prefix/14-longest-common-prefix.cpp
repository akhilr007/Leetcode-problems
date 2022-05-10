class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(), strs.end());
        
        int n = strs.size();
        string first = strs[0];
        string last = strs[n-1];
        
        int c=0;
        while(c < first.length()){
            if(first[c] == last[c]){
                c++;
            }
            else{
                break;
            }
        }
        
        return c == 0 ? "" : first.substr(0, c);
    }
};