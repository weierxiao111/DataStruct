#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "linklist.h"
int main()
{
	Node my_node;
    InitList(&my_node);
	PushBack(&my_node,  1);
	PushBack(&my_node,  2);
	PushBack(&my_node,  3);
	PushBack(&my_node,  4);
	PrintList(&my_node);

	return 0;
}

