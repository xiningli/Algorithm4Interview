#ifndef AVL_H_
#define AVL_H_
#ifndef IOSTREAM
#include <iostream>
#endif
#include <string>

struct AVLNode
{
	int32_t value;
	AVLNode *left;
	AVLNode *right;
	int32_t height;

	AVLNode() :value(0), left(NULL), right(NULL), height(0) {}
	AVLNode(const int32_t nodeValue, AVLNode *nodeLeft, AVLNode *nodeRight, int32_t nodeHeight) :value(nodeValue), left(nodeLeft), right(nodeRight), height(nodeHeight) {}
};

//enum printTreeOrder { PREORDER, INORDER, POSTORDER };

class AVLTree
{
public:
	AVLTree();
	virtual ~AVLTree();
	void Insert(int32_t val);
	// choose smallest node on the right subtree when deleting a node with two children
	void Delete(int32_t val);
	bool Access(int32_t val);
	int  Count();
	std::string PrintPreOrder() const;
	std::string PrintInOrder() const;


private:
	/* data */
	AVLNode *root;
	int nodeCount;
	
	enum printTreeOrder { PREORDER, INORDER, POSTORDER };
	void RenewTreeString(AVLNode *root, std::string &treeString, printTreeOrder order) const;

	enum rotateType { WITH_LEFT_CHILD, WITH_RIGHT_CHILD };
	void SingleRotate(AVLNode *&node, rotateType type);
	void DoubleRotate(AVLNode *&node, rotateType type);

	AVLNode* findMax(AVLNode *node);
	AVLNode* findMin(AVLNode *node);
	int32_t Height(AVLNode *node);
	bool Insert(int32_t value, AVLNode *&node);
	bool Delete(int32_t value, AVLNode *&node);
	bool Access(int32_t value, AVLNode *node);
};

#endif /* end of include guard: AVL_H_ */
