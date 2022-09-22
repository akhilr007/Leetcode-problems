class Solution {
public:
    void reverse(string& s, int i, int j){
        
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }

    }
    
    string reverseWords(string s) {
        
        int i=0;
        int j=0;
        
        while(j < s.length()){
            
            if(s[j] != ' '){
                j++;
                continue;
            }
            
            int l=i;
            int r=j-1;
            reverse(s, l, r);
            
            i=j+1;
            j++;
        }
        
        reverse(s, i, j-1);
        return s;
    }
};