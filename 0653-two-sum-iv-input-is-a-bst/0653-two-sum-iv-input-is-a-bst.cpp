class BSTIterator{
private:
    stack<TreeNode*> bst;
    bool reverse = false; // true -> before, false -> next
    
    void pushAll(TreeNode* root){
        
        while(root){
            bst.push(root);
            if(reverse){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }
    
public:
    BSTIterator(TreeNode* root, bool reverse){
        
        this->reverse = reverse;
        pushAll(root);
        
    }
    
    int next(){
        
        TreeNode* topNode = bst.top();
        bst.pop();
        
        if(reverse){
            pushAll(topNode->left);
        }
        else{
            pushAll(topNode->right);
        }
        
        return topNode->val;
    }
    
    bool hasNext(){
        return bst.empty() == false;
    }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        
        int i = l.next();
        int j = r.next();
        
        cout << i << " " << j << endl;
        
        while(i < j){
            
            if(i + j == k)
                return true;
            
            if(i + j < k){
                i = l.next();
            }
            else{
                j = r.next();
            }
        }
        
        return false;
    }
};