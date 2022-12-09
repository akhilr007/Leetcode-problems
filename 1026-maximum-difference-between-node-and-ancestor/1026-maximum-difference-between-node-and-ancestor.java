class Solution {
    int maxDiff=0;
    private void findMaxUtil(TreeNode root, TreeNode child){
        
        if(child == null) return;
        maxDiff = Math.max(maxDiff, Math.abs(root.val - child.val));
        
        findMaxUtil(root, child.left);
        findMaxUtil(root, child.right);
    }
    
    private void bruteForce(TreeNode root){
        
        if(root == null) return;
        
        findMaxUtil(root, root.left);
        findMaxUtil(root, root.right);
        
        bruteForce(root.left);
        bruteForce(root.right);
    }
    
    public int maxAncestorDiff(TreeNode root) {
        
        bruteForce(root);
        return maxDiff;
    }
}