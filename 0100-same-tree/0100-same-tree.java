class Solution {
    
    public boolean isSameTree(TreeNode p, TreeNode q) {
        
        if(p == null && q == null) return true;
        if(p == null || q == null) return false;
        
        Queue<TreeNode> q1 = new LinkedList<>();
        Queue<TreeNode> q2 = new LinkedList<>();
        q1.add(p);
        q2.add(q);
        
        while(q1.size() > 0 && q2.size() > 0){
            
            TreeNode node1 = q1.remove();
            TreeNode node2 = q2.remove();
            
            if(node1.val != node2.val) return false;
            
            if(node1.left != null && node2.left != null){
                q1.add(node1.left);
                q2.add(node2.left);
            }
            else if(node1.left != null || node2.left != null)
                return false;
            
            if(node1.right != null && node2.right != null){
                q1.add(node1.right);
                q2.add(node2.right);
            }
            else if(node1.right != null || node2.right != null)
                return false;
        }
        
        return true;
    }
}