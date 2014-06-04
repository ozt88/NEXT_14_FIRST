
//Doubly Linked List���� XOR�� ����ϴ� �ֵ� ������
//�ϳ��� �������� ����ؼ� ����� ���� ����Ʈ�� ����� ���̴�.
//
//����� ���� ����Ʈ�� ���� Ȥ�� ���� ����Ʈ�� �����̱� ���ؼ���
//�� ���� �ּ� �� prev, next�� �ʿ��ϴ�.
//
//�׷��� �� �ּ� ���� ��� �ϳ��� ������ �ٸ� ���� ���� �� �ִٸ�,
//�츮�� ��� ������ �ּҸ� �� �� �ִ�.
//
//*�ͳ��� ����
//
	//�⺻ ����)
	//����Ʈ�� �־��� head���� �츮�� prev ���� NULL�̶�� ���� �˰� �ִ�.
	//prev ���� ������ next ���� ���� �� �ִٸ�
	//�츮�� �� ���� ����� �ּ� ���� �� �� �ִ�.
	//
	//�ͳ� ����)
	//�츮�� ������ ��忡�� �� ���� ����� �ּ� ���� �� �� �ִٰ� ��������.
	//
	//�ͳ� ����)
	//�� ���� ��忡�� �츮�� prev ����� �ּҸ� �˰� �����Ƿ�
	//�ٸ� ��(next)�� ���ϴ� ����� �ȴٸ�, �츮�� �� ���� ��带 �� �� �ִ�.
	//
	//���� �ͳ��� ������ ���� �츮�� prev�� next ���� �ϳ��� �ּҷ� ������ ����
	//���ϴ� ����� �˰� �ִٸ�, �츮�� ��� ����� �ּҸ� �� �� �ִ�.
//
//*without loss of generosity
	//�־��� tail���� next�� NULL�̶�� ���� �˱� ������
	//�������� ��� ����� �ּҰ��� Ȯ�� �� �� �ִ�.
//
//
//�׷��ٸ� �� ������ ���� Ȥ�� ������ �ּҰ��� ���� ������ �ִ� ���
//�� �� �ϳ��� �־����� ������ �ϳ��� ���� �� �ִ� ����� ������ ������ ����ϴ�.
//
	//å���� �־��� ����� XOR�� �Ʒ��� ���� Ư���� ����Ѵ�.
	//
	//i)  XOR(A, (XOR(A, B)) = B
	//ii) XOR(XOR(A, B), A) = B
//
//
//��� ������ prev�� next�� �ּҰ� ��ſ�
//prev�� �ּҰ��� next�� �ּҰ��� XOR�� ����� ������ �ִٸ�,
//�� �� �ϳ��� �־����� �� ���� ������ �ִ� ��� ���� XOR ���� ������,
//�� XORƯ¡ i)�� ii)�� ���ؼ� ������ ���� ���´�.
//
//���� ����Ʈ�� ��� Ȥ�� ������ �־����ְ�,
//�� ������ prev�� next�� �ּҰ��� XOR�� ���� ������ ������
//�� �Ѱ��� ������ ������ ��� ������ �ּҸ� �ľ� �� �� �ִ�.



#include<stdio.h>

//XOR ������ ���� (�ּҸ� ������ ��ȯ�� ���� XOR�Ѵ�.)
#define XOR(a,b) ((unsigned int)(a)^(unsigned int)(b))

typedef struct node
{
	int data;
	struct node* link;
}node_t;

typedef struct list
{
	node_t* head;
	node_t* tail;
}list_t;

