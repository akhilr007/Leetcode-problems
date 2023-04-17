class Solution {
public:
    int pivotInteger(int n) {
        
        int totalSum = (n * (n+1))/2;
        
        int leftSum = 0;
        for(int i=1; i<=n; i++){
            totalSum -= i;
            if(leftSum == totalSum)
                return i;
            leftSum += i;
        }
        
        return -1;
    }
};