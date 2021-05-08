#include "RedBlackTree.hpp"
#include "UnsortedLinkedList.hpp"
#include "Node.hpp"
#include "Item.hpp"
#include <chrono>

#define HUNDRED_ELEMENTS 100
#define THOUSAND_ELEMENTS 1000
#define TEN_THOUSAND_ELEMENTS 10000
#define HUNDRED_THOUSAND_ELEMENTS 100000
#define MILLION_ELEMENTS 1000000

using namespace std;

void printRBT();
void insert100RandomNumbers(RedBlackTree<int>& redBlackTree, UnsortedLinkedList<int>& unsortedLinkedList);
void insert1000RandomNumbers(RedBlackTree<int>& redBlackTree, UnsortedLinkedList<int>& unsortedLinkedList);
void insert10000RandomNumbers(RedBlackTree<int>& redBlackTree, UnsortedLinkedList<int>& unsortedLinkedList);
void insert100000RandomNumbers(RedBlackTree<int>& redBlackTree, UnsortedLinkedList<int>& unsortedLinkedList);
void insert1000000RandomNumbers(RedBlackTree<int>& redBlackTree, UnsortedLinkedList<int>& unsortedLinkedList);
void timeForLookUp();
bool blackHeight(Node<int>*& node);
int countLeftBlackNodes(Node<int>* node);
int countRightBlackNodes(Node<int>* node);

int main()
{
	printRBT();
	timeForLookUp();

	cout << "------------------------------------------------------------------------" << endl;

	cout << "Check for Black Violation in Red Black Tree containing a 1000 Elements" << endl;

	cout << "------------------------------------------------------------------------" << endl << endl;

	RedBlackTree<int> redBlackTree;
	UnsortedLinkedList<int> unsortedLinkedList;

	insert1000RandomNumbers(redBlackTree, unsortedLinkedList);

	Node<int>* root = redBlackTree.getRoot();

	if (blackHeight(root))
		cout << "No Black Violation" << endl << endl;
	else
		cout << "Black Violation" << endl << endl;
}

