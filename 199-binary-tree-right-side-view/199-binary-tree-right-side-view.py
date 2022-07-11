# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findRightSideView(self, root, output, level):
        
        if not root:
            return
        
        if level == len(output):
            output.append(root.val)
        
        self.findRightSideView(root.right, output, level+1)
        self.findRightSideView(root.left, output, level+1)
    
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        
        output = []
        self.findRightSideView(root, output, 0);
        return output
    