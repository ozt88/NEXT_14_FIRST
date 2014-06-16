#ifndef __BST_H__
#define __BST_H__

#define NODE_NUM 9
#define TEST_NUM 20
#define BIG_NUM 100000

typedef struct node
{
	int data;
	struct node* parent;
	struct node* leftChild;
	struct node* rightChild;
}node_t;

typedef struct tree
{
	node_t* root;
}tree_t;

typedef struct stackNode
{
	node_t* data;
	struct stackNode* next;
}stackNode_t;

typedef struct stack
{
	stackNode_t* top;
}stack_t;


tree_t* makeBigBST(void);
tree_t* makeSampleBST(void);
tree_t* makeTree(void);
node_t* makeNode(void);

int testBSTWithInorder(tree_t* tree);
int testBSTWithPreorder(tree_t* tree);
void testBSTWithInorderWithNode(node_t* node);
void testBSTWithPreorderWithNode(node_t* node);

void testBSTWithPostorderWithNode(node_t* node);

int testBSTlikeNo3(node_t* resultNode);

node_t* searchBSTbyKey(tree_t* BST, int key);
node_t* searchBSTbyKeyWithNode(node_t* currentNode, int key);
int testSearchBSTbyKey(tree_t* BST, int key);

node_t* findMinInBST(tree_t* BST);
node_t* findMinInBSTWithNode(node_t* currentNode);

int testFindMaxInBST(tree_t* BST);
node_t* findMaxInBST(tree_t* BST);
node_t* findMaxInBSTWithNode(node_t* currentNode);

int testSuccessor(node_t* node);
node_t* bstSuccessorOf(node_t* node);

int testInsertNode(tree_t* tree);
int bstInsertNode(tree_t* tree, node_t* givenNode);
int testInsertNodeWithRecursive(int* testData);
int bstInsertNodeWithRecursive(tree_t* tree, node_t* currentNode, node_t* parentNode, node_t* givenNode);

int transplantInBST(tree_t* tree, node_t* deNode, node_t* newNode);
int deleteInBST(tree_t* tree, node_t* delNode);

int testCountLeafNode(tree_t* tree);
int countLeafNode(node_t* node);
int checkBST(node_t* node, int max, int min);

int testSwapTree(tree_t* tree);
int swapTreeWithNode(node_t* node);



stack_t* makeStack(void);
stackNode_t* makeStackNode(void);
int stackPush(stack_t* stack, node_t* node);
node_t* stackPop(stack_t* stack);

int inorderPrintWithStack(tree_t* tree);
int preorderPrintWithStack(tree_t* tree);

#endif