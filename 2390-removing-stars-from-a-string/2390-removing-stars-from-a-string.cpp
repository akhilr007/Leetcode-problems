class Solution {
public:
    string removeStars(string s) {
        
        int n = s.length();
        vector<char> temp(n);
        
        int j=0;
        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                j--;
            }
            else{
                temp[j] = s[i];
                j++;
            }
        }
        
        string res="";
        for(int i=0; i<j; i++){
            res.push_back(temp[i]);
        }
        
        return res;
    }
};