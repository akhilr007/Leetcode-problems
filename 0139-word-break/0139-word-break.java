class Solution {
    private Boolean[] dp;
    public boolean solve(int index, String s, HashSet<String> set){
        
        if(index >= s.length())
            return true;
        
        if(dp[index] != null)
            return dp[index];
        
        if(set.contains(s)==true)
            return true;
        
        for(int endIndex=index+1; endIndex<=s.length(); endIndex++){
            
            String str = s.substring(index, endIndex);
            if(set.contains(str)==true && solve(endIndex, s, set)==true){
                    return dp[index] = true;
            }
        }
        
        return dp[index] = false;
    }
    
    public boolean wordBreak(String s, List<String> wordDict) {
        
        HashSet<String> set = new HashSet<>();
        for(String word: wordDict){
            set.add(word);
        }
        
        dp = new Boolean[s.length()+1];
        
        return solve(0, s, set);
    }
}