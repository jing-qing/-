# include<stdio.h>
# include<stdlib.h>

//本栈由链表实现，即为链式栈

typedef struct stack//创建结构体栈
{
	int longth;//栈的长度
	struct node* top;//指向栈顶的指针变量

}STACK;

typedef struct node//创建结构体栈的节点
{
	struct node* next;//指向下一个节点的指针变量
	void* date;//指向数据的指针

}NODE;


STACK* create_stack();//创建栈，返回值该栈的地址
STACK* push_stack(STACK* stack,void* date);//入栈，输入栈的地址和变量的地址，输出栈的地址
void* pop_stack(STACK* stack);//出栈，输入栈的地址，输出栈中数据的地址，注意：输出的是栈中数据的地址，不是该数据，需要将该地址转化为所指的数据类型
void empty_stack(STACK* stack);//清空栈，清空栈中所有节点
void release_stack(STACK* stack);//释放栈，将栈中节点和栈全部释放

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9},i;
	int* b[9];
	char c = 'F';
	char* p;

	STACK* stack = create_stack();
	for(i=0;i<9;i++)
		push_stack(stack,&a[i]);
	push_stack(stack,&c);
	empty_stack(stack);
	p = pop_stack(stack);//因为该函数输出的是一个void*型地址，需要将其进行转化，左边p为char*型地址，即该函数输出的地址转化为了指向该地址的字符型指针p，若要输出p指向的字符变量，只需进行*p操作
	printf("%c\n",*p);
	for(i=0;i<9;i++)
	{
		b[i] = pop_stack(stack);
		printf("%d\n",*b[i]);
	}

	return 0;
}


STACK* create_stack()
{
	STACK* stack;

	stack = malloc(sizeof(STACK));

	if(stack == NULL)
	{
		printf("空间分配失败！");
		exit(-1);
	}
	else
	{
		stack->longth = 0;
		stack->top = NULL;
	}

	return stack;
}

STACK* push_stack(STACK* stack,void* date)
{
	NODE* node;

	node = malloc(sizeof(NODE));

	node->next = stack->top;
	node->date = date;
	stack->top = node;
	stack->longth++;

	return stack;
}


void* pop_stack(STACK* stack)
{
	NODE* pTail;
	void* date;

	if(stack->top == NULL)
	{
		printf("该栈为空！");
		exit(-1);
	}
	else
	{
		pTail = stack->top;
		stack->top = stack->top->next;
		date = pTail->date;
		free(pTail);
		pTail = NULL;
	}

	return date;
}

void empty_stack(STACK* stack)
{
	NODE* pTail;

	for(;stack->longth>0;stack->longth--)
	{
		pTail = stack->top;
		stack->top = stack->top->next;
		free(pTail);
	}

}

void release_stack(STACK* stack)
{
	void empty_stack(stack);
	free(stack);

}