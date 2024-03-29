class Solution {
    public boolean closeStrings(String word1, String word2) {
        
        if(word1.length() != word2.length()) return false;
        
        int[] freq1 = new int[26];
        int[] freq2 = new int[26];
        
        for(int i=0; i<word1.length(); i++){
            
            int idx1 = word1.charAt(i)-'a';
            int idx2 = word2.charAt(i)-'a';
            
            freq1[idx1]++;
            freq2[idx2]++;
        }
        
        for(int i=0; i<26; i++){
            if(freq1[i] != 0 && freq2[i] != 0) continue;
            if(freq1[i] == 0 && freq2[i] == 0) continue;
            return false;
        }
        
        Arrays.sort(freq1);
        Arrays.sort(freq2);
        
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]) return false;
        }
        
        return true;
    }
}