/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minCamera(TreeNode* root, int& camera){
        
        if(root == NULL) return 1;
        
        int lchild = minCamera(root->left, camera);
        int rchild = minCamera(root->right, camera);
        
        if(lchild == -1 || rchild == -1){
            camera++;
            return 0;
        }
        
        if(lchild == 0 || rchild == 0){
            return 1;
        }
        
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        
        int camera=0;
        if(minCamera(root, camera) == -1) camera++;
        return camera;
    }
};