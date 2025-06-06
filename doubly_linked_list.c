#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	struct Node *next;
	struct Node *prev;
	char data[100];
};

enum Direction 
{
	FORWARD,
	BACKWARD
};

void add_to_list_v1(struct Node **head, char *data)
{
	//create node on the heap
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	if(node==NULL)
	{
		perror("malloc: ");
		exit(EXIT_FAILURE);
	}

	memset(node->data,'\0',100);
	strcpy(node->data,data);

	//pointer linking
	node->next = (*head);
	if((*head)!=NULL)
	{
		(*head)->prev = node;
	}
	(*head) = node;	
}

void print_list(struct Node **head,enum Direction dir)
{
	struct Node *ptr = (*head);
	if(dir==FORWARD)
	{
		while(ptr)
		{
			printf("%s\n",ptr->data);
			ptr = ptr->next;
		}	
	}
	else
	{
		while(ptr->next)
		{
			ptr = ptr->next;
		}
		while(ptr)
		{
			printf("%s\n",ptr->data);
			ptr = ptr->prev;
		}
	}
}

//adding stack operations, being pop, but in this case delete at head O(1) LIFO
void pop(struct Node **head)
{
	struct Node *ptr = (*head);
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	
	printf("popped: %s\n",ptr->data);
	free(ptr);
}

void delete_node(struct Node **head,char *data)
{
	struct Node *ptr = (*head);

	while(ptr)
	{
		if(strcmp(ptr->data,data)==0)
		{
			if(ptr==(*head))
			{
				pop(head);
			}
			else{
				ptr->next->prev = ptr->prev;
				ptr->prev->next = ptr->next;
				free(ptr);
			}
		}
	}
}


int main()
{
	struct Node *head = NULL;
	
	add_to_list_v1(&head,"hello");
	add_to_list_v1(&head,"small");
	add_to_list_v1(&head,"human");
	
	pop(&head);
//	print_list(&head,FORWARD);
	print_list(&head,FORWARD);

	printf("attempting to print backward\n");
	print_list(&head,BACKWARD);

//	printf("%s\n",head->next->next->prev->data);

	return 0;
}
