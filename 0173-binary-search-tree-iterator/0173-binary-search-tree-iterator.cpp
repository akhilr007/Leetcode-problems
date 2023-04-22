class BSTIterator {
private:
    stack<TreeNode*> bst;
    
    void pushAll(TreeNode* root){
        
        while(root){
            bst.push(root);
            root = root->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        
        TreeNode* topNode = bst.top();
        bst.pop();
        
        pushAll(topNode->right);
        return topNode->val;
    }
    
    bool hasNext() {
        return bst.empty() == false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */