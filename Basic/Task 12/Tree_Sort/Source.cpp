#include <iostream>
#include <vector>

using namespace std;

class Node {
	
	public:
	int value;
	Node* left;
	Node* right;
};

class Tree {
	public:
	Node* root;
	Tree() 
	{
		root=NULL;
	}
	void insert(int val, Node* &root)
	{
		Node* X = new Node();
		X->value = val;
		if (root == NULL)
		{
			root = X;
		}
		else
		{
			if (X->value < root->value)
			{
				insert(val, root->left);
			}
			else
			{
				insert(val, root->right);
			}
		}
	}
	void inorder(Node* root)
	{
		if (root != NULL)
		{
			inorder(root->left);
			cout << root->value << " ";
			inorder(root->right);
		}
	}

	//Morris Inorder Tree Traversal
	void inorderiterative(Node* root)
	{
		Node* cur=root;

		while (cur!=NULL)
		{
			if (cur->left == NULL)
			{
				cout << cur->value<<" ";
				cur = cur->right;
			}
			else
			{
				Node* previous = cur->left;
				while (previous->right != NULL && previous->right != cur)
				{
					previous = previous->right;
				}

				if (previous->right == NULL)
				{
					previous->right = cur;
					cur = cur->left;
				}
				else
				{
					previous->right = NULL;
					cout << cur->value << " ";
					cur = cur->right;
				}
			}
		}
	}
};

int main() {
	vector<int> list{10,3,7,8,4,6,0,2,1};
	vector<int> empty;
	Tree tree;
	tree.insert(7, tree.root);
	tree.insert(10, tree.root);
	tree.insert(2, tree.root);
	tree.insert(4, tree.root);
	tree.insert(1, tree.root);
	tree.insert(6, tree.root);
	tree.insert(9, tree.root);

	tree.inorderiterative(tree.root);
	char a;
	cin >> a;
}