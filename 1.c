#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node_ll{
	char *element;
	struct node_ll *next;
};

typedef struct node_ll* NODE;
NODE insert_top(void);
void display_from_top(NODE);
NODE create_node(char*);
NODE head;
void logic_caller();
int main()
{
	printf("Enter\n'1'-> Insert from top\n'2'-> Remove from top\n'3'-> Insert from bottom\n'4'-> Remove from bottom\n'5'-> Display the elements from top\n'6'-> Display elements from bottom\n'7'-> Reverse the linked list\n'8'-> Find the middle node\n'9'-> Exit linked list program\n");
	logic_caller();
	return 0;
}

void logic_caller()
{
	char *ch;
	int i;
	ch = (char*)malloc(10);
	fgets(ch,10,stdin);
	i = atoi(ch);
	switch (i)
	{
		case 1:
			head = insert_top();
			printf("Press '9' to exit or any other to continue\n");
			logic_caller();
			break;
		case 2:
			/*remove_top();
			printf("Press '9' to exit or any other to continue\n");
			logic_caller();
			break;
		case 3:
			insert_bottom();
			printf("Press '9' to exit or any other to continue\n");
			logic_caller();
			break;
		case 4: 
			remove_bottom();
			printf("Press '9' to exit or any other to continue\n");
			logic_caller();
			break;*/
		case 5:
			printf("Calling display function \n");
			display_from_top(head);
			printf("Press '9' to exit or any other to continue\n");
			logic_caller();
			break;/*
		case 6:
			display_from_bottom(head);
			printf("Press '9' to exit or any other to continue\n");
			logic_caller();
			break;
		case 7:
			reverse(head);
			printf("Press '9' to exit or any other to continue\n");
			logic_caller();
			break;
		case 8:
			middle_node(head);
			printf("Press '9' to exit or any other to continue\n");
			logic_caller();
			break;*/
		case 9:
			exit(0);
			break;
	}
	return ;
}


NODE insert_top()
{
	char* data;
	NODE temp;
	//temp = NULL;
	data = (char*)malloc(100);
	printf("Enter data\n");
	fgets(data,100, stdin);
	temp = create_node(data);
	if(head == NULL)
	{
		head = temp;
		return temp;
	}
	temp->next = head;
	head = temp;
	return head;
}

NODE create_node(char *data)
{
	NODE main;
	if(data)
	{
		main = (NODE)malloc(sizeof(struct node_ll));
		main->element = (char*)malloc(100);
		strcpy(main->element,data);
		main->next = NULL;
	}
	else
	{
		printf("Enter valid data\n");
		insert_top();
	}
	return main;
}

void display_from_top(NODE top)
{
	printf("Inside display\n");
	NODE temp = top;
	if(temp == NULL)
	{
		printf("No elements to print\n");
		return;
	}
	while(temp!=NULL)
	{
		printf("%s\n",temp->element);
		temp= temp->next;
		return;
	}
}
