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
class BSTIterator {
    private Stack<TreeNode> st;
    
    private void pushAll(TreeNode root){
        
        while(root != null){
            st.push(root);
            root = root.left;
        }
    }
    
    public BSTIterator(TreeNode root) {
        st = new Stack();
        pushAll(root);
    }
    
    public int next() {
        
        TreeNode tmpNxt = st.peek();
        st.pop();
        
        pushAll(tmpNxt.right);
        return tmpNxt.val;
    }
    
    public boolean hasNext() {
        return st.size() != 0;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */