class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        count = {}
        freq = [[] for i in range(len(nums) + 1)]
        
        for el in nums:
            count[el] = count.get(el, 0) + 1
            
        for key, val in count.items():
            freq[val].append(key)
            
        res = []
        for i in range(len(freq)-1, 0, -1):
            for j in freq[i]:
                res.append(j);
                if(len(res) == k):
                    return res