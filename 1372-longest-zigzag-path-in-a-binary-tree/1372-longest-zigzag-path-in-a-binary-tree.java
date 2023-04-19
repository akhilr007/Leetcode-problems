class Solution {
    
    public int maxPath = 0;
    
    public void solve(TreeNode root, int l, int r){
        
        if(root == null)
            return;
        
        maxPath = Math.max(maxPath, Math.max(l, r));
        
        solve(root.left, r+1, 0);
        solve(root.right, 0, l+1);
    }
    
    public int longestZigZag(TreeNode root) {
        
        solve(root, 0, 0); 
        return maxPath;
    }
}