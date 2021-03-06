// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, 
    unordered_map<int, int> & mp){
        
        // base case
        if(index >= n || inOrderStart > inOrderEnd){
            return NULL;
        }
        
        int element = pre[index++];
        Node* root = new Node(element);
        int position = mp[element];
        
        root->left = solve(in, pre, index, inOrderStart, position-1, n, mp);
        root->right = solve(in, pre, index, position+1, inOrderEnd, n, mp);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex=0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[in[i]] = i;
        }
        
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n, mp);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends