class Solution {
public:
    bool areEqual(vector<int>& count1, vector<int>& count2){
        
        for(int i=0; i<26; i++)
            if(count1[i] != count2[i])
                return false;
        
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length())
            return false;
        
        vector<int> count1(26, 0), count2(26, 0);
        
        for(int i=0; i<s1.length(); i++)
            count1[s1[i] - 'a']++;
        
        int i=0; 
        int j=0;
        
        while(j < s2.length()){
            
            count2[s2[j] - 'a']++;
            
            if(j-i+1 == s1.length()){
                if(areEqual(count1, count2))
                    return true;
            }
            
            if(j-i+1 < s1.length())
                j++;
            else{
                count2[s2[i]-'a']--;
                
                i++;
                j++;
            }
        }
        
        return false;
    }
};