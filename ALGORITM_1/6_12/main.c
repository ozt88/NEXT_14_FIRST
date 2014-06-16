#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

int main(void)
{
	tree_t* testBST = makeSampleBST();
	//리프노드 갯수 새려고 만든 큰 BST
	tree_t* bigBST = makeBigBST();

	//테스트용 데이터
	int testData1[TEST_NUM] = { 1, 2, 3, 4, 5, 6 };
	int testData2[TEST_NUM] = { 6, 5, 4, 3, 2, 1 };
	int testData3[TEST_NUM] = { 8, 4, 2, 1, 3, 6, 5, 7, 12, 10, 9, 11, 13, 14, 15 };
	int testData4[TEST_NUM] = { 2, 5, 9, 12, 15, 17, 18, 19 };
	int testData5[TEST_NUM] = { 2, 5, 12, 15, 17, 18, 19 };

	//샘플 출력 함수들 테스트(inorder/preorder/postorder 각각 reculsive, iterative로 한번씩)
	printf("\nSAMPLE BST with Inorder\n");
	testBSTWithInorder(testBST);
	printf("\nSAMPLE BST with Inorder Iterative\n");
	inorderPrintWithStack(testBST);
	printf("\nSAMPLE BST with Preorder\n");
	testBSTWithPreorder(testBST);
	printf("\nSAMPLE BST with Preorder Iterative\n");
	preorderPrintWithStack(testBST);
	printf("\nSAMPLE BST with Postorder\n");
	testBSTWithPostorder(testBST);
	printf("\nSAMPLE BST with Postorder Iterative\n");
	postorderPrintWithStack(testBST);

	//키값으로 노드를 검색하는 함수 테스트
	printf("\nSEARCH TEST\n");
	testSearchBSTbyKey(testBST, 12);
	testSearchBSTbyKey(testBST, 2);
	testSearchBSTbyKey(testBST, 7);

	//최소값을 찾는 함수 테스트
	printf("\nFIND MINIMUM TEST\n");
	testFindMinInBST(testBST);

	//최대값을 찾는 함수 테스트
	printf("\nFIND MAXIMUM TEST\n");
	testFindMaxInBST(testBST);

	//successor찾는 함수 테스트
	printf("\nFIND SUCCESSOR TEST\n");
	testSuccessor(searchBSTbyKey(testBST, 2));
	testSuccessor(searchBSTbyKey(testBST, 9));
	testSuccessor(searchBSTbyKey(testBST, 12));
	testSuccessor(searchBSTbyKey(testBST, 15));
	testSuccessor(searchBSTbyKey(testBST, 19));

	//삽입기능 테스트
	printf("\nINSERT TEST\n");
	testInsertNode(testData1);
	testInsertNode(testData2);
	testInsertNode(testData3);

	//이식 기능 테스트
	printf("\nTRANSPLANT TEST\n");
	testTransplantNode(testData4, 15, 17);
	testTransplantNode(testData5, 2, 5);

	//삭제 기능 테스트
	printf("\nDELETE TEST\n");
	testDeleteInBST(testBST, 13);
	testDeleteInBST(testBST, 17);
	testDeleteInBST(testBST, 12);

	//리프노드의 갯수를 새는 함수 테스트
	printf("\nTEST COUNT LEAF NODE\n");
	testCountLeafNode(bigBST);

	//리커시브로 삽입하는 함수 테스트
	printf("\nRECURSIVE INSERT TEST\n");
	testInsertNodeWithRecursive(testData1);
	testInsertNodeWithRecursive(testData2);
	testInsertNodeWithRecursive(testData3);

	//모든 노드의 왼쪽 자식과 오른쪽 자식을 교환하는 함수 테스트 
	printf("\nTEST SWAP TREE\n");
	testSwapTree(testBST);

	//BST인지 체크하는 함수 테스트
	printf("\nCHECK BST TEST\n");
	testCheckBST(testBST);




	clearTreeWithNode(testBST->root);
	clearTreeWithNode(bigBST->root);



	return 0;
}