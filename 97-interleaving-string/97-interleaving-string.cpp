class Solution {
public:
    bool f(int i, int j, int k, string& s1, string& s2, string& s3){
        
        if(k < 0 && i < 0 && j < 0) return true;
        
        
        if(i>=0 && k>=0 && s3[k] == s1[i]){
            if(j>=0 && k>=0 && s3[k] == s2[j]){
                return f(i-1, j, k-1, s1, s2, s3) || f(i, j-1, k-1, s1, s2, s3);
            }
            else return f(i-1, j, k-1, s1, s2, s3);
        }
        if(j>=0 && k>=0 && s3[k] == s2[j]){
            return f(i, j-1, k-1, s1, s2, s3);
        }
        else{
            return false;
        }
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();
        
        if (n + m != o) return false;
        if(s1.length() == 0){
            return s2 == s3;
        }
        else if(s2.length() == 0){
            return s1 == s3;
        }
        
        return f(n-1, m-1, o-1, s1, s2, s3);
    }
};