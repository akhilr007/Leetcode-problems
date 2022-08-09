class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        
        arr.sort()
        m = {}
        
        for i in range(0, len(arr)):
            count = 1
            for j in range(0, i):
                if (arr[i] % arr[j] == 0) and (arr[i]//arr[j]) in m:
                    count += m[arr[j]] * m[arr[i]//arr[j]]
            
            m[arr[i]] = count
        
        
        MOD = 1000000007
        totalCount=0
        for key in m:
            totalCount += m[key]
        
        return totalCount % MOD