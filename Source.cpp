#define ZSS
#ifdef ZSS
#include<iostream>
int main(void)
{
	typedef char* pstring;
	const pstring p1 = "Hello";
	const char *p2 = "world";
	//const pstring p3 = p2;
	const char *p4 = p1;
	std::cout << p1 << "hhh";
	std::cout << *p4<<"hhh";

}
#endif // ZSS


//#define myProg
//#define CONSTREE
//#define DICT
//#define CONNECTED
//#define myProgAVLTree
//#define GoogleTestAVLTree
//#define GoogleTestAVLTree2
//#define GoogleTestMMHeap
//#define FUNCTIONTEST
#ifdef FUNCTIONTEST
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a = "asw2";
	//string b = a - " ";
	//a[a.length() - 1] = '\0';
	//a.erase(a.length() - 1);
	string sub = a.substr(0, 1);
	cout << sub;
	return 0;
}
#endif // FUNCTIONTEST
#ifdef CONNECTED
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool notConnected = false;
int time = 0;
enum vertex { A, B, C, D, E, F, G, H, I, J };
vector<string> verticesName = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J" };
const int NODE_COUNT = 6;
int visited[NODE_COUNT];
int arr[NODE_COUNT];
int adjMatrix[NODE_COUNT][NODE_COUNT];
int parent[NODE_COUNT];
void init()
{
	for (int i = 0;i < NODE_COUNT;i++)
	{
		visited[i] = 0;
		arr[i] = 0;
		parent[i] = 0;
	}
	for (int i = 0;i < NODE_COUNT;i++)
		for (int j = 0;j < NODE_COUNT;j++)
			adjMatrix[i][j] = 0;
	parent[0] = -1;
}
void setAdjRelationship(vertex v1, vertex v2)
{
	adjMatrix[v1][v2] = 1;
	adjMatrix[v2][v1] = 1;
}
void printAdjMatrix()
{
	cout << "  ";
	for (int i = 0;i < NODE_COUNT;i++)
		cout << verticesName[i] << " ";
	cout << endl;
	for (int i = 0;i < NODE_COUNT;i++)
	{
		cout << verticesName[i] << " ";
		for (int j = 0;j < NODE_COUNT;j++)
			std::cout << adjMatrix[i][j] << " ";
		std::cout << std::endl;
	}
}

void printArr()
{
	cout << endl << "arrTime:" << endl;
	for (int i = 0;i < NODE_COUNT;i++)
		cout << verticesName[i] << " " << arr[i] << endl;
}
void printVisited()
{
	cout << endl << "visited:" << endl;
	for (int i = 0;i < NODE_COUNT;i++)
		cout << verticesName[i] << " " << visited[i] << endl;
}
void printParent()
{
	cout << endl << "parent:" << endl;
	//ver
	cout << verticesName[0] << " " << "-" << endl;
	for (int i = 1;i < NODE_COUNT;i++)
	{
		cout << verticesName[i] << " " << verticesName[parent[i]] << endl;
	}
}
int xmin(int a, int b)
{
	return a < b ? a : b;
}
int edgeconnected(int v)
{
	visited[v] = 1;
	arr[v] = time++;
	int minArrTime = arr[v];

	//for all w adjecent to v do
	for(int w=0;w<NODE_COUNT;w++)
		if(adjMatrix[v][w]==1)
		{
			if (!visited[w])
			{
				parent[w] = v;
				minArrTime = xmin(minArrTime, edgeconnected(w));
			}
			else
				if (parent[v] != w)
					minArrTime = xmin(minArrTime, arr[w]);//if there is any back-edge, arr[w] should be less than xyz
				else
					int breakPoint=0;
		}
	//if (minArrTime == arr[v] && v!=0)// if minArrTime not changed, graph is not two-edge connected.
	if (minArrTime == arr[v] && v != 0)// if minArrTime not changed, graph is not two-edge connected.
	{
		cout << verticesName[v] << " ";
		notConnected = true;
	}
	return minArrTime;
}
int main()
{
	init();
	setAdjRelationship(A, B);
	setAdjRelationship(B, C);
	setAdjRelationship(C, D);
	setAdjRelationship(D, E);
	setAdjRelationship(E, F);
	setAdjRelationship(A, F);
	setAdjRelationship(A, E);
	setAdjRelationship(B, D);
	edgeconnected(A);
	if (notConnected)
		std::cout << "not 1-connected: " << std::endl;
	else
		std::cout << "1-connected" << std::endl;
	printAdjMatrix();
	printArr();
	printVisited();
	printParent();
	return 0;
}
#endif // CONNECTED



