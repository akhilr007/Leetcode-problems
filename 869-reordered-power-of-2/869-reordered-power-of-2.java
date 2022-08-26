class Solution {
    public boolean reorderedPowerOf2(int n) {
        
        int[] inputDigitCount = freqCount(n);
        
        for(int i=0; i<31; i++){
            
            int powerOf2 = (int)Math.pow(2, i);
            int[] powerOf2Freq = freqCount(powerOf2);
            if(compareArray(powerOf2Freq, inputDigitCount)){
                return true;
            }
        }
        
        return false;
    }
    
    private boolean compareArray(int[] a, int[] b){
        
        for(int i=0; i<10; i++){
            if(a[i] != b[i]) return false;
        }
        
        return true;
    }
    
    private int[] freqCount(int n){
        
        int[] digitCount = new int[10];
        while(n > 0){
            digitCount[n%10]++;
            n /= 10;
        }
        
        return digitCount;
    }
}