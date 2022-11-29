class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        permutations = []
        ans = []
        freq = [0]*len(nums)
        # print(freq)
        
        def permute(idx):
            if idx>=len(nums):
                permutations.append(ans.copy())
                return
            
            #print(ans)
            for i in range(len(nums)):
                if freq[i] == 0:
                    ans.append(nums[i])
                    freq[i]=1
                    permute(idx+1)
                    freq[i]=0
                    ans.pop()
            
        permute(0)
        return permutations
    
        
        