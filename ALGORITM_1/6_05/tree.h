#ifndef __TREE_H__
#define __TREE_H__

#define NODE_NUM 9

typedef struct node
{
	char value;
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

int testSampleTree(tree_t* testTree); //샘플 트리를 테스트 출력하는함수
int printNode(node_t* node); //샘플 트리 출력하는데 사용되는 재귀 함수

int testTreeWithInorder(tree_t* tree); //트리를 inorder로 출력하는 함수
int inorderPrint(node_t* node); //트리를 inorder출력하는데 사용되는 재귀 함수

int testTreeWithPostorder(tree_t* tree); //트리를 postorder로 출력하는 함수
int postorderPrint(node_t* node); //트리를 postorder출력하는데 사용되는 재귀 함수

int testTreeWithPreorder(tree_t* tree); //트리를 preorder로 출력하는 함수 
int preorderPrint(node_t* node); //트리를 preorder로 출력하는데 사용되는 재귀 함수

queue_t* makeQueue(void); //레벨 순으로 출력하는데 필요한 큐를 생성하는 함수
int enQueue(queue_t* queue, node_t* newNode); //레벨 순 출력에 사용되는 인큐함수
node_t* deQueue(queue_t* queue); //레벨 순 출력에 사용되는 디큐함수
int testTreeWithLevelorder(tree_t* tree); //트리를 레벨순으로 출력하는 함수

#endif