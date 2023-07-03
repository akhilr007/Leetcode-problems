class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int n = s.length();
        if(s.length() != goal.length())
            return false;
        
        if(s == goal)
        {   
            vector<int> freq(26, 0);
            for(auto ch: s){
                freq[ch-'a']++;
                if(freq[ch-'a']==2)
                    return true;
            }
            
            return false;
        
        }
        
        int firstIndex = -1;
        int secondIndex = -1;
        
        for(int i=0; i<n; i++){
            
            if(s[i] != goal[i]){
                if(firstIndex == -1)
                    firstIndex = i;
                else if(secondIndex == -1){
                    secondIndex = i;
                }
                else{
                    return false;
                }
            }
        }
        
        if(secondIndex == -1)
            return false;
        
        return s[firstIndex] == goal[secondIndex] &&
            s[secondIndex] == goal[firstIndex];
    }
};