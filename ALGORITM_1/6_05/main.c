#include<stdio.h>
#include"tree.h"

int main(void)
{
	tree_t* testTree = makeSampleTree();

	testSampleTree(testTree);  
	testTreeWithInorder(testTree); 
	testTreeWithPreorder(testTree);
	testTreeWithPostorder(testTree);
	testTreeWithLevelorder(testTree);

	return 0;
}
