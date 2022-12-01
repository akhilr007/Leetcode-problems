class Solution {
    private boolean isVowel(char ch){
        ch = Character.toLowerCase(ch);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        
        return false;
    }

    public boolean halvesAreAlike(String s) {
        
        int length = s.length();
        int countVowelA=0, countVowelB=0;
        
        for(int i=0; i<length/2; i++){
            if(isVowel(s.charAt(i))==true) countVowelA++;
        }
        
        for(int i=length/2; i<length; i++){
            if(isVowel(s.charAt(i))==true) countVowelB++;
        }
        
        return countVowelA == countVowelB;
    }
}