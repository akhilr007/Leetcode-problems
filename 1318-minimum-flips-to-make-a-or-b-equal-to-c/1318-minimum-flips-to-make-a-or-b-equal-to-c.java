class Solution {
    public int minFlips(int a, int b, int c) {
        
        int tempC = c;
        int tempA = a;
        int tempB = b;
        
        int ans = 0;
        while(tempC > 0 || tempB > 0 || tempA > 0){
            
            int lastBitOfC = tempC & 1;
            int lastBitOfA = tempA & 1;
            int lastBitOfB = tempB & 1;
        
            
            if(lastBitOfC == 1){
                // 1 is required
                if(lastBitOfA == 0 && lastBitOfB == 0){
                    ans += 1;
                }
            }
            else{
                // 0 is required
                if(lastBitOfA == 1 && lastBitOfB == 1){
                    ans += 2;
                }
                else if(lastBitOfA == 1 || lastBitOfB == 1){
                    ans += 1;
                }
            }
            
            tempC = tempC >> 1;
            tempA = tempA >> 1;
            tempB = tempB >> 1;
        }
        
        return ans;
    }
}