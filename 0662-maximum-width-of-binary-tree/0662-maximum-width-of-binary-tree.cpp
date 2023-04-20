class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        queue < pair<TreeNode*, int> > q;
        q.push( {root, 0} );
        
        int maxWidth = 0;
        
        while(!q.empty()){
            
            int size = q.size();
            int first, last;
            for(int i=0; i<size; i++){
                
                auto node = q.front().first;
                long current_index = q.front().second;
                q.pop();
                
                if(i == 0)
                    first = current_index;
                if(i == size-1)
                    last = current_index;
                
                if(node->left)
                    q.push( {node->left, 2 * current_index + 1 });
                if(node->right)
                    q.push({node->right, 2 * current_index + 2});
            }
            
            maxWidth = max(maxWidth, last - first + 1);
        }
        
        return maxWidth;
    }
};