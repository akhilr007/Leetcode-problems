class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        
        if(root == null)
            return null;
        
        if(root.val > key){
            root.left = deleteNode(root.left, key);
        }
        else if(root.val < key){
            root.right = deleteNode(root.right, key);
        }
        else{
            
            if(root.left == null)
                return root.right;
            else if(root.right == null)
                return root.left;
            else{
                
                int newData = findInorderSuccessor(root.right);
                root.val = newData;
                
                root.right = deleteNode(root.right, newData);
            }
            
            
        }
        
        return root;
    }
    
    public int findInorderSuccessor(TreeNode root){
        
        int data = root.val;
        
        while(root.left != null){
            data = root.left.val;
            root = root.left;
        }
        return data;
    }
}