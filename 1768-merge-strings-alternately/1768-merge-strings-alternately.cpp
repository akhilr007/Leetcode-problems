class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string res;
        
        int n = word1.length();
        int m = word2.length();
        
        int i=0, j=0;
        
        bool flag=false;
        while(i < n && j < m){
            
            if(flag == false){
                res.push_back(word1[i]);
                i++;
            }
            else{
                res.push_back(word2[j]);
                j++;
            }
            
            flag = !flag;
        }
        
        while(i<n){
            res.push_back(word1[i]);
            i++;
        }
        
        while(j<m){
            res.push_back(word2[j]);
            j++;
        }
        
        return res;
        
    }
};