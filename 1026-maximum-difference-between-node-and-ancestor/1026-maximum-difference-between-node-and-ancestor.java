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
    
    int pathMin = Integer.MAX_VALUE, pathMax=Integer.MIN_VALUE;
    private int optimal(TreeNode root, int pathMin, int pathMax){
        
        if(root == null){
            return Math.abs(pathMax - pathMin);
        }
        
        pathMin = Math.min(pathMin, root.val);
        pathMax = Math.max(pathMax, root.val);
        
        int left = optimal(root.left, pathMin, pathMax);
        int right = optimal(root.right, pathMin, pathMax);
        
        return Math.max(left, right);
    }
    
    public int maxAncestorDiff(TreeNode root) {
        
        //bruteForce(root)
        return optimal(root, pathMin, pathMax);
        // return maxDiff;
    }
}