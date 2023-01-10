class Solution {
    
    List<TreeNode> l1 = new ArrayList<>();
    List<TreeNode> l2 = new ArrayList<>();
    
    private void preorder(TreeNode root, List<TreeNode> l){
        
        if(root == null){
            l.add(null);
            return;
        }
        
        l.add(root);
        preorder(root.left, l);
        preorder(root.right, l);
    
    }
    
    public boolean isSameTree(TreeNode p, TreeNode q) {
        
        preorder(p, l1);
        preorder(q, l2);
        
        if(l1.size() != l2.size()) return false;
        
        for(int i=0; i<l1.size(); i++){
            
            if(l1.get(i) == null && l2.get(i) == null) continue;
            if(l1.get(i) == null || l2.get(i) == null) return false;
            if(l1.get(i).val != l2.get(i).val) return false;
        }
        
        return true;
    }
}