void printRBT()
{
	RedBlackTree<int> redBlackTree;

	int value1 = 101;
	int value2 = 21;
	int value3 = 13;
	int value4 = 402;
	int value5 = 15;
	int value6 = 6;
	int value7 = 7;
	int value8 = 18;
	int value9 = 91;
	int value10 = 0;
	int value11 = 12;
	int value12 = 31;
	int value13 = 131;
	int value14 = 114;
	int value15 = 170;
	int value16 = 2;
	int value17 = 3;
	int value18 = 4;

	redBlackTree.Insert(value1);
	redBlackTree.Insert(value2);
	redBlackTree.Insert(value3);
	redBlackTree.Insert(value4);
	redBlackTree.Insert(value5);
	redBlackTree.Insert(value6);
	redBlackTree.Insert(value7);
	redBlackTree.Insert(value8);
	redBlackTree.Insert(value9);
	redBlackTree.Insert(value10);
	redBlackTree.Insert(value11);
	redBlackTree.Insert(value12);
	redBlackTree.Insert(value13);
	redBlackTree.Insert(value14);
	redBlackTree.Insert(value15);
	redBlackTree.Insert(value16);
	redBlackTree.Insert(value17);
	redBlackTree.Insert(value18);

	cout << "-----------------------------------------" << endl;

	cout << "Inorder Traversal of Red Black Tree" << endl;

	cout << "-----------------------------------------" << endl << endl;


	redBlackTree.printDataInorderTraversal();
	cout << endl << endl;

	redBlackTree.printRoot();

	Node<int>* root = redBlackTree.getRoot();

	if (blackHeight(root))
		cout << "No Black Violation" << endl << endl;
	else
		cout << "Black Violation" << endl << endl;

	cout << "---------------------------------------" << endl;

	Node<int>* test1 = redBlackTree.findNode(value1);
	redBlackTree.printFoundData(test1);
	redBlackTree.printFoundData(test1->left);
	redBlackTree.printFoundData(test1->right);

	cout << "---------------------------------------" << endl;


	Node<int>* test2 = redBlackTree.findNode(value2);
	redBlackTree.printFoundData(test2);
	redBlackTree.printFoundData(test2->left);
	redBlackTree.printFoundData(test2->right);

	cout << "---------------------------------------" << endl;


	Node<int>* test3 = redBlackTree.findNode(value3);
	redBlackTree.printFoundData(test3);
	redBlackTree.printFoundData(test3->left);
	redBlackTree.printFoundData(test3->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test4 = redBlackTree.findNode(value4);
	redBlackTree.printFoundData(test4);
	redBlackTree.printFoundData(test4->left);
	redBlackTree.printFoundData(test4->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test5 = redBlackTree.findNode(value5);
	redBlackTree.printFoundData(test5);
	redBlackTree.printFoundData(test5->left);
	redBlackTree.printFoundData(test5->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test6 = redBlackTree.findNode(value6);
	redBlackTree.printFoundData(test6);
	redBlackTree.printFoundData(test6->left);
	redBlackTree.printFoundData(test6->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test7 = redBlackTree.findNode(value7);
	redBlackTree.printFoundData(test7);
	redBlackTree.printFoundData(test7->left);
	redBlackTree.printFoundData(test7->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test8 = redBlackTree.findNode(value8);
	redBlackTree.printFoundData(test8);
	redBlackTree.printFoundData(test8->left);
	redBlackTree.printFoundData(test8->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test9 = redBlackTree.findNode(value9);
	redBlackTree.printFoundData(test9);
	redBlackTree.printFoundData(test9->left);
	redBlackTree.printFoundData(test9->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test10 = redBlackTree.findNode(value10);
	redBlackTree.printFoundData(test10);
	redBlackTree.printFoundData(test10->left);
	redBlackTree.printFoundData(test10->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test11 = redBlackTree.findNode(value11);
	redBlackTree.printFoundData(test11);
	redBlackTree.printFoundData(test11->left);
	redBlackTree.printFoundData(test11->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test12 = redBlackTree.findNode(value12);
	redBlackTree.printFoundData(test12);
	redBlackTree.printFoundData(test12->left);
	redBlackTree.printFoundData(test12->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test13 = redBlackTree.findNode(value13);
	redBlackTree.printFoundData(test13);
	redBlackTree.printFoundData(test13->left);
	redBlackTree.printFoundData(test13->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test14 = redBlackTree.findNode(value14);
	redBlackTree.printFoundData(test14);
	redBlackTree.printFoundData(test14->left);
	redBlackTree.printFoundData(test14->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test15 = redBlackTree.findNode(value15);
	redBlackTree.printFoundData(test15);
	redBlackTree.printFoundData(test15->left);
	redBlackTree.printFoundData(test15->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test16 = redBlackTree.findNode(value16);
	redBlackTree.printFoundData(test16);
	redBlackTree.printFoundData(test16->left);
	redBlackTree.printFoundData(test16->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test17 = redBlackTree.findNode(value17);
	redBlackTree.printFoundData(test17);
	redBlackTree.printFoundData(test17->left);
	redBlackTree.printFoundData(test17->right);

	cout << "---------------------------------------" << endl;

	Node<int>* test18 = redBlackTree.findNode(value18);
	redBlackTree.printFoundData(test18);
	redBlackTree.printFoundData(test18->left);
	redBlackTree.printFoundData(test18->right);

	cout << "-----------------------------------------" << endl;

	cout << "Find Nodes in Red Black Tree" << endl;

	cout << "-----------------------------------------" << endl << endl;


	redBlackTree.printFoundData(redBlackTree.findNode(value1));
	redBlackTree.printFoundData(redBlackTree.findNode(value2));
	redBlackTree.printFoundData(redBlackTree.findNode(value3));
	redBlackTree.printFoundData(redBlackTree.findNode(value4));
	redBlackTree.printFoundData(redBlackTree.findNode(value5));
	redBlackTree.printFoundData(redBlackTree.findNode(value6));
	redBlackTree.printFoundData(redBlackTree.findNode(value7));
	redBlackTree.printFoundData(redBlackTree.findNode(value8));
	redBlackTree.printFoundData(redBlackTree.findNode(0));
}

void insert100RandomNumbers(RedBlackTree<int>& redBlackTree, UnsortedLinkedList<int>& unsortedLinkedList)
{
	srand(time(NULL));
	
	int i = 0;
	while (i < HUNDRED_ELEMENTS)
	{
		int randomNumber = rand() % RAND_MAX;
		redBlackTree.Insert(randomNumber);
		unsortedLinkedList.PutItem(randomNumber);
		i++;
	}
	cout << i << " Elements inserted into Red Black Tree" << endl;
	cout << i << " Elements inserted into Unsorted Linked List" << endl << endl;
}

void insert1000RandomNumbers(RedBlackTree<int>& redBlackTree, UnsortedLinkedList<int>& unsortedLinkedList)
{
	srand(time(NULL));

	int i = 0;
	while (i < THOUSAND_ELEMENTS)
	{
		int randomNumber = rand() % RAND_MAX;
		redBlackTree.Insert(randomNumber);
		unsortedLinkedList.PutItem(randomNumber);
		i++;
	}

	cout << i << " Elements inserted into Red Black Tree" << endl;
	cout << i << " Elements inserted into Unsorted Linked List" << endl << endl;
}

void insert10000RandomNumbers(RedBlackTree<int>& redBlackTree, UnsortedLinkedList<int>& unsortedLinkedList)
{
	srand(time(NULL));

	int i = 0;
	while (i < TEN_THOUSAND_ELEMENTS)
	{
		int randomNumber = rand() % RAND_MAX;
		redBlackTree.Insert(randomNumber);
		unsortedLinkedList.PutItem(randomNumber);
		i++;
	}

	cout << i << " Elements inserted into Red Black Tree" << endl;
	cout << i << " Elements inserted into Unsorted Linked List" << endl << endl;
}

void insert100000RandomNumbers(RedBlackTree<int>& redBlackTree, UnsortedLinkedList<int>& unsortedLinkedList)
{
	srand(time(NULL));

	int i = 0;
	while (i < HUNDRED_THOUSAND_ELEMENTS)
	{
		int randomNumber = rand() % RAND_MAX;
		redBlackTree.Insert(randomNumber);
		unsortedLinkedList.PutItem(randomNumber);
		i++;
	}

	cout << i << " Elements inserted into Red Black Tree" << endl;
	cout << i << " Elements inserted into Unsorted Linked List" << endl << endl;
}

void insert1000000RandomNumbers(RedBlackTree<int>& redBlackTree, UnsortedLinkedList<int>& unsortedLinkedList)
{
	srand(time(NULL));

	int i = 0;
	while (i < MILLION_ELEMENTS)
	{
		int randomNumber = rand() % RAND_MAX;
		redBlackTree.Insert(randomNumber);
		unsortedLinkedList.PutItem(randomNumber);
		i++;
	}

	cout << i << " Elements inserted into Red Black Tree" << endl;
	cout << i << " Elements inserted into Unsorted Linked List" << endl << endl;
}

void timeForLookUp()
{
	cout << "-----------------------------------------------------------------" << endl;

	cout << "Inserting Elements in Red Black Tree and Unsorted Linked List" << endl;

	cout << "-----------------------------------------------------------------" << endl << endl;

	RedBlackTree<int> redBlackTree1;
	UnsortedLinkedList<int> unsortedLinkedList1;
	insert100RandomNumbers(redBlackTree1, unsortedLinkedList1);
	/*redBlackTree1.printDataInorderTraversal();

	cout << endl << endl;*/

	RedBlackTree<int> redBlackTree2;
	UnsortedLinkedList<int> unsortedLinkedList2;
	insert1000RandomNumbers(redBlackTree2, unsortedLinkedList2);
	/*redBlackTree2.printDataInorderTraversal();

	cout << endl << endl;*/

	RedBlackTree<int> redBlackTree3;
	UnsortedLinkedList<int> unsortedLinkedList3;
	insert10000RandomNumbers(redBlackTree3, unsortedLinkedList3);
	/*redBlackTree3.printDataInorderTraversal();

	cout << endl << endl;*/

	RedBlackTree<int> redBlackTree4;
	UnsortedLinkedList<int> unsortedLinkedList4;
	insert100000RandomNumbers(redBlackTree4, unsortedLinkedList4);
	/*redBlackTree4.printDataInorderTraversal();

	cout << endl << endl;*/

	RedBlackTree<int> redBlackTree5;
	UnsortedLinkedList<int> unsortedLinkedList5;
	insert1000000RandomNumbers(redBlackTree5, unsortedLinkedList5);
	/*redBlackTree5.printDataInorderTraversal();*/
	
	srand(time(NULL));

	int lookUpNumber = rand() % RAND_MAX;

	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double, std::milli> elaspedTime{};

	cout << "------------------------------------------------------------" << endl;

	cout << "Look Up Times for Red Black Tree and Unsorted Linked List" << endl;

	cout << "------------------------------------------------------------" << endl << endl;

	cout << "Red Black Tree" << endl << endl;

	start = std::chrono::system_clock::now();
	redBlackTree1.printFoundData(redBlackTree1.findNode(lookUpNumber));
	end = std::chrono::system_clock::now();

	elaspedTime = end - start;
	cout << "Red Black Tree: Elapsed Time for " << HUNDRED_ELEMENTS << " elements is " << elaspedTime.count() << " ms" << endl << endl;

	cout << "Unsorted Linked List" << endl << endl;

	start = std::chrono::system_clock::now();
	try
	{
		cout << "Item: " << unsortedLinkedList1.GetItem(lookUpNumber) << endl << endl;
	}
	catch (const char* msg)
	{
		cout << "Item " << msg << endl << endl;
	}
	end = std::chrono::system_clock::now();

	elaspedTime = end - start;
	cout << "Unsorted Linked List: Elapsed Time for " << HUNDRED_ELEMENTS << " elements is " << elaspedTime.count() << " ms" << endl;

	cout << "------------------------------------------------------------------------" << endl << endl;

	cout << "Red Black Tree" << endl << endl;

	start = std::chrono::system_clock::now();
	redBlackTree2.printFoundData(redBlackTree2.findNode(lookUpNumber));
	end = std::chrono::system_clock::now();

	elaspedTime = end - start;
	cout << "Red Black Tree: Elapsed Time for " << THOUSAND_ELEMENTS << " elements is " << elaspedTime.count() << " ms" << endl << endl;

	cout << "Unsorted Linked List" << endl << endl;

	start = std::chrono::system_clock::now();
	try
	{
		cout << "Item: " << unsortedLinkedList2.GetItem(lookUpNumber) << endl << endl;
	}
	catch (const char* msg)
	{
		cout << "Item " << msg << endl << endl;
	}
	end = std::chrono::system_clock::now();

	elaspedTime = end - start;
	cout << "Unsorted Linked List: Elapsed Time for " << THOUSAND_ELEMENTS << " elements is " << elaspedTime.count() << " ms" << endl;

	cout << "------------------------------------------------------------------------" << endl << endl;

	cout << "Red Black Tree" << endl << endl;

	start = std::chrono::system_clock::now();
	redBlackTree3.printFoundData(redBlackTree3.findNode(lookUpNumber));
	end = std::chrono::system_clock::now();

	elaspedTime = end - start;
	cout << "Red Black Tree: Elapsed Time for " << TEN_THOUSAND_ELEMENTS << " elements is " << elaspedTime.count() << " ms" << endl << endl;

	cout << "Unsorted Linked List" << endl << endl;

	start = std::chrono::system_clock::now();
	try
	{
		cout << "Item: " << unsortedLinkedList3.GetItem(lookUpNumber) << endl << endl;
	}
	catch(const char* msg)
	{
		cout << "Item " << msg << endl << endl;
	}
	end = std::chrono::system_clock::now();

	elaspedTime = end - start;
	cout << "Unsorted Linked List: Elapsed Time for " << TEN_THOUSAND_ELEMENTS << " elements is " << elaspedTime.count() << " ms" << endl;

	cout << "------------------------------------------------------------------------" << endl << endl;

	cout << "Red Black Tree" << endl << endl;

	start = std::chrono::system_clock::now();
	redBlackTree4.printFoundData(redBlackTree4.findNode(lookUpNumber));
	end = std::chrono::system_clock::now();

	elaspedTime = end - start;
	cout << "Red Black Tree: Elapsed Time for " << HUNDRED_THOUSAND_ELEMENTS << " elements is " << elaspedTime.count() << " ms" << endl << endl;

	cout << "Unsorted Linked List" << endl << endl;

	start = std::chrono::system_clock::now();
	try
	{
		cout << "Item: " << unsortedLinkedList4.GetItem(lookUpNumber) << endl << endl;
	}
	catch (const char* msg)
	{
		cout << "Item " << msg << endl << endl;
	}
	end = std::chrono::system_clock::now();

	elaspedTime = end - start;
	cout << "Unsorted Linked List: Elapsed Time for " << HUNDRED_THOUSAND_ELEMENTS << " elements is " << elaspedTime.count() << " ms" << endl;

	cout << "------------------------------------------------------------------------" << endl << endl;

	cout << "Red Black Tree" << endl << endl;

	start = std::chrono::system_clock::now();
	redBlackTree5.printFoundData(redBlackTree5.findNode(lookUpNumber));
	end = std::chrono::system_clock::now();

	elaspedTime = end - start;
	cout << "Red Black Tree: Elapsed Time for " << MILLION_ELEMENTS << " elements is " << elaspedTime.count() << " ms" << endl << endl;

	cout << "Unsorted Linked List" << endl << endl;

	start = std::chrono::system_clock::now();
	try
	{
		cout << "Item: " << unsortedLinkedList5.GetItem(lookUpNumber) << endl << endl;
	}
	catch (const char* msg)
	{
		cout << "Item " << msg << endl << endl;
	}
	end = std::chrono::system_clock::now();

	elaspedTime = end - start;
	cout << "Unsorted Linked List: Elapsed Time for " << MILLION_ELEMENTS << " elements is " << elaspedTime.count() << " ms" << endl;

	cout << "------------------------------------------------------------------------" << endl << endl;

}

bool blackHeight(Node<int>*& node)
{
	if (node == nullptr)
		return true;

	int countLeft = countLeftBlackNodes(node);
	int countRight = countRightBlackNodes(node);

	if (countLeft == countRight)
	{
		return (blackHeight(node->left) && blackHeight(node->right));
	}
	else
		return false;
}

int countLeftBlackNodes(Node<int>* node)
{
	if (node == nullptr)
		return 0;

	int numberOfLeftBlackNodes = countLeftBlackNodes(node->left);

	if (node->color == Color::BLACK)
		return numberOfLeftBlackNodes++;

	return numberOfLeftBlackNodes;
}

int countRightBlackNodes(Node<int>* node)
{
	if (node == nullptr)
		return 0;

	int numberOfRightBlackNodes = countLeftBlackNodes(node->right);

	if (node->color == Color::BLACK)
		return numberOfRightBlackNodes++;

	return numberOfRightBlackNodes;
}