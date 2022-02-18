class Solution {
public:
    int f(int idx){
        
        if(idx <= 1) return idx;
        
        return f(idx-1) + f(idx-2);
    }
    
    int fib(int n) {
        
        return f(n);
    }
};