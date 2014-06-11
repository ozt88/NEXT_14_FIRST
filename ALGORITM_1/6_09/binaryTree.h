#ifndef __TREE_H__
#define __TREE_H__

#define NODE_NUM 9

typedef struct node
{
	char data;
	struct node* parent;
	struct node* leftChild;
	struct node* rightChild;
}node_t;

typedef struct tree
{
	node_t* root;
}tree_t;

typedef struct queNode
{
	struct queNode* next;
	node_t* node;
}queNode_t;

typedef struct queue
{
	queNode_t* head;
	queNode_t* tail;
}queue_t;

node_t* makeNode(void); //트리용 노드를 만드는 함수
tree_t* makeTree(void); //트리를 만드는 함수
tree_t* makeSampleTree(void); //샘플 트리를 만드는 함수

int testTreeWithInorder(tree_t* tree); //트리를 inorder로 출력하는 함수
int inorderPrint(node_t* node); //트리를 inorder출력하는데 사용되는 재귀 함수

int copyTreeTest(tree_t* srcTree); //복사 테스트 출력함수
tree_t* copyBinaryTree(tree_t* srcTree); //트리를 복사하는 함수
node_t* copyBinaryTreeWithNode(node_t* srcNode, node_t* parent); //트리 복사하는 함수에 사용되는 재귀함수

int EqaulityTest(tree_t* srcTree); //동일성 테스트 출력함수
int testingTreeEquality(tree_t* tree1, tree_t* tree2); //동일성 확인하는 함수
int testingTreeEqualityWithNode(node_t* node1, node_t* node2); //동일성 확인하는데 사용되는 재귀함수


#endif