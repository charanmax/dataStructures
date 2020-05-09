#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 struct node *next;
 struct node *beg;
}*head,*temp,*newnode,*delnode;
void create();
void display();
void _insertbegin();
void _deletebegin();
void _insertend();
void _insertmiddle();
int main()
{




create();
display();
_insertbegin();
display();
_deletebegin();
printf("after deleting first node:\n");
display();
_insertend();
display();
_insertmiddle();

display();

}
void create()
{
  int ch;
    do
    {
     newnode=(struct node *)malloc(sizeof(struct node));
     printf("enter data:");
     scanf("%d",&newnode->data);
     newnode->beg=NULL;
     newnode->next=NULL;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else
    {
        newnode->beg=temp;
        temp->next=newnode;
        temp=newnode;
        temp->next=head;


    }
    printf("0/1");
    scanf("%d",&ch);
    }while(ch);
}
void _insertbegin()
{

    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&newnode->data);
    newnode->beg=NULL;
    newnode->next=head;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    temp->next=newnode;

 head->beg=newnode;
 head=newnode;

}
void _deletebegin()
{
   delnode=head;
   temp->next=head->next;
    head=head->next;
    head->beg=NULL;
   free(delnode);


}

void display()
{
    temp=head;
    while(temp->next!=head)
    {
        printf("%d  ",temp->data);
        temp=temp->next;

    }
    printf("%d",temp->data);
}
void _insertend()
{
newnode=(struct node *)malloc(sizeof(struct node));
printf("enter the data:");
scanf("%d",&newnode->data);
newnode->beg=NULL;
newnode->next=NULL;
if(head==NULL)
{
 printf("NO NODES BRO!");
}
temp=head;
while(temp->next!=head)
{
    temp=temp->next;
}
temp->next=newnode;
newnode->beg=temp;
newnode->next=head;
}
void _insertmiddle()
{
    temp=head;
int pos;
printf("enter the position:");
scanf("%d",&pos);
int i=1;
while(i<pos)
{
  temp=temp->next;
  i++;
}
newnode=(struct node *)malloc(sizeof(struct node));
printf("enter the data:");
scanf("%d",&newnode->data);
newnode->beg=NULL;
newnode->next=NULL;
newnode->next=temp->next;
temp->next->beg=newnode;
newnode->beg=temp;
temp->next=newnode;
}

