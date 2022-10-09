class BSTIterator{

    Stack<TreeNode> stack;
    // reverse -> true -> before
    // reverse -> false -> after
    boolean reverse = true;

    public BSTIterator(TreeNode root, boolean isReverse){
        stack = new Stack<>();
        reverse = isReverse;
        pushAll(root);
    }
    
    public boolean hasNext(){
        return stack.size() != 0;
    }
    
    public int next(){
        
        TreeNode tmpNode = stack.pop();
        
        if(reverse == true){ // before
            pushAll(tmpNode.left);
        }
        else{
            pushAll(tmpNode.right);
        }
        
        return tmpNode.val;
    }
    
    private void pushAll(TreeNode node){
        
        while(node != null){
            stack.push(node);
            if(reverse == true){
                node = node.right;
            }
            else{
                node = node.left;
            }
        }
    }
}

class Solution {
    public boolean findTarget(TreeNode root, int k) {
        
        BSTIterator nextIterator = new BSTIterator(root, false);
        BSTIterator beforeIterator = new BSTIterator(root, true);
        
        int L = nextIterator.next();
        int R = beforeIterator.next();
        
        while(L<R){
            if(L+R == k) return true;
            
            if(L+R > k){
                // reduce R
                R = beforeIterator.next();
            }
            else{
                L = nextIterator.next();
            }
        }
        
        return false;
    }
}