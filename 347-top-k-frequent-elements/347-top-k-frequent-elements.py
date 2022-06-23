class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        count = {}
        
        heap = []
        heapify(heap)
        
        for el in nums:
            count[el] = count.get(el, 0) + 1
        
        for key in count:
            heappush(heap, (count[key], key))
            if len(heap) > k:
                heappop(heap)
                
        res = []
        while heap:
            freq, item = heappop(heap)
            res.append(item)
        return res