#ifdef DICT
// hash example
#include <iostream>
#include <functional>
#include <string>
#include <vector>

std::hash<std::string> str_hash;
struct TableRow
{
	std::string word;
	int key;
	TableRow():word("NOTSET"),key(-1) {}
	TableRow(std::string wd, int k) :word(wd), key(k) {}
};
std::vector<TableRow> getDictionary()
{
	std::vector<TableRow> dict;
	dict.push_back(TableRow("a", str_hash("a")));
	dict.push_back(TableRow("it", str_hash("it")));
	dict.push_back(TableRow("am", str_hash("am")));
	dict.push_back(TableRow("ram", str_hash("ram")));
	dict.push_back(TableRow("pro", str_hash("pro")));
	dict.push_back(TableRow("gram", str_hash("gram")));
	dict.push_back(TableRow("gammer", str_hash("gammer")));
	dict.push_back(TableRow("program", str_hash("program")));
	dict.push_back(TableRow("programmer", str_hash("programmer")));
	dict.push_back(TableRow("me", str_hash("me")));
	dict.push_back(TableRow("merit", str_hash("merit")));
	return dict;
}
bool searchDictionary(std::string word, std::vector<TableRow> dict)
{
	for (int i = 0;i < dict.size();i++)
	{
		//if(hashTable.find(word)==true)
		if (word == dict[i].word)
			return true;		
	}
	return false;
}
//void findWords(std::string s, int length, std::string out)
void findWords(std::string s, std::string out)
{
	std::vector<TableRow> dict = getDictionary();
	int length = s.size();
	for (int index = 1;index <= s.size();index++)
	{
		std::string substring = s.substr(0, index);
		if (searchDictionary(substring, dict))
		{
			if (index == length)
			{
				out = out + substring;
				std::cout << out << std::endl;
				return;
			}
			//findWords(s.substr(index, length), length - index, out + substring + " ");
			findWords(s.substr(index, length), out + substring + " ");
		}
	}
}
int main()
{
	std::string s = "programmerit";
	//findWords(s, s.size(), "");
	findWords(s, "");
}
#endif // DICT


#ifdef CONSTREE
#include <iostream>
#include <vector>
class TreeNode
{
public:
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode() :val(0), left(NULL), right(NULL) {}// { left = NULL; right = NULL; val = 0; }
	TreeNode(int value) :val(value), left(NULL), right(NULL){}// { left = NULL; right = NULL; }
	TreeNode(int value, TreeNode* leftC, TreeNode* rightC) :val(value), left(leftC), right(rightC) {}
	static TreeNode* construct(std::vector<TreeNode> preorder, int preStart, int preEnd, std::vector<TreeNode> inorder, int inStart, int inEnd)
	{
		if (preStart>preEnd || inStart>inEnd) {
			return NULL;
		}

		int val = preorder[preStart].val;
		TreeNode *p = new TreeNode(val);

		//find parent element index from inorder
		int k = 0;
		for (int i = 0; i<inorder.size(); i++) {
			if (val == inorder[i].val) {
				k = i;
				break;
			}
		}

		p->left = construct(preorder, preStart + 1, preStart + (k - inStart), inorder, inStart, k - 1);
		p->right = construct(preorder, preStart + (k - inStart) + 1, preEnd, inorder, k + 1, inEnd);

		return p;
	}
	static TreeNode* buildTree(std::vector<TreeNode> preorder, std::vector<TreeNode> inorder)
	{
		int preStart = 0;
		int preEnd = preorder.size() - 1;
		int inStart = 0;
		int inEnd = inorder.size() - 1;

		return construct(preorder, preStart, preEnd, inorder, inStart, inEnd);
	}
};
void printTreePreOrder(TreeNode* root)
{
	if (root == NULL)
		return;

	TreeNode *left = root->left;
	TreeNode *right = root->right;

	std::cout << root->val << " ";
	printTreePreOrder(left);
	printTreePreOrder(right);
}

