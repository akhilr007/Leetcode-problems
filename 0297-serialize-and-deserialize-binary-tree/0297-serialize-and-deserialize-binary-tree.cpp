class Codec {
public:
    string serialize(TreeNode* root) {
        
        if(root == NULL)
            return "";
        
        string s="";
        
        queue <TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            auto node = q.front();
            q.pop();
            
            if(node == NULL){
                s.append("#,");
                continue;
            }
            
            s.append(to_string(node->val) + ',');
            q.push(node->left);
            q.push(node->right);
        }
        
        return s;
        
    }

    TreeNode* deserialize(string data) {
        
        if(data.size() == 0)
            return NULL;
        
        stringstream s(data);
        string str;

        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            auto node = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            
            getline(s, str, ',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        
        return root;
        
    }
};
