class Solution {
    public int longestPalindrome(String[] words) {
        
        Map<String, Integer> fmap = new HashMap<>(); 
        for(String word: words){
            fmap.put(word, fmap.getOrDefault(word, 0) + 1);
        }
        
        int longestPalindromeWord = 0;
        boolean centerUsed = false;
        
        for(String word: words){
            
            String rev = new StringBuilder(word).reverse().toString();
            
            if(!rev.equals(word)){
                if(fmap.get(word)>0 && fmap.getOrDefault(rev, 0)>0){
                    longestPalindromeWord += 4;
                    fmap.put(word, fmap.get(word)-1);
                    fmap.put(rev, fmap.get(rev)-1);
                }
            }
            else{
                if(fmap.get(word) >= 2){
                    longestPalindromeWord += 4;
                    fmap.put(word, fmap.get(word)-2);
                }
                else if(fmap.get(word) ==1 && centerUsed == false){
                    longestPalindromeWord += 2;
                    fmap.put(word, fmap.get(word)-1);
                    centerUsed = true;
                }
            }
        }
        
        return longestPalindromeWord;
        
    }
}