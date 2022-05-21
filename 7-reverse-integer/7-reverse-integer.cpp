class Solution {
public:
    int reverse(int x) {
        
        int max=INT_MAX;
        int min=INT_MIN;

        int result = 0;
        while(x != 0){
            int digit = x%10;
            x /= 10;

            if(result > max/10 || result == max/10 && digit >= max%10) return 0;
            if(result < min/10 || result == min/10 && digit <= min%10) return 0;

            result = (result*10)+digit;
        }

        return result;
    }
};