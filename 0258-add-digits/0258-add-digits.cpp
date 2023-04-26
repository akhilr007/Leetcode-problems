class Solution {
public:
    int addDigits(int num) {
        
        int sum = INT_MAX;
        
        int temp = num;
        
        while(sum > 9){
            
            sum = 0;
            
            while(temp > 0) {

                int lastDigit = temp % 10;
                temp /= 10;

                sum += lastDigit;
            }
            
            temp = sum;
        }
        
        
        return sum == INT_MAX ? 0 : sum;
    }
};