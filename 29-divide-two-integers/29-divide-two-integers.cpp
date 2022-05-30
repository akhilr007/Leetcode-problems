class Solution {
public:
    int divide(int dividend, int divisor) {
        
        long long m = dividend;
        long long n = divisor;
        
        
        int sign;
        if((m < 0 && n < 0) || (m>0 && n>0)) sign = 1;
        else sign = -1;
        
        m = abs(dividend); // 43
        n = abs(divisor); // 8
        
        long long q = 0;
        long long t = 0;
        
        for(long long i=31; i>=0; i--){
            if(t + (n<<i) <= m){
                t += n<<i;
                q = q | (1LL << i);
            }
        }
        
        if(sign < 0) q = -q;
        return q>=INT_MAX || q < INT_MIN ? INT_MAX : q;
    }
};