void printTreeInOrder(TreeNode* root)
{
	if (root == NULL)
		return;

	TreeNode *left = root->left;
	TreeNode *right = root->right;

	printTreeInOrder(left);
	std::cout << root->val << " ";
	printTreeInOrder(right);
}
void printTreePostOrder(TreeNode* root)
{
	if (root == NULL)
		return;

	TreeNode *left = root->left;
	TreeNode *right = root->right;

	printTreePostOrder(left);
	printTreePostOrder(right);
	std::cout << root->val << " ";	
}

int main()
{
	std::vector<TreeNode> preOrder;
	std::vector<TreeNode> inOrder;
	//(1) 2 4 5  3 7 6 8
	preOrder.push_back(TreeNode(1));
	preOrder.push_back(TreeNode(2));
	preOrder.push_back(TreeNode(4));
	preOrder.push_back(TreeNode(5));
	preOrder.push_back(TreeNode(3));
	preOrder.push_back(TreeNode(7));
	preOrder.push_back(TreeNode(6));
	preOrder.push_back(TreeNode(8));

	// 4 2 5 (1) 6 7 3 8
	inOrder.push_back(TreeNode(4));
	inOrder.push_back(TreeNode(2));
	inOrder.push_back(TreeNode(5));
	inOrder.push_back(TreeNode(1));
	inOrder.push_back(TreeNode(6));
	inOrder.push_back(TreeNode(7));
	inOrder.push_back(TreeNode(3));
	inOrder.push_back(TreeNode(8));

	TreeNode *root = TreeNode::buildTree(preOrder, inOrder);

	printTreePostOrder(root);

	return 0;
}


#endif



#ifdef GoogleTestMMHeap
#include <iostream>

#include "gtest/gtest.h"

#include "mmheap.h"

using namespace std;

TEST(MinMaxHeap, Test1) {
	vector<int32_t> vals = { 7, 11, 9, 55, 22, 13, 29, 31, 3, -34, -5, 100, 103, 200, 205 };
	minmaxheap::mmheap hp(50);

	hp.buildHeap(vals);
	ASSERT_EQ(hp.getMin(), -34);
	ASSERT_EQ(hp.getMax(), 205);

	hp.deleteMin();
	ASSERT_EQ(hp.getMin(), -5);
	ASSERT_EQ(hp.getMax(), 205);

	hp.deleteMax();
	ASSERT_EQ(hp.getMin(), -5);
	ASSERT_EQ(hp.getMax(), 200);

	hp.insert(300);
	ASSERT_EQ(hp.getMin(), -5);
	ASSERT_EQ(hp.getMax(), 300);

	hp.insert(-100);
	ASSERT_EQ(hp.getMin(), -100);
	ASSERT_EQ(hp.getMax(), 300);
}

TEST(MinMaxHeap, Test2) {
	vector<int32_t> vals = { 7, 11, 9, 55, 22, 13, 29, 31, 3, -34, -5, 100, 103, 200, 205 };
	vector<int32_t> vals2 = { 99, 1, 32, 44, 12, 14, 25, 34, 343, -3, -5, 10, 133, 202, 250 };
	minmaxheap::mmheap hp(50);

	hp.buildHeap(vals);
	ASSERT_EQ(hp.getMin(), -34);
	ASSERT_EQ(hp.getMax(), 205);

	hp.deleteMin();
	ASSERT_EQ(hp.getMin(), -5);
	ASSERT_EQ(hp.getMax(), 205);

	// rebuild a min-max heap
	hp.buildHeap(vals2);
	ASSERT_EQ(hp.getMin(), -5);
	ASSERT_EQ(hp.getMax(), 343);

	hp.insert(300);
	ASSERT_EQ(hp.getMin(), -5);
	ASSERT_EQ(hp.getMax(), 343);

	hp.deleteMin();
	ASSERT_EQ(hp.getMin(), -3);
	ASSERT_EQ(hp.getMax(), 343);

	hp.deleteMax();
	ASSERT_EQ(hp.getMin(), -3);
	ASSERT_EQ(hp.getMax(), 300);
}

