class Solution {
private:
    int solveRec(int n){
        
        if(n == 1 || n == 2) return n;
        
        int oneStep = solveRec(n-1);
        int twoStep = solveRec(n-2);
        
        return oneStep + twoStep;
    }
    
    int solveMem(int n){
        
        if(n == 1 || n == 0) return 1;
        if(t[n] != -1) return t[n];
        
        int oneStep = solveMem(n-1);
        int twoStep = solveMem(n-2);
        
        return t[n] = oneStep + twoStep;
    }
public:
    
    int t[46];
    
    int climbStairs(int n) {
        memset(t, -1, sizeof t);
        return solveMem(n);
    }
};