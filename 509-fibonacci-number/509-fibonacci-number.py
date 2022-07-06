class Solution:
    def f(self, idx, dp):
        if idx <= 1:
            return idx
        
        if dp[idx] != -1:
            return dp[idx]
        
        dp[idx] = self.f(idx-1, dp) + self.f(idx-2, dp)
        return dp[idx]
    
    
    def fib(self, n: int) -> int:
        if(n <= 1):
            return n
        
        first, second = 0, 1
        result=first+second
        for i in range(2, n+1):
            result = first + second
            first = second
            second = result
        return result