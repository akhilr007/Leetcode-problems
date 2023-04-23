class Solution {
private:
    TreeNode* first, *last, *middle, *prev;
public:
    void inorder(TreeNode* root){
        
        if(root == NULL)
            return;
        
        inorder(root->left);
        
        if(prev != NULL && (prev->val > root->val)){
            
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        
        prev = root;
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        first = last = middle = prev = NULL;
        inorder(root);
        
        if(first && last){
            swap(first->val, last->val);
        }
        else{
            swap(first->val, middle->val);
        }
    }
};