//���ʿ��� ���������� üũ�ϸ鼭 ����ϴ� �Լ�
	//���� ���� �Ѿ�µ� XOR�� ����Ѵ�.
	//�� ����� ������ ������ �� ������ ��� ������ �����ؾ��Ѵ�.
	//��� ����
		//i)prevNode�� NULL�� ��� (��, ���) 
			//���� currentNode�� ������ �ִ� XOR ���� 
			//XOR(NULL,nextNode)�̴�.
			//���� XOR(NULL,XOR(NULL,nextNode))�� nextNode�� �ǹǷ�
			//�� ���Ŀ��� ���ܰ� ���� �ʴ´�.

		//ii)�������� �Ѿ ��尡 NULL�� ��� (��, ����)
			//��忡������ ���Ϸ� üũ�ϸ� ����ϴ� �Լ��̹Ƿ�,
			//���ϱ��� �Դٸ� �����ؾ��Ѵ�.
			//���� �� ������ ���������̴�.
			//tail�� ������ �ִ� XOR ���� XOR(prevNode,NULL)
			//XOR(XOR(prevNode,NULL),NULL)) = NULL�̴�.
			//���� ���ο� currentNode�� NULL�� �ɶ� �����ϸ� �ȴ�.

int print_left(list_t* list)
{
	node_t* currentNode; //���� ����� �ּҸ� ��Ÿ���� ����
	node_t* prevNode;	//���� ����� �ּҸ� �����ϴ� ����
	node_t* tempNode;	//�������� ����� �ӽ÷� ��� �ּҸ� �����ϴ� ����

	if (!list)
	{
		return -1;
	}

	currentNode = list->head; //�켱 ���� ���� ��忡������ �����Ѵ�.
	prevNode = NULL; //�翬�� ���� ����� �ּҴ� ���̴�.

	while (currentNode)
	{
		printf("%d\n", currentNode->data); //�켱 ���� ����� ���� ����ϰ�
		tempNode = currentNode; //���� �ּҸ� �ӽ÷� �����Ѵ�.
		currentNode = XOR(currentNode->link, prevNode); //XOR�� ���� ���� ���� �Ѿ��
		prevNode = tempNode; //�Ʊ� ������ �ӽ� ����Ҹ� ������ ���� ����� �ּҸ� �����Ѵ�.
	}
	printf("\n");

	return 0;
}

//�����ʿ��� �������� üũ�ϸ鼭 ����ϴ� �Լ���
//�ռ� ����� �Ϲݼ��� ���� �ʰ� ���� ������� �����ϴ� ��쿡 �ش��Ѵ�.
//prev�� next�� �˾Ƴ��� ���� ����� ������ ���·�
//next�� ������ prev�� �˾Ƴ��� ����� ����Ѵ�.
//����Ʈ���� �̹� next�� NULL�� Ȯ���� tail�� �־����� ������
//�װ����κ��� �ϳ��� ������ �����ϴ� ���� �����ϴ�.

//�ڵ忡���� prevNode ��� nextNode ������ ����ϴ� ��.
//list->head ��� list->tail�� ����ϴ� �� ����� ��� ���� ������� ���������ϴ�.

//��������� �ٽ� ���캸��
	//i)current �� tail�� ���
		//tail�� ������ �ִ� link�� ���� XOR(prevNode,NULL)�̹Ƿ�
		//NULL�� XOR(nextNode, XOR(prevNode,Null)  = prevNode�� �ȴ�.
		//���� ���ܰ� ���� �ʴ´�.
	//ii)current�� head�� ���
		//�����ʿ��� ���������� Ž���� ���� ����̹Ƿ� �̰��� ������������ �Ѵ�.
		//current->link �� ���� XOR(NULL,nextNode)�̹Ƿ�
		//XOR(XOR(NULL,nextNode),nextNode) = NULL�̴�.
		//�ᱹ ���ο� currentNode�� NULL�� ��� �������ָ� �ȴ�.
//���ʿ��� ���������� ����ϴ� �Ͱ� ������ �������� ���� �����ϴ�.

int print_right(list_t* list)
{
	node_t* currentNode;
	node_t* nextNode;
	node_t* tempNode;

	if (!list)
	{
		return -1;
	}
	currentNode = list->tail;
	nextNode = NULL;

	while (currentNode)
	{
		printf("%d\n", currentNode->data);
		tempNode = currentNode;
		currentNode = XOR(currentNode->link, nextNode);
		nextNode = tempNode;
	}
	printf("\n");

	return 0;

}