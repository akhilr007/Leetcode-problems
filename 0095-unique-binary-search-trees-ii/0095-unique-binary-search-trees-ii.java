class Solution {
    public List<TreeNode> solve(int start, int end){
        
        if(start > end){
            List<TreeNode> l = new ArrayList<>();
            l.add(null);
            return l;
        }
        
        List<TreeNode> result = new ArrayList<>();
        
        for(int i=start; i<=end; i++){
            
            List<TreeNode> leftBSTs = solve(start, i-1);
            List<TreeNode> rightBSTs = solve(i+1, end);
            
            for(TreeNode leftRoot: leftBSTs){
                for(TreeNode rightRoot: rightBSTs){
                    
                    TreeNode root = new TreeNode(i);
                    root.left = leftRoot;
                    root.right = rightRoot;
                    result.add(root);
                }
            }
        }
        return result;
    }
    
    public List<TreeNode> generateTrees(int n) {
        
        return solve(1, n);
    }
}