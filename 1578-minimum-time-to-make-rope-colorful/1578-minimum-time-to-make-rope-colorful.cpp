class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        char prevChar = '*';
        int costPrevChar = 0;
        int minCost=0;
        
        for(int i=0; i<colors.length(); i++){
            
            if(colors[i] == prevChar){
                
                if(costPrevChar < neededTime[i]){
                    
                    minCost += costPrevChar;
                    costPrevChar = neededTime[i];
                }
                else{
                    minCost += neededTime[i];
                }
            }
            else{
                prevChar = colors[i];
                costPrevChar = neededTime[i];
            }
        }
        
        return minCost;
    }
};