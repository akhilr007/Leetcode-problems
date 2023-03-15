class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        
        if(root == NULL)
            return true;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            auto node = q.front();
            q.pop();

            if(node){
                q.push(node->left);
                q.push(node->right);
            }
            else{

                while(!q.empty()){

                    auto node = q.front();
                    q.pop();

                    if(node)
                        return false;
                }
            }
        }

        return true;
    }
};