/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int helper(TreeNode root, int maxVal, int[] res){
        
        if(root == null) return 0;
        
        res[0] += root.val >= maxVal ? 1 : 0;
        
        helper(root.left, Math.max(maxVal, root.val), res);
        helper(root.right, Math.max(maxVal, root.val), res);
        
        return res[0];
    }
    
    public int goodNodes(TreeNode root) {
        int[] res = {0};
        return helper(root, root.val, res);
    }
}