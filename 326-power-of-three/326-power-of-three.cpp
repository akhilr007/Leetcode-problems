class Solution {
public:
    bool isPowerOfThree(int n) {
        
        int threePowOf19 = pow(3, 19);
        if(n>0 && threePowOf19 % n == 0) return true;
        else return false;
    }
};