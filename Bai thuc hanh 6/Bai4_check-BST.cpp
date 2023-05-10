/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    
    bool checkBST(Node* root) {
        if(root == NULL)    return true;
        if(root->left != NULL && root->left->data > root->data)   return false;
        if(root->right != NULL && root->right->data < root->data)  return false;
        checkBST(root->left);
        checkBST(root->right);
        return true;
    }