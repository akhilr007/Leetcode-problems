/*
1. if(power == tokens[i]) then score = +1 and power = -tokens[i]
2. if(score >= 1) score = -1 and power = +tokens[i]

// to increase score we have to play face up
*/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        
        int i=0, j=tokens.size()-1;
        
        int maxScore = 0;
        int score = 0;
        while(i <= j && power >= 0){
            if(tokens[i] <= power){
                power -= tokens[i];
                score += 1;
                i++;
            }
            else if(score >= 1) {
                power += tokens[j];
                score -= 1;
                j--;
            }
            else{
                break;
            }
            
            //cout<<score<<endl;
            maxScore = max(maxScore, score);
        }
        
        return maxScore;
    }
};