TEST(MinMaxHeap, Test3) {
	vector<int32_t> vals = { 6 };
	minmaxheap::mmheap hp(50);

	hp.buildHeap(vals);
	ASSERT_EQ(hp.getMin(), 6);
	ASSERT_EQ(hp.getMax(), 6);

	hp.deleteMin();
	ASSERT_EQ(hp.getMin(), 0);
	ASSERT_EQ(hp.getMax(), 0);

	hp.insert(300);
	ASSERT_EQ(hp.getMin(), 300);
	ASSERT_EQ(hp.getMax(), 300);

	hp.deleteMax();
	ASSERT_EQ(hp.getMin(), 0);
	ASSERT_EQ(hp.getMax(), 0);

	hp.insert(1);
	hp.insert(3);
	ASSERT_EQ(hp.getMin(), 1);
	ASSERT_EQ(hp.getMax(), 3);

	hp.deleteMax();
	ASSERT_EQ(hp.getMin(), 1);
	ASSERT_EQ(hp.getMax(), 1);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

	//vector<int32_t> vals = { 7, 11, 9, 55, 22, 13, 29, 31, 3, -34, -5, 100, 103, 200, 205 };
	//minmaxheap::mmheap heap(50);
	//heap.buildHeap(vals);
	//heap.printHeap();
	//return 0;
}

#endif // GoogleTest

#ifdef myProg
#include <iostream>
#include <string>
//#include "XHashTable.h"
#include <math.h>
#include "mmheap.h"
//#include "gtest.h"
using namespace minmaxheap;
void insertTest(mmheap &heap)
{
	heap.insert(10);
	heap.insert(12);
	heap.insert(14);
	heap.insert(104);
	heap.insert(129);
	heap.insert(3);
	heap.insert(17);
	heap.insert(56);
	heap.printHeap();
}
int main()
{
	//cout << 5 / 3;
	//int i = 3;
	//std::cout << (2-1 < pow(2, i));
	mmheap heap(40);

	std::vector<int32_t> vals = { 7, 11, 9, 55, 22, 13, 29, 31, 3, -34, -5, 100, 103, 200, 205 };
	std::vector<int32_t> vals_3 = { 6 };
	std::vector<int32_t> vec;
	vec.push_back(10);
	vec.push_back(12);
	vec.push_back(14);
	vec.push_back(104);
	vec.push_back(129);
	vec.push_back(3);
	vec.push_back(17);
	vec.push_back(56);

	//int size = vec.size();
	//int aa = vec[0];
	heap.buildHeap(vals_3);
	//heap.buildHeap(vec);
	heap.printHeap();
	std::cout << std::endl << heap.getMax() << std::endl << heap.getMin();

	std::cout << std::endl;
	//heap.deleteMax();
	//heap.printHeap();

	return 0;
}
#endif // myProg

#ifdef GoogleTestAVLTree
#include <iostream>
#define IOSTREAM

#include "gtest/gtest.h"

#include "AVLTree.h"

using namespace std;

TEST(AVLTree, Test1) {
	AVLTree avltree;
	avltree.Insert(20);
	avltree.Insert(10);
	avltree.Insert(2);
	avltree.Access(2);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "10 2 20");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "2 10 20");

	
	avltree.Insert(15);
	avltree.Insert(18);
	avltree.Insert(12);
	avltree.Access(15);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "15 10 2 12 18 20");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "2 10 12 15 18 20");

	
	avltree.Delete(10);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "15 12 2 18 20");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "2 12 15 18 20");

	avltree.Delete(18);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "15 12 2 20");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "2 12 15 20");

	avltree.Delete(20);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "12 2 15");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "2 12 15");
	
	avltree.Insert(7);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "12 2 7 15");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "2 7 12 15");
	
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

