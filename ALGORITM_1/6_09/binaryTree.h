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

node_t* makeNode(void); //Ʈ���� ��带 ����� �Լ�
tree_t* makeTree(void); //Ʈ���� ����� �Լ�
tree_t* makeSampleTree(void); //���� Ʈ���� ����� �Լ�

int testTreeWithInorder(tree_t* tree); //Ʈ���� inorder�� ����ϴ� �Լ�
int inorderPrint(node_t* node); //Ʈ���� inorder����ϴµ� ���Ǵ� ��� �Լ�

int copyTreeTest(tree_t* srcTree); //���� �׽�Ʈ ����Լ�
tree_t* copyBinaryTree(tree_t* srcTree); //Ʈ���� �����ϴ� �Լ�
node_t* copyBinaryTreeWithNode(node_t* srcNode, node_t* parent); //Ʈ�� �����ϴ� �Լ��� ���Ǵ� ����Լ�

int EqaulityTest(tree_t* srcTree); //���ϼ� �׽�Ʈ ����Լ�
int testingTreeEquality(tree_t* tree1, tree_t* tree2); //���ϼ� Ȯ���ϴ� �Լ�
int testingTreeEqualityWithNode(node_t* node1, node_t* node2); //���ϼ� Ȯ���ϴµ� ���Ǵ� ����Լ�


#endif