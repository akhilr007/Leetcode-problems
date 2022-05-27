class Solution {
public:
    int numberOfSteps(int num) {
        
        int minSteps=0;
        while(num>0){
            if(num%2){
                num -= 1;
            }
            else{
                num /= 2;
            }
            minSteps++;
        }
        
        return minSteps;
    }
};