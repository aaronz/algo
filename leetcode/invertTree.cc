#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	TreeNode* invertTree(TreeNode* root){
		if(root != NULL){
			TreeNode* temp = root->right;
			root->right = invertTree(root->left);
			root->left = invertTree(temp);
		}
		return root;
	}
};

void print_tree(TreeNode* root){
	if(root != NULL){
		print_tree(root->left);
		print_tree(root->right);
		cout<<root->val<<" ";
	}
}

void main(){
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);
	print_tree(root);
	cout<<endl;
	Solution *s = new Solution();
	s->invertTree(root);
	print_tree(root);
}