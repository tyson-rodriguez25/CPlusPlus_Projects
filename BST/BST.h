#ifndef BST_H
#define BST_H
#include "BSTInterface.h"
//#include "BTNode.h"
using namespace std;
template<typename T>
class BST : public BSTInterface<T> {
private:
	struct Node {
		T data;
		Node* left;
		Node* right;
		Node(T d) {
			data = d;
			left = NULL;
			right = NULL;
		}
		

	};
	Node* root;
	string levelOrderString = "";
public:
	BST() {
		root = NULL;
	}
	~BST() {
		clearTree();
	}
	

	virtual bool removeNode(const T& data) {
		return removeNode(root, data);
	}
	virtual bool clearTree() {
		return clearTree(root);
	}
	// My toString Friend
	friend std::ostream& operator<< (ostream& os, const BSTInterface<T>& bst) {
		os << bst.toString();
		return os;
	}

	// Calls the addNode Function
	virtual bool addNode(const T& data) {
		return addNode(root, data);
	}

	// Adds a node and checks for duplicates
	virtual bool addNode(Node*& node, const T& data) {
		if (node == NULL) {
			node = new Node(data);
			return true;
		}
		if (data == node->data) return false;
		if (data < node->data) {
			return addNode(node->left, data);
		}
		if (data > node->data) {
			return addNode(node->right, data);
		}
	}

	// Finds and removes a Node and resturctures the BST
	virtual bool removeNode(Node*& node, const T& data) {
		if (node == NULL) {
			return false;
		}
		else if (data < node->data) {
			return removeNode(node->left, data);
		}
		else if (data > node->data) {
			return removeNode(node->right, data);
		}
		else if (node->left == NULL && node->right == NULL) {
			delete node;
			node = NULL;
			return true;
		}
		else if (node->left != NULL && node->right == NULL) {
			Node* ptr = node;
			node = node->left;
			delete ptr;
			return true;
		}
		else if (node->left == NULL && node->right != NULL) {
			Node* ptr = node;
			node = node->right;
			delete ptr;
			return true;
		}
		else if (node->left != NULL && node->right != NULL) {
			Node* ptr = node;
			ptr = node->left;
				while (ptr->right != NULL) {
					ptr = ptr->right;
				}
			node->data = ptr->data;
			removeNode(node->left, ptr->data);
			return true;
		}
		return removeNode(node->left, data);
	}

	// Goes through the BST and deletes each Node
	virtual bool clearTree(Node*& node) {
		if (node == NULL) {
			return true;
		}
		else if (node->left == NULL && node->right == NULL) {
			delete node;
			node = NULL;
			return clearTree(root);
		}
		else if (node->left != NULL && node->right == NULL) {
			return clearTree(node->left);
		}
		else if (node->left == NULL && node->right != NULL) {
			return clearTree(node->right);
		}
		else if (node->left != NULL && node->right != NULL) {
			return clearTree(node->left);
		}
		return false;
	}

	// Prints out in Level-Order
	bool outLevel(Node* root, int level, stringstream& out) const
	{
		if (root == NULL) return false;
		if (level == 0)
		{
			out << " " << root->data;
			if ((root->left != NULL) || (root->right != NULL)) return true;
			return false;
		}
		if ((level == 1) && !root->left && root->right) out << " _";
		bool left = outLevel(root->left, level - 1, out);
		bool right = outLevel(root->right, level - 1, out);
		if ((level == 1) && root->left && !root->right) out << " _";
		return left || right;
	}

	virtual string toString() const
	{
		stringstream out;
		if (root == NULL) out << " Empty";
		else
		{
			int level = -1;
			do
			{
				out << endl << "  " << ++level << ":";
			} while (outLevel(root, level, out));
		}
		return out.str();
	}

};

#endif
