#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"binaryTree.h"

int main(void)
{
	tree_t* testTree = makeSampleTree();

	copyTreeTest(testTree);
	EqaulityTest(testTree);

	return 0;
}
