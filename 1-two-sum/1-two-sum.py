class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        result = []
        
        hashmap = {} #  number -> index
        
        for i, el in enumerate(nums):
            if target - el in hashmap:
                result.append(hashmap[target-el])
                result.append(i)
                return result
            
            hashmap[el] = i
            
        return result
            