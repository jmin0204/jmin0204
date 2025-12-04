#include<stdio.h>
#include <stdlib.h>

typedef enum STEP
{
	STEP1 = 1,
	STEP2,
	STEP3,
	STEP4,
	STEP5
}Mystep; 


typedef int ElementType;
typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;
}Node;

Node* SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
};

void SLL_DestroyNode(Node* Node)
{
	free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
	//헤드 노드가 NULL 이라면 새로운 Node가 Head가 된다.
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// 테일을 찾아 NewNode를 연결한다.
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;

	}
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

void SLL_RemoveNode(Node** Head, Node* Remove)
{
	//Node의 첫번째 값이 삭제하려는 값일때 그 값의 다음값을 헤드로 변경
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
	}

	else
	{	
		//Node의 첫번째 값이 NULL 이 아닐 경우 헤드값부터 NULL이 아니고, 다음노드값이 삭제하려는 값일때까지 다음노드를 찾는다
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		//다 찾았으면 그 값이 혹시모를 NULL일수도 있으니 예외 처리 이후 원래의 다음값을 삭제하려는 노드의 다음값으로 변경
		if (Current != NULL)
		{
			Current->NextNode = Remove->NextNode;
		}
	}
}

void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	//새로 넣으려는 NewNode의 NextNode값을 넣으려는 노드위치의 다음값으로 설정
	NewNode->NextNode = Current->NextNode;

	//현재노드의 NextNode값을 새로 넣으려는 Node값으로 설정
	Current->NextNode = NewNode;

	//SLL_AppendNode(&List, SLL_CreateNode(117));
	//SLL_AppendNode(&List, SLL_CreateNode(119));
	//SLL_AppendNode(&List, SLL_CreateNode(212));
	
	//MyNode = SLL_GetNodeAt(List, 1);
	//NewNode = SLL_CreateNode(999);
	//SLL_InsertAfter(MyNode, NewNode);

	//해석) MyNode 는 넣으려는 위치
	//119의 다음값이 212인데 새로 넣으려는 999의 다음값을 212로 설정
	//119의 다음값을 999로 설정

	//결과) 117->119->999->212
}

int SLL_GetNodeCount(Node* Head)
{
	int		Count = 0;
	Node*	Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;

}

int main()
{
	Mystep step;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* MyNode = NULL;

	step = STEP5;

	switch (step)
	{
	case STEP1:
		NewNode = SLL_CreateNode(117);
		SLL_AppendNode(&List, NewNode);
		NewNode = SLL_CreateNode(119);
		SLL_AppendNode(&List, NewNode);
		break;
	case STEP2:
		SLL_AppendNode(&List, SLL_CreateNode(117));
		SLL_AppendNode(&List, SLL_CreateNode(119));
		MyNode = SLL_GetNodeAt(List, 1);
		printf("%d\n", MyNode->Data);
		break;
	case STEP3:
		SLL_AppendNode(&List, SLL_CreateNode(117));
		SLL_AppendNode(&List, SLL_CreateNode(119));
		SLL_AppendNode(&List, SLL_CreateNode(212));
		
		MyNode = SLL_GetNodeAt(List, 1);
		printf("%d 의값을 삭제 후 그 다음값이 2번째(1번쨰 값)\n", MyNode->Data);
		SLL_RemoveNode(&List, MyNode);
		SLL_DestroyNode(MyNode);

		MyNode = SLL_GetNodeAt(List, 1);
		printf("삭제 이후 2번쨰 값: %d\n", MyNode->Data);
		break;
	case STEP4:
		SLL_AppendNode(&List, SLL_CreateNode(117));
		SLL_AppendNode(&List, SLL_CreateNode(119));
		SLL_AppendNode(&List, SLL_CreateNode(212));

		MyNode = SLL_GetNodeAt(List, 1);
		NewNode = SLL_CreateNode(999);
		SLL_InsertAfter(MyNode, NewNode);
		printf("현재값 : %d\n", MyNode->Data);

		MyNode = SLL_GetNodeAt(List, 2);
		printf("변경값 : %d\n", MyNode->Data);
		break;
	case STEP5:
		SLL_AppendNode(&List, SLL_CreateNode(117));
		SLL_AppendNode(&List, SLL_CreateNode(119));
		SLL_AppendNode(&List, SLL_CreateNode(212));

		int value = SLL_GetNodeCount(List);

		printf("Count : %d", value);
		break;
	}


return 0;

}