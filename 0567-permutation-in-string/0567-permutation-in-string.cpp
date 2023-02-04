class Solution {
public:
    bool areEqual(vector<int>& countS1, vector<int>& countS2){
        
        for(int i=0; i<26; i++){
            if(countS1[i] != countS2[i]) return false;
        }
        
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length()) return false;
        
        vector<int> countS1(26, 0), countS2(26, 0);
        
        for(int i=0; i<s1.length(); i++){
            countS1[s1[i]-'a']++;
        }
        
        int i=0;
        int j=0;
        
        while(j < s2.length()){
            
            countS2[s2[j]-'a']++;
            
            if(j-i+1 == s1.length()){
                if(areEqual(countS1, countS2)) return true;
            }
            
            if(j-i+1 < s1.length()) j++;
            else{
                countS2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        
        return false;
    }
};