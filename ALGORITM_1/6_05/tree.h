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

node_t* makeNode(void); //Ʈ���� ��带 ����� �Լ�
tree_t* makeTree(void); //Ʈ���� ����� �Լ�

tree_t* makeSampleTree(void); //���� Ʈ���� ����� �Լ�

int testSampleTree(tree_t* testTree); //���� Ʈ���� �׽�Ʈ ����ϴ��Լ�
int printNode(node_t* node); //���� Ʈ�� ����ϴµ� ���Ǵ� ��� �Լ�

int testTreeWithInorder(tree_t* tree); //Ʈ���� inorder�� ����ϴ� �Լ�
int inorderPrint(node_t* node); //Ʈ���� inorder����ϴµ� ���Ǵ� ��� �Լ�

int testTreeWithPostorder(tree_t* tree); //Ʈ���� postorder�� ����ϴ� �Լ�
int postorderPrint(node_t* node); //Ʈ���� postorder����ϴµ� ���Ǵ� ��� �Լ�

int testTreeWithPreorder(tree_t* tree); //Ʈ���� preorder�� ����ϴ� �Լ� 
int preorderPrint(node_t* node); //Ʈ���� preorder�� ����ϴµ� ���Ǵ� ��� �Լ�

queue_t* makeQueue(void); //���� ������ ����ϴµ� �ʿ��� ť�� �����ϴ� �Լ�
int enQueue(queue_t* queue, node_t* newNode); //���� �� ��¿� ���Ǵ� ��ť�Լ�
node_t* deQueue(queue_t* queue); //���� �� ��¿� ���Ǵ� ��ť�Լ�
int testTreeWithLevelorder(tree_t* tree); //Ʈ���� ���������� ����ϴ� �Լ�

#endif