#endif // GoogleTestAVLTree

#ifdef GoogleTestAVLTree2
#include <iostream>

#include "gtest/gtest.h"

#include "AVLTree.h"

using namespace std;

TEST(AVLTree, Test1) {
	AVLTree avltree;
	avltree.Insert(20);
	avltree.Insert(10);
	avltree.Insert(2);
	avltree.Access(2);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "10 2 20");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "2 10 20");

	avltree.Insert(15);
	avltree.Insert(18);
	avltree.Insert(12);
	avltree.Access(15);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "15 10 2 12 18 20");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "2 10 12 15 18 20");

	avltree.Delete(10);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "15 12 2 18 20");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "2 12 15 18 20");

	avltree.Delete(18);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "15 12 2 20");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "2 12 15 20");

	avltree.Delete(20);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "12 2 15");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "2 12 15");

	avltree.Insert(7);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "12 2 7 15");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "2 7 12 15");
}

TEST(AVLTree, Test2) {
	AVLTree avltree;
	avltree.Insert(50);
	avltree.Insert(25);
	avltree.Insert(10);
	avltree.Insert(5);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "25 10 5 50");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "5 10 25 50");

	avltree.Insert(7);
	avltree.Insert(3);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "7 5 3 25 10 50");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "3 5 7 10 25 50");

	avltree.Insert(30);
	avltree.Insert(20);
	avltree.Insert(8);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "7 5 3 25 10 8 20 50 30");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "3 5 7 8 10 20 25 30 50");

	avltree.Insert(15);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "10 7 5 3 8 25 20 15 50 30");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "3 5 7 8 10 15 20 25 30 50");

	avltree.Access(5);
	avltree.Delete(8);
	EXPECT_STREQ(avltree.PrintPreOrder().c_str(), "10 5 3 7 25 20 15 50 30");
	EXPECT_STREQ(avltree.PrintInOrder().c_str(), "3 5 7 10 15 20 25 30 50");
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

#endif // GoogleTestAVLTree2


#ifdef myProgAVLTree
// stack overflow: http://www.cnblogs.com/xiangwengao/archive/2012/03/16/2399888.html
#include <iostream>
#define IOSTREAM
#include <string>
#include <stdlib.h>
#include <time.h>

#include "BinarySearchTree.h"
#include "AVLTree.h"

const int MIN = 0;
const int LENGTH =7500;
const int MAX = MIN + LENGTH - 1;
using namespace std;

int *arrayIncreasing;
int *arrayDisorder;
void initial()
{
	arrayIncreasing = new int[LENGTH];
	arrayDisorder = new int[LENGTH];
	for (int i = 0;i < LENGTH;i++)
	{
		arrayIncreasing[i] = i;
		arrayDisorder[i] = i;
	}

	srand((unsigned)time(NULL));
	int temp = 0;
	int tempIndex = 0;
	for (int i = 0;i < LENGTH;i++)
	{
		temp = arrayDisorder[i];
		tempIndex = MIN + rand() % (MAX + MIN - 1);
		arrayDisorder[i] = arrayDisorder[tempIndex];
		arrayDisorder[tempIndex] = temp;
	}

	cout << "Array Length: " << LENGTH << endl;
}

