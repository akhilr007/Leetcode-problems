/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root == NULL) return "";
        
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()>0){
            
            auto rem = q.front(); q.pop();
            
            if(rem == NULL){
                s += "#,";
            }
            else{
                s += to_string(rem->val) + ',';
            }
            
            if(rem != NULL){
                q.push(rem->left);
                q.push(rem->right);
            }
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size() == 0) return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()>0){
            
            auto rem = q.front(); q.pop();
            
            getline(s, str, ',');
            if(str == "#"){
                rem->left = NULL;
            }
            else{
                TreeNode* node = new TreeNode(stoi(str));
                rem->left = node;
                q.push(node);
            }
            
            getline(s, str, ',');
            if(str == "#"){
                rem->right = NULL;
            }
            else{
                TreeNode* node = new TreeNode(stoi(str));
                rem->right = node;
                q.push(node);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));