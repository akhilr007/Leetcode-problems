# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, start, end, nums):
        
        if start > end:
            return None
        
        mid = (start + end) // 2
        
        root = TreeNode(nums[mid])
        
        root.left = self.helper(start, mid-1, nums)
        root.right = self.helper(mid+1, end, nums)
        
        return root
    
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        
        n = len(nums)
        mid = (n-1)//2
        
        root = TreeNode(nums[mid])
        
        root.left = self.helper(0, mid-1, nums)
        root.right = self.helper(mid+1, n-1, nums)
        
        return root
    