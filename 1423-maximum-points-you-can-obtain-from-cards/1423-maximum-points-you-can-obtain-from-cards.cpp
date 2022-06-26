/*
 0 1 2 3 4 5 6
[1 2 3 4 5 6 1]
*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n=cardPoints.size();
        
        int l=0;
        int r=n-k;
        
        int total=0;
        for(int i=r; i<n; i++){
            total += cardPoints[i];
        }
        
        int result = total;
        while(r<n){
            
            total += cardPoints[l] - cardPoints[r];
            result = max(result, total);
            l++;
            r++;
        }
        
        return result;
    }
};