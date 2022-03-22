/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> makeSortedList(ListNode* head){
        
        ListNode* curr = head;
        vector<int> v;
        
        while(curr != NULL){
            v.push_back(curr->val);
            curr = curr->next;
        }
        
        return v;
    }
    
    TreeNode* createTree(vector<int>& arr, int start, int end){
        
        if(start > end) return NULL;
        
        int mid = (start + end)/2;
        
        TreeNode* root = new TreeNode(arr[mid]);
        
        root->left = createTree(arr, start, mid-1);
        root->right = createTree(arr, mid+1, end);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head == NULL) return NULL;
        
        vector<int> arr = makeSortedList(head);
        
        return createTree(arr, 0, arr.size()-1);
    }
};