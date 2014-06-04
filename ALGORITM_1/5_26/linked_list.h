#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct node{
	int value;
	struct node* next;
}node_t;

typedef struct list{
	struct node* head;
}list_t;

void printAllNodes(list_t * list);
void insertNode(list_t* listPtr, node_t* prevNodePtr, node_t* newNodePtr);
node_t* searchNode(list_t *list, int key);
void deleteNode(list_t *list, node_t *prevN, node_t *targetN);
node_t* findPrevNode(list_t* list, node_t* currentNode);
node_t* findCycleHead(list_t* list, node_t* one, node_t* two);
node_t* cycleFinder(list_t* list);
void practice2(list_t list);
void practice34(list_t* list, node_t* node1, node_t* node2, node_t* node3, node_t* node4, node_t* node5, node_t* node6);
void practice5(list_t list);
void practice67(list_t list);
void practice89(list_t list);

#endif