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
    public TreeNode pruneTree(TreeNode root) {
        
        if(helper(root) == 0) return null;
        
        return root;
    }
    
    private int helper(TreeNode root){
        
        if(root == null) return 0;
        
        if(root.left == null && root.right == null){
            return root.val == 0 ? 0 : 1;
        }
        
        int leftSubTreeOnes = helper(root.left);
        int rightSubTreeOnes = helper(root.right);
        
        if(leftSubTreeOnes == 0) root.left = null;
        if(rightSubTreeOnes == 0) root.right = null;
        
        return leftSubTreeOnes + rightSubTreeOnes + root.val == 0 ? 0 : 1;
    }
}