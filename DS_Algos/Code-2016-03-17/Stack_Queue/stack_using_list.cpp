//Implementation of stack using Linked list
#include <iostream>
#include <cstdio>
#include <cstdlib>
 
typedef struct stack{
	int data;
	struct stack *next;
}Stack_Link;
 
typedef struct top{
	Stack_Link *TOP;
}Top_of_Stack;
Top_of_Stack *TOS =NULL;
//Insert the element in stack 
 
void push(int a)
{
	Stack_Link *new;
 
	 new = (Stack_Link *)malloc(sizeof(Stack_Link));
	 new->data = a;
	 new->next = TOS;
	 TOS = new;
	  printf("\nItem is pushed");
}	
 
// Remove the element from stack
int pop()
{
	int ret;
    if(TOS == NULL) //If stack is empty exit from func
    {
    	printf("\n Stack is empty");
    	exit(3);
    }
    else
    {
    	ret = TOS->data;
    	TOS = TOS->next;
    }
    return ret;
}
 
int main(void) {
	// your code goes here
	int ch, tem, ret;
 
	while(1)
	{
		printf("\nEnter your choice ");
		printf("\n1: push \n2: pop \n3: exit \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nenter the data which has to be enter in stack\n");
			        scanf("%d",&tem);
			        push(tem);
			        break;
			case 2: ret = pop();
                    printf("\n%d item is popped from stack\n",ret);
			        break;
			case 3: exit(1);
			default : printf("\n Wrong choice\n");
		}
	}
 
	return 0;
}