class Solution:
    def isPossible(self, target: List[int]) -> bool:
        
        totalSum=0
        heap = []
        heapify(heap)
        
        for el in target:
            heappush(heap, -1*el)
            totalSum += el
        
        while(len(heap) > 0):
            
            maxEl = -1 * heappop(heap)
            # print(maxEl)
            remTotal = totalSum - maxEl
            
            if maxEl == 1 or remTotal == 1:
                return True
            
            if remTotal == 0 or maxEl < remTotal:
                return False
            
            updateMax = maxEl % remTotal
            
            if updateMax == 0:
                return False
            
            heappush(heap, -1*updateMax)
            
            totalSum = remTotal + updateMax
        
        return True