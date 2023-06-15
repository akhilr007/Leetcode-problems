class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        int maxSum=INT_MIN;
        int maxLevel;
        int level = 0;
        
        while(!q.empty()){
            
            int size = q.size();
            int sum = 0;
            level++;
            while(size-- > 0){
                
                auto node = q.front();
                q.pop();
                
                sum += node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
            }
            
            if(sum > maxSum){
                maxSum = sum;
                maxLevel = level;
            }
        }
        
        return maxLevel;
    }
};