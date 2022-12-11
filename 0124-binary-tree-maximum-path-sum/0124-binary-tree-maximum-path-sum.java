class Solution {
    int maxSum = Integer.MIN_VALUE;
    private int solve(TreeNode root){
        
        if(root == null) return 0;
        
        int left = solve(root.left);
        int right = solve(root.right);
        
        int subtreePath = root.val + left + right;
        int singlePath = root.val + Math.max(left, right);
        int rootPath = root.val;
        
        maxSum = Math.max(maxSum, Math.max(subtreePath, Math.max(singlePath, rootPath)));
        
        return Math.max(singlePath, rootPath);
    }
    
    public int maxPathSum(TreeNode root) {
        solve(root);
        return maxSum;
    }
}