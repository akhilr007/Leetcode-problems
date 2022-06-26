class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        
        l, r = 0, len(numbers)-1
        res = []
        
        while l<r: 
            if numbers[l] + numbers[r] == target:
                res.append(l+1)
                res.append(r+1)
                break
            elif numbers[l] + numbers[r] > target:
                r -= 1
            else:
                l += 1
        return res