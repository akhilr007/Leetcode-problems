class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int minOps = 1e9;
        int flips = 0;
        int consecutiveBlacks = 0;
        
        int i=0, j=0;
        int n = blocks.length();
        
        while(j < n){
            
            if(blocks[j] == 'W'){
                flips++;
                consecutiveBlacks++;
            }
            else if(blocks[j] == 'B'){
                consecutiveBlacks++;
            }
            
            if(consecutiveBlacks == k){
                
                minOps = min(minOps, flips);
                
                if(blocks[i] == 'W'){
                    flips--;
                    consecutiveBlacks--;
                }
                else{
                    consecutiveBlacks--;
                }
                
                i++;
            }
            j++;
        }
        
        return minOps;
    }
};