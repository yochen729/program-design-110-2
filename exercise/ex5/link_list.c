#include "myDS.h"
#include "basic.h"

// HEAD is point to FOODPAPA (id: 0)
void my_insert(struct node* HEAD, int ID, char *Name, int node_id){
	// Please insert a new node(store Name & node_id)
	// after the node which id is ID
	// If it doesn't exit such ID, print "INVALID OPERATION"
	struct node *ptr,*qtr,*temp;
	qtr = (struct node*)malloc(sizeof(struct node));//給空間
	qtr->id = node_id;//複製ID
	strcpy(qtr->name,Name);//複製名字
	qtr->next = NULL;
	ptr = HEAD;
	while(ptr->id != ID)
	{	//找位置
		if(ptr->next == NULL)
		{	//根本找不到
			printf("INVALID OPERATION\n");
			return;
		}
		if(strcmp(ptr->name,Name)==0)
		{	//重複名字
			free(qtr);
			printf("INVALID OPERATION\n");
			return;
		}
		ptr = ptr->next;
	}
	if(ptr->next == NULL)
	{	//直接插入
		ptr->next = qtr;
	}
	else
	{	//從中插入
		temp = ptr->next;
		ptr->next = qtr;
		qtr->next = temp;
	}
}
void my_delete(struct node* HEAD, char *Name){
	// Delete the node which store the Name.
	// If it doesn’t exit such Name, print “INVALID OPERATION”.
	struct node *ptr,*pre;
	pre = HEAD;
	ptr = HEAD->next;
	while(strcmp(ptr->name,Name) != 0)
	{	//找位置
		if(ptr->next == NULL)
		{	//根本找不到
			printf("INVALID OPERATION\n");
			return;
		}
		pre = ptr;
		ptr = ptr->next;
	}
	pre->next = ptr->next;
	free(ptr);
}
void my_swap(struct node *HEAD, char *Name1, char *Name2){
	// Swap the node which store Name1 and Name2
	// If either of the node doesn’t exit, print “INVALID OPERATION”
	// NOTICE: don't just swap the node's value
	// You need to break the link and recombine it
	struct node *ptr,*qtr,*pre1,*pre2,*temp;
	pre1 = pre2 = HEAD;
	ptr = qtr = HEAD->next;
	while(strcmp(ptr->name,Name1) != 0)
	{	//找位置1
		if(ptr->next == NULL)
		{	//根本找不到
			printf("INVALID OPERATION\n");
			return;
		}
		pre1 = ptr;
		ptr = ptr->next;
	}
	while(strcmp(qtr->name,Name2) != 0)
	{	//找位置2
		if(qtr->next == NULL)
		{	//根本找不到
			printf("INVALID OPERATION\n");
			return;
		}
		pre2 = qtr;
		qtr = qtr->next;
	}
	//swap
	pre1->next = qtr;
	pre2->next = ptr;
	temp = qtr->next;
	qtr->next = ptr->next;
	ptr->next = temp;
}
void my_print_id(struct node *HEAD, char *Name){
	// Print the id of the corresponding Name.
	// If Name doesn’t exit, print “INVALID OPERATION”
	struct node *ptr;
	ptr = HEAD;
	while(strcmp(ptr->name,Name) != 0)
	{	//找位置1
		if(ptr->next == NULL)
		{	//根本找不到
			printf("INVALID OPERATION\n");
			return;
		}
		ptr = ptr->next;
	}
	printf("%d\n",ptr->id);
}
void my_print_name(struct node *HEAD, int ID){
	// Print the name of the corresponding ID
	// If ID doesn’t exit, print “INVALID OPERATION”
	struct node *ptr;
	ptr = HEAD;
	while(ptr->id != ID)
	{	//找位置1
		if(ptr->next == NULL)
		{	//根本找不到
			printf("INVALID OPERATION\n");
			return;
		}
		ptr = ptr->next;
	}
	printf("%s\n",ptr->name);
}
void my_result(struct node* HEAD){
	// Print out all the information in the linked list orderly
	// in the format “ID NAME”. (start from HEAD)
	struct node *ptr;
	ptr = HEAD;
	printf("%d %s\n",ptr->id,ptr->name);
	while(ptr->next)
	{	//直到NULL
		ptr = ptr->next;
		printf("%d %s\n",ptr->id,ptr->name);
	}
}
