
//Doubly Linked List에서 XOR을 사용하는 주된 목적은
//하나의 정보만을 사용해서 양방향 연결 리스트를 만드는 것이다.
//
//양방향 연결 리스트가 다음 혹은 이전 리스트로 움직이기 위해서는
//두 개의 주소 값 prev, next가 필요하다.
//
//그런데 두 주소 값중 어느 하나의 값으로 다른 값을 구할 수 있다면,
//우리는 모든 노드들의 주소를 알 수 있다.
//
//*귀납적 증명
//
	//기본 스텝)
	//리스트에 주어진 head에서 우리는 prev 값이 NULL이라는 것을 알고 있다.
	//prev 값을 가지고 next 값을 구할 수 있다면
	//우리는 그 다음 노드의 주소 값을 알 수 있다.
	//
	//귀납 가정)
	//우리가 임의의 노드에서 그 다음 노드의 주소 값을 알 수 있다고 가정하자.
	//
	//귀납 스텝)
	//그 다음 노드에서 우리는 prev 노드의 주소를 알고 있으므로
	//다른 값(next)을 구하는 방법을 안다면, 우리는 그 다음 노드를 알 수 있다.
	//
	//위의 귀납적 과정을 통해 우리가 prev나 next 둘중 하나의 주소로 나머지 값을
	//구하는 방법을 알고 있다면, 우리는 모든 노드의 주소를 알 수 있다.
//
//*without loss of generosity
	//주어진 tail에서 next가 NULL이라는 것을 알기 때문에
	//역순으로 모든 노드의 주소값을 확인 할 수 있다.
//
//
//그렇다면 각 노드들은 다음 혹은 이전의 주소값을 직접 가지고 있는 대신
//둘 중 하나만 주어저도 나머지 하나를 구할 수 있는 방법을 가지고 있으면 충분하다.
//
	//책에서 주어진 방법은 XOR의 아래와 같은 특성을 사용한다.
	//
	//i)  XOR(A, (XOR(A, B)) = B
	//ii) XOR(XOR(A, B), A) = B
//
//
//모든 노드들이 prev와 next의 주소값 대신에
//prev의 주소값과 next의 주소값의 XOR된 결과를 가지고 있다면,
//둘 중 하나가 주어져도 그 값을 가지고 있는 결과 값에 XOR 연산 했을때,
//위 XOR특징 i)과 ii)에 의해서 나머지 값이 나온다.
//
//따라서 리스트의 헤드 혹은 테일이 주어져있고,
//각 노드들이 prev와 next의 주소값을 XOR한 값을 가지고 있으면
//그 한가지 정보만 가지고 모든 노드들의 주소를 파악 할 수 있다.



#include<stdio.h>

//XOR 연산자 정의 (주소를 정수로 변환한 값을 XOR한다.)
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

//왼쪽에서 오른쪽으로 체크하면서 출력하는 함수
	//다음 노드로 넘어가는데 XOR을 사용한다.
	//이 방식은 위에서 설명한 바 있지만 경계 조건을 주의해야한다.
	//경계 조건
		//i)prevNode가 NULL인 경우 (즉, 헤드) 
			//현재 currentNode가 가지고 있는 XOR 값은 
			//XOR(NULL,nextNode)이다.
			//따라서 XOR(NULL,XOR(NULL,nextNode))는 nextNode가 되므로
			//위 공식에서 예외가 되지 않는다.

		//ii)다음으로 넘어갈 노드가 NULL인 경우 (즉, 테일)
			//헤드에서부터 테일로 체크하며 출력하는 함수이므로,
			//테일까지 왔다면 종료해야한다.
			//따라서 이 조건은 종료조건이다.
			//tail이 가지고 있는 XOR 값은 XOR(prevNode,NULL)
			//XOR(XOR(prevNode,NULL),NULL)) = NULL이다.
			//따라서 새로운 currentNode가 NULL이 될때 종료하면 된다.

int print_left(list_t* list)
{
	node_t* currentNode; //현재 노드의 주소를 나타내는 변수
	node_t* prevNode;	//이전 노드의 주소를 저장하는 변수
	node_t* tempNode;	//지워지지 말라고 임시로 노드 주소를 저장하는 변수

	if (!list)
	{
		return -1;
	}

	currentNode = list->head; //우선 현재 노드는 헤드에서부터 시작한다.
	prevNode = NULL; //당연히 이전 노드의 주소는 널이다.

	while (currentNode)
	{
		printf("%d\n", currentNode->data); //우선 현재 노드의 값을 출력하고
		tempNode = currentNode; //현재 주소를 임시로 저장한다.
		currentNode = XOR(currentNode->link, prevNode); //XOR을 통해 다음 노드로 넘어가고
		prevNode = tempNode; //아까 저장한 임시 저장소를 가지고 이전 노드의 주소를 저장한다.
	}
	printf("\n");

	return 0;
}

//오른쪽에서 왼쪽으로 체크하면서 출력하는 함수는
//앞서 언급한 일반성을 잃지 않고 같은 방식으로 성립하는 경우에 해당한다.
//prev로 next를 알아내는 이전 방법의 역전된 형태로
//next를 가지고 prev를 알아내는 방법을 사용한다.
//리스트에서 이미 next가 NULL로 확정된 tail이 주어지기 때문에
//그것으로부터 하나씩 앞으로 진행하는 것이 가능하다.

//코드에서도 prevNode 대신 nextNode 변수를 사용하는 것.
//list->head 대신 list->tail을 사용하는 것 말고는 모두 같은 방법으로 구현가능하다.

//경계조건을 다시 살펴보면
	//i)current 가 tail인 경우
		//tail이 가지고 있는 link의 값은 XOR(prevNode,NULL)이므로
		//NULL인 XOR(nextNode, XOR(prevNode,Null)  = prevNode가 된다.
		//따라서 예외가 되지 않는다.
	//ii)current가 head인 경우
		//오른쪽에서 왼쪽으로의 탐색이 끝난 경우이므로 이것을 종료조건으로 한다.
		//current->link 의 값은 XOR(NULL,nextNode)이므로
		//XOR(XOR(NULL,nextNode),nextNode) = NULL이다.
		//결국 새로운 currentNode가 NULL인 경우 종료해주면 된다.
//왼쪽에서 오른쪽으로 출력하는 것과 동일한 조건으로 수행 가능하다.

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