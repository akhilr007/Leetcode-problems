class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (n==1 or n==2)
        return 1;
        if (n%2==1 or n==0)
        return 0;
        return isPowerOfTwo(n/2);
    }
};