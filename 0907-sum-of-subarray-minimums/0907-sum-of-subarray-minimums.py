class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        
        LENGTH = len(arr)
        stack = []
        nsl = [ -1 for x in range(LENGTH)]
        
        for i in range(LENGTH):
            while len(stack)>0 and arr[stack[-1]] >= arr[i]:
                stack.pop()
            
            if len(stack)!=0:
                nsl[i] = stack[-1]
            
            stack.append(i)
        
        stack.clear()
        nsr=[LENGTH for x in range(LENGTH)]
        
        for i in range(LENGTH-1, -1, -1):
            while len(stack)>0 and arr[stack[-1]] > arr[i]:
                stack.pop()
            
            if len(stack)!=0:
                nsr[i] = stack[-1]
            
            stack.append(i)
        
        print(nsl, nsr)
        total=0
        MOD = 10**9+7
        for i in range(len(arr)):
            product = (arr[i])*((i-nsl[i])*(nsr[i]-i))
            total = ((total % MOD) + (product % MOD))  % MOD
        
        return total