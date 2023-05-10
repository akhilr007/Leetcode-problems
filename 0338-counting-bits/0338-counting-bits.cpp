class Solution {
public:
    int solve(int n){
        
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        if(n % 2 == 0)
            return solve(n/2);
        
        return 1 + solve(n/2);
    }
    vector<int> countBits(int n) {
        
        vector<int> result(n+1, 0);
        
        for(int index=0; index<=n; index++){
            result[index] = solve(index);
        }
        return result;
    }
};