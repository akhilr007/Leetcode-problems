class Solution {
public:
    
    bool isVowel(char ch){
        
        if(ch == 'A' || ch =='E' || ch == 'I' || ch =='O' || ch =='U' || ch =='a' || ch =='e' || ch =='i' || ch =='o' || ch =='u'){
            return true;
        }
        
        return false;
    }
    string reverseVowels(string s) {
        
        int i = 0;
        int j = s.length()-1;
        
        //
        while(i<j){
            
            // increment i till we find vowels from left side
            while(i<j && isVowel(s[i]) == false){
                i++;
            }
            
            // decrement j till we find vowels from right side
            while(i<j && isVowel(s[j])== false){
                j--;
            }
            
            // if both the pointers are standing on vowels, then swap them
            swap(s[i], s[j]);
            i++;
            j--;
        }
        
        return s;
        
    }
};