class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n == 1) return true;
        if(n == INT_MIN) return false;
        
        bool containsSingleSetBit = (n & (n-1)) == 0;
        bool fourOrSixthInZerothPlace = (n%10==4 || n%10==6);
        
        return containsSingleSetBit && fourOrSixthInZerothPlace;
    }
};