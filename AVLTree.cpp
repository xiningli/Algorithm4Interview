#include "AVLTree.h"



AVLTree::AVLTree()
{
	root = NULL;
	nodeCount = 0;
}


AVLTree::~AVLTree()
{
}

void AVLTree::Insert(int32_t val)
{
	if(Insert(val, root))
		nodeCount++;
}

bool AVLTree::Insert(int32_t value, AVLNode * &node)
{
	if (node == NULL)
	{
		node = new AVLNode(value, NULL, NULL, 1);
		return true;
	}
	else if (value < node->value)
	{
		Insert(value, node->left);
		if (Height(node->left) - Height(node->right) == 2)		// if unbalanced
		{
			if (value < node->left->value)						// if new node is in the left subtree of node's left node
				SingleRotate(node, WITH_LEFT_CHILD);
			else												// if new node is in the right subtree of node's left node
				//SingleRotate(node, WITH_RIGHT_CHILD);
				DoubleRotate(node, WITH_RIGHT_CHILD);
		}
	}
	else if (value > node->value)
	{
		Insert(value, node->right);
		if (Height(node->right) - Height(node->left) == 2)		// if unbalanced
		{
			if (value > node->right->value)						// if new node is in the right subtree of node's right node
				SingleRotate(node, WITH_RIGHT_CHILD);
			else												// if new node is in the left subtree of node's right node
				//SingleRotate(node, WITH_LEFT_CHILD);
				DoubleRotate(node, WITH_LEFT_CHILD);
		}
	}
	else														// if value already exists, return false
		return false;

	node->height = Height(node->left) >= Height(node->right) ? Height(node->left) + 1 : Height(node->right) + 1;

	return true;
}

AVLNode* AVLTree::findMax(AVLNode * node)
{
	if (node != NULL)
		while (node->right != NULL)
			node = node->right;
	return node;
}

AVLNode * AVLTree::findMin(AVLNode * node)
{
	if (node != NULL)
		while (node->left != NULL)
			node = node->left;
	return node;
}

int32_t AVLTree::Height(AVLNode * node)
{
	//return int32_t();
	if (node != NULL)
		return node->height;
	else
		return 0;
}

void AVLTree::Delete(int32_t val)
{
	if (Delete(val, root))
		nodeCount--;
}
bool AVLTree::Delete(int32_t value, AVLNode * &node)
{
	if (node == NULL)
		return false;
	else if (value < node->value)								// if deleted node is in left subtree
	{
		Delete(value, node->left);
		if (Height(node->right) - Height(node->left) == 2)		// if unbalanced
		{
			if (Height(node->right->right) >= Height(node->right->left))
				SingleRotate(node, WITH_RIGHT_CHILD);
			else
				DoubleRotate(node, WITH_LEFT_CHILD);
		}
	}
	else if (value > node->value)
	{
		Delete(value, node->right);
		if (Height(node->left) - Height(node->right) == 2)		// if unbalanced
		{
			if (Height(node->left->left) >= Height(node->left->right))
				SingleRotate(node, WITH_LEFT_CHILD);
			else
				DoubleRotate(node, WITH_RIGHT_CHILD);
		}
	}
	else 
	{
		if (node->left != NULL&&node->right != NULL)			// innernode
		{														//     o
			//AVLNode *maxInLeft = findMax(node->left);			//	    |
			//node->value = maxInLeft->value;					//   o   o
			//Delete(maxInLeft->value, node->left);
			AVLNode *minInRight = findMin(node->right);
			node->value = minInRight->value;
			Delete(minInRight->value, node->right);
		}
		else													//	 -> o		     o
		{														//	   /	or	    /
			AVLNode* oldNode = node;							//	  o		    -> o (leaf)
			node = node->left != NULL ? node->left : node->right;
			delete oldNode;
		}														//
	}

	if(node!=NULL)
		node->height = Height(node->left) >= Height(node->right) ? Height(node->left) + 1 : Height(node->right) + 1;
	return true;
}



bool AVLTree::Access(int32_t val)
{	
	return Access(val, root);
}

int AVLTree::Count()
{
	return nodeCount;
}

bool AVLTree::Access(int32_t value, AVLNode * node)
{
	if (node == NULL)
		return false;
	else if (value == node->value)
		return true;
	else if (value < node->value)
		return Access(value, node->left);
	else
		return Access(value, node->right);
}

std::string AVLTree::PrintPreOrder() const
{
	if (root == NULL) return "";
	std::string treeStringPreOrder = "";						// initialize
	RenewTreeString(root, treeStringPreOrder, PREORDER);		// print
	treeStringPreOrder.erase(treeStringPreOrder.length() - 1);	// remove last space
	return treeStringPreOrder;
}

std::string AVLTree::PrintInOrder() const
{
	if (root == NULL) return "";
	std::string treeStringInOrder = "";						// initialize
	RenewTreeString(root, treeStringInOrder, INORDER);		// print
	treeStringInOrder.erase(treeStringInOrder.length() - 1);	// remove last space
	return treeStringInOrder;
}

void AVLTree::RenewTreeString(AVLNode * node, std::string &treeString, printTreeOrder order) const
{
	switch ((order))
	{
	case PREORDER:
		if (node == NULL) return;
		// print node
		treeString += std::to_string(node->value);
		treeString += " ";

		// print left node
		RenewTreeString(node->left, treeString, PREORDER);

		// print right node
		RenewTreeString(node->right, treeString, PREORDER);
		break;
	case INORDER:
		if (node == NULL) return;
		// print left node
		RenewTreeString(node->left, treeString, INORDER);

		// print node
		treeString += std::to_string(node->value);
		treeString += " ";

		// print right node
		RenewTreeString(node->right, treeString, INORDER);
		break;
	case POSTORDER:
		if (node == NULL) return;		
		// print left node
		RenewTreeString(node->left, treeString, POSTORDER);

		// print right node
		RenewTreeString(node->right, treeString, POSTORDER);

		// print node
		treeString += std::to_string(node->value);
		treeString += " ";
		break;
	default:
		break;
	}
}

void AVLTree::SingleRotate(AVLNode * &node, rotateType type)
{
	AVLNode *child = NULL;
	switch (type)
	{
	case WITH_LEFT_CHILD:
		child = node->left;
		node->left = child->right;
		child->right = node;
		child->height = Height(child->left) >= Height(child->right) ? Height(child->left) + 1 : Height(child->right) + 1;
		node->height = Height(node->left) >= Height(node->right) ? Height(node->left) + 1 : Height(node->right) + 1;
		node = child;
		break;
	case WITH_RIGHT_CHILD:
		child = node->right;
		node->right = child->left;
		child->left = node;
		child->height = Height(child->left) >= Height(child->right) ? Height(child->left) + 1 : Height(child->right) + 1;
		node->height = Height(node->left) >= Height(node->right) ? Height(node->left) + 1 : Height(node->right) + 1;
		node = child;
		break;
	default:
		break;
	}
}

void AVLTree::DoubleRotate(AVLNode * &node, rotateType type)
{
	switch (type)
	{
	case WITH_LEFT_CHILD:
		SingleRotate(node->right, WITH_LEFT_CHILD);
		SingleRotate(node, WITH_RIGHT_CHILD);
		break;
	case WITH_RIGHT_CHILD:
		SingleRotate(node->left, WITH_RIGHT_CHILD);
		SingleRotate(node, WITH_LEFT_CHILD);
		break;
	default:
		break;
	}
}



