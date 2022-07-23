class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        
        arr = [ (nums[i], i) for i in range(len(nums))]
        
        count = [0]*len(nums)
        
        def mergesort(l, h):
            if l == h:
                ans=[]
                ans.append(arr[l])
                return ans
            
            mid = (l + h)//2
            left = mergesort(l, mid)
            right = mergesort(mid+1, h)
            
            merged = merge(left, right)
            return merged
        
        def merge(left, right):
            
            n, m = len(left), len(right)
            i, j = 0, 0
            
            output =[]
            
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
        
        mergesort(0, len(nums)-1)
        return count