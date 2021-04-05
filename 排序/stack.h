#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;//栈顶
	int capacity;//容量
}Stack;

//栈的初始化
void StackInit(Stack* ps)
{
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

//入栈

void StackPush(Stack* ps, STDataType data)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		STDataType newCapacity = ps->capacity == 0 ? 4 : ps->capacity *2;
		ps->a = (STDataType*)realloc(ps->a, sizeof(STDataType)*newCapacity);
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = data;
	ps->top++;
}

//出栈

void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);

	ps->top--;
}

//判断栈是否为空

int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top ? 0 : 1;
}

//获取栈顶的元素

STDataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->a[ps->top - 1];
}


//栈的销毁

void StackDestory(Stack* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);

	StackPop(&s);
	StackPop(&s);
	StackPop(&s);

//	printf("%d ",StackTop(&s));

	while (!StackEmpty(&s))
	{
		s.top--;
		printf("%d ", s.a[s.top]);
	}
	
	StackDestory(&s);
}
