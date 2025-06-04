#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	char data[100];
	struct Node *next;
};


void free_list(struct Node **head)
{
	struct Node *ptr = (*head);
	while((*head)!=NULL)
	{
		(*head) = (*head)->next;
		free(ptr);
		ptr = (*head);
	}
}

void add_to_list_v1(struct Node **head,char *data)
{
	//create a node, fill with data and then add
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	if(!node)
	{
		perror("malloc: ");
		exit(EXIT_FAILURE);
	}

	memset(node->data,'\0',100);
	if(data)
		strncpy(node->data,data,99);

	//version 1 way of appending to a list
	node->next = *head;
	*head = node;	
}

//O(n)
void print_list(struct Node **head)
{
	struct Node *ptr = (*head);
	while(ptr!=NULL)
	{
		printf("data = %s\n",ptr->data);
		ptr = ptr->next;
	}
}

//O(n)
void reverse_list(struct Node **head)
{
	struct Node *newhead = NULL;
	struct Node *ptr = (*head);
	
	while(ptr!=NULL)
	{
		struct Node *node = (struct Node*)malloc(sizeof(struct Node));
		if(!node)
		{
			perror("malloc: ");
			exit(EXIT_FAILURE);
		}

		strcpy(node->data,ptr->data);
		node->next = newhead;
		newhead = node;
		ptr = ptr->next;
		
	}

	//now let's attempt to print this out#
	print_list(&newhead);

	(*head) = newhead;
	
}
//n*n = O(n^2), as long as n is small, it's not so bad
void selection_sort(struct Node **head)
{
	//sort by smallest to largest
	struct Node *ptr = (*head);
	struct Node *ptr2 = ptr;
	struct Node *selected = ptr;
	struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
	while(ptr!=NULL)
	{
//		printf("ptr1 = %s and length = %d\n",ptr->data,strlen(ptr->data));
					
		while(ptr2!=NULL)
		{
//			printf("\tptr2 = %s and length = %d\n",ptr2->data,strlen(ptr2->data));

			if(strcmp(ptr->data,ptr2->data)>0)
			{
				strcpy(tmp->data,ptr->data);
				strcpy(ptr->data,ptr2->data);
				strcpy(ptr2->data,tmp->data);
			} 

			ptr2 = ptr2->next;

		}
		ptr = ptr->next;
	}
	
	print_list(head);	
		
}

//finding a node O(n) deleting O(1) we don't have to shift elements down like in an array
void delete_node(struct Node **head,char *name)
{
	struct Node *curr = (*head);
	struct Node *prev = curr;
	
	while(curr!=NULL)
	{
		 
			
		if(strcmp(name,curr->data)==0)
		{
			if(curr==(*head))
			{
				(*head) = (*head)->next;
				free(curr);
				break;
			}
			else{
				prev->next = curr->next;
				free(curr);
			}			
		}
		prev = curr;
		curr = curr->next;
	}		
}



int main()
{
	struct Node *head = NULL;

	add_to_list_v1(&head,"hello");
	add_to_list_v1(&head,"worlddd");
	add_to_list_v1(&head,"megateacup");
	print_list(&head);

	printf("deleting node: hello\n");
	delete_node(&head,"hello");

	print_list(&head);

	free_list(&head);

//	printf("\nReverse print\n");
//	reverse_list(&head);

	/*printf("\nReverse print\n");
	reverse_list(&head);*/

//	printf("sorting smallest to largest\n");
//	selection_sort(&head);

	return 0;
}


