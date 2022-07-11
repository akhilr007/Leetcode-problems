# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root, res):
        if not root:
            return 0
        
        leftMax = self.helper(root.left, res)
        rightMax = self.helper(root.right, res)
        leftMax = max(0, leftMax)
        rightMax = max(0, rightMax)
        
        res[0] = max(res[0], root.val + leftMax + rightMax)
        
        return root.val + max(leftMax, rightMax)
        
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        
        res = [root.val]
        self.helper(root, res)
        ans = res[0]
        return ans
    