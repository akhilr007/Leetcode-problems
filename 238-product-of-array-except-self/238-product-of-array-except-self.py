"""
1 2 3 4 : left 1 2 2 6  
        right:24 12 4 4
        ans :  24 12
"""
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        prefix = [1]*len(nums)
        postfix = [1]*len(nums)
        
        for i in range(len(nums)):
            if i==0:
                prefix[i] = nums[i]
            else:
                prefix[i] = prefix[i-1]*nums[i]
        
        
        for i in range(len(nums)-1, -1, -1):
            if i==len(nums)-1:
                postfix[i] = nums[i]
            else:
                postfix[i] = postfix[i+1]*nums[i]
                
        
        res = [1]*len(nums)
        
        for i in range(len(nums)):
            if i == 0:
                res[i] = postfix[i+1]
            elif i == len(nums)-1:
                res[i] = prefix[i-1]
            else:
                res[i] = prefix[i-1]*postfix[i+1]
            
        print(prefix, postfix)
        return res
                
        