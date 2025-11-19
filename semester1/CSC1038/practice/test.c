#include <stdio.h>

#include<stdlib.h>

struct node{

	int data;
	struct node *next;

};

struct node* insertAtLast(struct node * head,int d){

struct node *new=(struct node*)malloc(sizeof(struct node));

new->data=d;

new->next=NULL;

if(head==NULL){

head=new;

}else{

struct node *temp=head;

while(temp->next!=NULL){

temp=temp->next;

}

temp->next=new;

}

return head;

}

int main()

{

struct node *head=NULL;

head=insertAtLast(head,10);

head=insertAtLast(head,20);

head=insertAtLast(head,30);

head=insertAtLast(head,40);

struct node* temp=head;

while(temp!=NULL){

printf("%d\n",temp->data);

temp=temp->next;

}

return 0;

}