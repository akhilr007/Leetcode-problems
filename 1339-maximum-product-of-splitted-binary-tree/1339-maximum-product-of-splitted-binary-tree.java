class Solution {
    long total = 0;
    long maxP = 0;
    
    public int sum(TreeNode root) {
        if (root == null) return 0;

        int sumLeft = sum(root.left);
        int sumRight = sum(root.right);
        long subtreeSum = root.val + sumLeft + sumRight;
        
        long remSubtreeSum = total - subtreeSum;
        maxP = Math.max(maxP, subtreeSum * remSubtreeSum);
        
        return (int)subtreeSum;
    }


    public int maxProduct(TreeNode root) {

        if (root == null) return 0;

        total = sum(root);
        maxP = 0;
        
        sum(root);
        return (int)((maxP) % (long)(1e9+7));
    }
}
