class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        
        int i=0, j=0;
        int m=0, n=0;
        
        while(i<word1.length && j<word2.length){
            
            char ch1 = word1[i].charAt(m++);
            char ch2 = word2[j].charAt(n++);
            if(ch1 != ch2) return false;
            
            if(m >= word1[i].length()){
                i++;
                m=0;
            }
            
            if(n >= word2[j].length()){
                j++;
                n=0;
            }
        }
        
        return i == word1.length && j == word2.length;
    }
}