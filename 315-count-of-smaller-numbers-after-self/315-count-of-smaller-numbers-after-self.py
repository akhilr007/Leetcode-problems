class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        
        arr = []
        for i in range(len(nums)):
            arr.append((nums[i], i))
        
        count = [0]*len(nums)
        
        def mergeSort(l, h):
            
            if l == h:
                res = []
                res.append(arr[l])
                return res
            
            mid = (l + h) // 2
            left = mergeSort(l, mid)
            right = mergeSort(mid+1, h)
            
            mergeArr = merge(left, right)
            return mergeArr
        
        def merge(left, right):
            
            n, m = len(left), len(right)
            i, j = 0, 0
            
            output = []
            
            while i<n and j<m:
                
                x, i1 = left[i]
                y, i2 = right[j]
                
                if x <= y:
                    output.append(right[j])
                    j += 1
                else:
                    count[i1] += m-j
                    output.append(left[i])
                    i += 1
            
            while i<n:
                output.append(left[i])
                i += 1
            
            while j<m:
                output.append(right[j])
                j += 1
                
            return output
        
        mergeSort(0, len(arr)-1)
        return count
    
    