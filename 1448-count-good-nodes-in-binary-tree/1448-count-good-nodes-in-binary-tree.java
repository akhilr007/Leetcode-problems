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
    int res;
    public  void helper(TreeNode root, int maxVal){
        
        if(root == null) return;
        
        res += root.val >= maxVal ? 1 : 0;
        
        helper(root.left, Math.max(maxVal, root.val));
        helper(root.right, Math.max(maxVal, root.val));
    }
    public int goodNodes(TreeNode root) {
        res = 0;
        helper(root, root.val);
        return res;
    }
}