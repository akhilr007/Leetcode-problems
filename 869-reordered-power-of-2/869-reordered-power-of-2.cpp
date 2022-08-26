class Solution {
private:
    vector<int> freqCount(int n){
        
        vector<int> digitCount(10);
        while(n>0){
            digitCount[n%10]++;
            n = n/10;
        }
        
        return digitCount;
    }
    
    bool compareArray(vector<int>& a, vector<int>& b){
        
        for(int i=0; i<10; i++){
            if(a[i] != b[i]) return false;
        }
        
        return true;
    }
    
public:
    bool reorderedPowerOf2(int n) {
        
        vector<int> inputDigitCount = freqCount(n);
        
        for(int i=0; i<31; i++){
            int powerOf2 = (int)pow(2, i);
            vector<int> powerOf2FreqCount = freqCount(powerOf2);
            if(compareArray(inputDigitCount, powerOf2FreqCount)){
                return true;
            }
        }
        
        return false;
    }
};