class Solution {
public:
    bool isVowel(char ch){
        
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    
    int maxVowels(string s, int k) {
        
        int n = s.length();
        
        int result = 0;
        
        int cnt=0;
        // first k
        for(int i=0; i<k; i++){
            
            if(isVowel(s[i])){
                cnt++;
            }
        }
        
        result = max(result, cnt);
        
        int j=0;
        
        for(int i=k; i<n; i++){
            
            if(isVowel(s[j])){
                cnt--;
            }
            
            if(isVowel(s[i])){
                cnt++;
            }
            
            result = max(result, cnt);
            j++;
        }
        
        
        return result;
    }
};