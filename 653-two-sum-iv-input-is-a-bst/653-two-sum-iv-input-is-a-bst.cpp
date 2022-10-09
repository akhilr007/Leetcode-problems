class BSTIterator{
    stack<TreeNode*> mystack;
    // reverse -> true -> before
    // reverse -> false -> after;
    bool reverse = true;
    
public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    
    bool hasNext(){
        return mystack.size() != 0;
    }
    
    int next(){
        TreeNode* tmpNode = mystack.top();
        mystack.pop();
        
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        
        return tmpNode->val;
    }
private:
    void pushAll(TreeNode* root){
        
        while(root != NULL){
            mystack.push(root);
            if(reverse == true){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        if(!root) return false;
        
        // next iterator
        BSTIterator l(root, false);
        
        // before iterator
        BSTIterator r(root, true);
        
        int i = l.next();
        int j = r.next();
        
        while(i<j){
            if(i+j == k) return true;
            if(i+j < k) i = l.next();
            else j = r.next();
        }
        
        return false;
    }
};