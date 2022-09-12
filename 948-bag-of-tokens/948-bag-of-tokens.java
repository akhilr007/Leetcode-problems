class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        
        Arrays.sort(tokens);
        int i=0, j=tokens.length-1;
        
        int maxScore = 0;
        int currScore = 0;
        while(i<=j){
            if(power >= tokens[i]){
                power -= tokens[i];
                currScore += 1;
                i++;
            }
            else if(currScore >= 1){
                power += tokens[j];
                currScore -= 1;
                j--;
            }
            else{
                break;
            }
            
            maxScore = Math.max(maxScore, currScore);
        }
        
        return maxScore;
    }
}