void timeIncrease()
{
	// ------------------------------------------- //
	// ----------------increasing----------------- //
	// ------------------------------------------- //
	AVLTree treeAVL;
	BinarySearchTree treeBST;
	// -------------------------- AVL -----------------------------//
	// insert
	clock_t insertStartAVL, insertEndAVL;
	insertStartAVL = clock();
	for (int i = 0;i < LENGTH;i++)
		treeAVL.Insert(arrayIncreasing[i]);
	insertEndAVL = clock();
	double insertDurAVL = (double)(insertEndAVL - insertStartAVL);

	// access
	clock_t accessStartAVL, accessEndAVL;
	accessStartAVL = clock();
	for (int i = 0;i < LENGTH;i++)
		treeAVL.Access(arrayIncreasing[i]);
	accessEndAVL = clock();
	double accessDurAVL = (double)(accessEndAVL - accessStartAVL);

	// delete
	clock_t deleteStartAVL, deleteEndAVL;
	deleteStartAVL = clock();
	for (int i = 0;i < LENGTH;i++)
		treeAVL.Delete(arrayIncreasing[i]);
	deleteEndAVL = clock();
	double deleteDurAVL = (double)(deleteEndAVL - deleteStartAVL);


	// -------------------------- BST -----------------------------//
	// insert
	clock_t insertStartBST, insertEndBST;
	insertStartBST = clock();
	for (int i = 0;i < LENGTH;i++)
		treeBST.Insert(arrayIncreasing[i]);
	insertEndBST = clock();
	double insertDurBST = (double)(insertEndBST - insertStartBST);

	// access
	clock_t accessStartBST, accessEndBST;
	accessStartBST = clock();
	for (int i = 0;i < LENGTH;i++)
		treeBST.Access(arrayIncreasing[i]);
	accessEndBST = clock();
	double accessDurBST = (double)(accessEndBST - accessStartBST);

	// delete
	clock_t deleteStartBST, deleteEndBST;
	deleteStartBST = clock();
	for (int i = 0;i < LENGTH;i++)
		treeBST.Delete(arrayIncreasing[i]);
	deleteEndBST = clock();
	double deleteDurBST = (double)(deleteEndBST - deleteStartBST);

	cout << "Increasing Order:" << endl;
	cout << "AVL Tree:" << endl;
	cout << insertDurAVL / CLOCKS_PER_SEC << endl;
	cout << accessDurAVL / CLOCKS_PER_SEC << endl;
	cout << deleteDurAVL / CLOCKS_PER_SEC << endl;

	cout << endl;
	cout << "Binary Search Tree:" << endl;
	cout << insertDurBST / CLOCKS_PER_SEC << endl;
	cout << accessDurBST / CLOCKS_PER_SEC << endl;
	cout << deleteDurBST / CLOCKS_PER_SEC << endl;
	cout << endl;
}
void timeReverse()
{
	// ------------------------------------------- //
	// -----------------reverse------------------- //
	// ------------------------------------------- //
	AVLTree treeAVL;
	BinarySearchTree treeBST;
	// -------------------------- AVL -----------------------------//
	// insert
	clock_t insertStartAVL, insertEndAVL;
	insertStartAVL = clock();
	for (int i = 0;i < LENGTH;i++)
		treeAVL.Insert(arrayIncreasing[i]);
	insertEndAVL = clock();
	double insertDurAVL = (double)(insertEndAVL - insertStartAVL);

	// access
	clock_t accessStartAVL, accessEndAVL;
	accessStartAVL = clock();
	for (int i = 0;i < LENGTH;i++)
		treeAVL.Access(arrayIncreasing[LENGTH - i - 1]);
	accessEndAVL = clock();
	double accessDurAVL = (double)(accessEndAVL - accessStartAVL);

	// delete
	clock_t deleteStartAVL, deleteEndAVL;
	deleteStartAVL = clock();
	for (int i = 0;i < LENGTH;i++)
		treeAVL.Delete(arrayIncreasing[LENGTH - i - 1]);
	deleteEndAVL = clock();
	double deleteDurAVL = (double)(deleteEndAVL - deleteStartAVL);


	// -------------------------- BST -----------------------------//
	// insert
	clock_t insertStartBST, insertEndBST;
	insertStartBST = clock();
	for (int i = 0;i < LENGTH;i++)
		treeBST.Insert(arrayIncreasing[i]);
	insertEndBST = clock();
	double insertDurBST = (double)(insertEndBST - insertStartBST);

	// access
	clock_t accessStartBST, accessEndBST;
	accessStartBST = clock();
	for (int i = 0;i < LENGTH;i++)
		treeBST.Access(arrayIncreasing[LENGTH - i - 1]);
	accessEndBST = clock();
	double accessDurBST = (double)(accessEndBST - accessStartBST);

	// delete
	clock_t deleteStartBST, deleteEndBST;
	deleteStartBST = clock();
	for (int i = 0;i < LENGTH;i++)
		treeBST.Delete(arrayIncreasing[LENGTH - i - 1]);
	deleteEndBST = clock();
	double deleteDurBST = (double)(deleteEndBST - deleteStartBST);

	cout << "Reverse Order:" << endl;
	cout << "AVL Tree:" << endl;
	cout << insertDurAVL / CLOCKS_PER_SEC << endl;
	cout << accessDurAVL / CLOCKS_PER_SEC << endl;
	cout << deleteDurAVL / CLOCKS_PER_SEC << endl;

	cout << endl;
	cout << "Binary Search Tree:" << endl;
	cout << insertDurBST / CLOCKS_PER_SEC << endl;
	cout << accessDurBST / CLOCKS_PER_SEC << endl;
	cout << deleteDurBST / CLOCKS_PER_SEC << endl;
	cout << endl;
}
void timeDisorder()
{
	// ------------------------------------------- //
	// -----------------disorder------------------ //
	// ------------------------------------------- //
	AVLTree treeAVL;
	BinarySearchTree treeBST;
	// -------------------------- AVL -----------------------------//
	// insert
	clock_t insertStartAVL, insertEndAVL;
	insertStartAVL = clock();
	for (int i = 0;i < LENGTH;i++)
		treeAVL.Insert(arrayDisorder[i]);
	insertEndAVL = clock();
	double insertDurAVL = (double)(insertEndAVL - insertStartAVL);

	// access
	clock_t accessStartAVL, accessEndAVL;
	accessStartAVL = clock();
	for (int i = 0;i < LENGTH;i++)
		treeAVL.Access(arrayDisorder[i]);
	accessEndAVL = clock();
	double accessDurAVL = (double)(accessEndAVL - accessStartAVL);

	// delete
	clock_t deleteStartAVL, deleteEndAVL;
	deleteStartAVL = clock();
	for (int i = 0;i < LENGTH;i++)
		treeAVL.Delete(arrayDisorder[i]);
	deleteEndAVL = clock();
	double deleteDurAVL = (double)(deleteEndAVL - deleteStartAVL);


	// -------------------------- BST -----------------------------//
	// insert
	clock_t insertStartBST, insertEndBST;
	insertStartBST = clock();
	for (int i = 0;i < LENGTH;i++)
		treeBST.Insert(arrayDisorder[i]);
	insertEndBST = clock();
	double insertDurBST = (double)(insertEndBST - insertStartBST);

	// access
	clock_t accessStartBST, accessEndBST;
	accessStartBST = clock();
	for (int i = 0;i < LENGTH;i++)
		treeBST.Access(arrayDisorder[i]);
	accessEndBST = clock();
	double accessDurBST = (double)(accessEndBST - accessStartBST);

	// delete
	clock_t deleteStartBST, deleteEndBST;
	deleteStartBST = clock();
	for (int i = 0;i < LENGTH;i++)
		treeBST.Delete(arrayDisorder[i]);
	deleteEndBST = clock();
	double deleteDurBST = (double)(deleteEndBST - deleteStartBST);

	cout << "Disorder:" << endl;
	cout << "AVL Tree:" << endl;
	cout << insertDurAVL / CLOCKS_PER_SEC << endl;
	cout << accessDurAVL / CLOCKS_PER_SEC << endl;
	cout << deleteDurAVL / CLOCKS_PER_SEC << endl;

	cout << endl;
	cout << "Binary Search Tree:" << endl;
	cout << insertDurBST / CLOCKS_PER_SEC << endl;
	cout << accessDurBST / CLOCKS_PER_SEC << endl;
	cout << deleteDurBST / CLOCKS_PER_SEC << endl;
	cout << endl;
}
int main()
{
	initial();
	timeIncrease();
	timeReverse();
	timeDisorder();
	return 0;
}
#endif // myProgAVLTree
