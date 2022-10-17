class Solution {
    public boolean checkIfPangram(String sentence) {
        int seen=0;
        for(char ch : sentence.toCharArray()){
            int bit = ch - 'a';
            seen = seen | (1 << bit);
        }
        
        return seen == ((1 << 26) - 1);
    }
}