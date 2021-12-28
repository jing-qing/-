# include<stdio.h>
# include<stdlib.h>

typedef struct Node
{
	int date;          //数据域，该数据为整形，即该链表存储的数据为整形
	struct Node* pNext;//指针域

}NODE;

NODE* creat_list();//该函数用于创建链表（创造一个头节点，该节点数据域为该链表存储的数据的个数），返回值为头节点的地址（头指针）
void scanf_list(int val,NODE* pHead);//该函数用于向链表从尾部开始输入元素
NODE* traverse_list(NODE* pHead);//该函数的作用是将链表进行一次遍历，输出值为最后一个节点的地址
void printf_list(NODE* pHead);//该函数用于将链表输出
int longth_list(NODE* pHead);//该函数用于输出链表长度
void insert_list(NODE* pHead,int val,int pos);//该函数用于向链表某一位置后面插入一个节点
void delete_list(NODE* pHead,int pos);//该函数用于删除该链表第pos个节点

int main()
{
	NODE* pa = creat_list();
	scanf_list(1,pa);
	scanf_list(2,pa);
	scanf_list(3,pa);
	printf_list(pa);
	printf("\n");
	insert_list(pa,5,2);
	printf_list(pa);
	printf("%d\n",longth_list(pa));
	delete_list(pa,3);
	printf_list(pa);
	printf("%d",longth_list(pa));

	return 0;
}
NODE* creat_list()
{
	NODE* pHead; //定义头指针

	pHead = (NODE*) malloc(sizeof(NODE));//为头节点分配空间并将头结点的地址赋给头指针

	pHead->date = 0;//该链表还未存入数据，所以数据域为0
	pHead->pNext = NULL;

	return pHead;//返回值为头指针
}

NODE* traverse_list(NODE* pHead)
{
	NODE* pNext = pHead;

	while(pNext->pNext != NULL)
		pNext = pNext->pNext;

	return pNext;
}

void scanf_list(int val,NODE* pHead)
{
	NODE* pNext;

	pNext = traverse_list(pHead);

	pNext->pNext = (NODE*) malloc(sizeof(NODE));

	if(pNext->pNext == NULL)
	{
		printf("内存不足，分配失败！");
		exit(-1);
	}
	else
	{
		pNext->pNext->date = val;
		pNext->pNext->pNext  = NULL;
		pHead->date++;
	}

	return;
}

void printf_list(NODE* pHead)
{
	int i;
	NODE* pTail;

	pTail = pHead->pNext;

	if(pHead->date != 0)
	{
		for(i=1;i<=pHead->date;i++)
		{
			printf("该链表第%d个节点的数据：%d\n",i,pTail->date);
			pTail = pTail->pNext;

		}
	}
	else
		printf("该链表为空！");
	return;
}

int longth_list(NODE* pHead)
{
	return pHead->date;
}

void insert_list(NODE* pHead,int val,int pos)
{
	int i;
	NODE* pTail = pHead->pNext,* pNew;

	if(pos>pHead->date)
	{
		printf("你所插入的节点位置大于链表长度！");
		exit(-1);
	}
	else
	{
		for(i=1;i<pos;i++)
			pTail = pTail->pNext;
	}

	pNew = (NODE*)malloc(sizeof(NODE));

	pNew->date = val;
	pNew->pNext = pTail->pNext;
	pTail->pNext = pNew;
	pHead->date++;

}

void delete_list(NODE* pHead,int pos)
{
	int i;
	NODE* pTail = pHead,* pTemp;

	if(pos>pHead->date)
	{
		printf("删除的该节点大于链表的长度！");
		exit(-1);
	}
	else
	{
		for(i=0;i<pos-1;i++)
			pTail = pTail->pNext;
	}

	pTemp = pTail->pNext;
	pTail->pNext = pTail->pNext->pNext;
	free(pTemp);
	pTemp = NULL;
	pHead->date--;

}
