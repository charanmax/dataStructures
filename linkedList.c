#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *next;
};
void create();
void _insertbegin();
void _insertend();
void _insertpos();
void display();
void _deletebegin();
void _deleteend();
void _deletepos();
void reverse();
struct node *head,*temp,*newnode;
int main()
{
    while(1)
    {
printf("\n1.create\n2.insert_begin\n3.insert_end\n4.insert_pos\n5.display\n6.delete_begin\n7.delete_end\n8.delete_pos\n9.reverse\nenter you choice:");
int ch;
scanf("%d",&ch);
switch(ch)
{
    case 1:create();
    break;
    case 2:_insertbegin();
    break;
    case 3:_insertend();
    break;
    case 4:_insertpos();
    break;
    case 5:display();
    break;
    case 6:_deletebegin();
    break;
    case 7:_deleteend();
    break;
    case 8:_deletepos();
    break;
    case 9:reverse();
    break;

}
    }

}
void create()
{
   // int ch;
    //while(ch)
    //{
newnode=(struct node *)malloc(sizeof(struct node));
printf("enter data:");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(head==NULL)
head=temp=newnode;
else
temp->next=newnode;
temp=newnode;
//printf("do you want to enter the data again:(0,1)");
//scanf("%d",&ch);
   // }

}
void display()
{
     temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    //printf("%d\n",temp->data);

}
void _insertbegin()
{
 temp=head;
 newnode=(struct node *)malloc(sizeof(struct node));
 printf("enter data at beginning:");
 scanf("%d",&newnode->data);
 newnode->next=head;
 head=newnode;
}
void _insertend()
{
    temp=head;
    newnode=(struct node *)malloc(sizeof(struct node));
 printf("enter data at end:");
 scanf("%d",&newnode->data);
 newnode->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void _insertpos()
{
    int pos,i=1;
    int count=0;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("enter the position:");
    scanf("%d",&pos);
    if(pos>=count)
    {
        printf("invalid position\n");
    }
    else
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter the data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void _deletebegin()
{
    if(head==0)
    {
        printf("no nodes in the list!\n");
    }
    temp=head;
head=head->next;
free(temp);
}
void _deleteend()
{
    struct node *prevnode;
    temp=head;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=NULL;
    free(temp);
}
void _deletepos()
{
    struct node *nextnode;
    temp=head;
    int i=1,pos;
    printf("enter the position:");
    scanf("%d",&pos);
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
}
/*void display()
{
     temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }

}*/
void reverse()
{
struct node *prevnode,*currentnode,*nextnode;
if(head==NULL)
{
    printf("no nodes bro:\n");
}
currentnode=nextnode=head;
prevnode=0;
while(nextnode!=NULL)
{
    nextnode=nextnode->next;
    currentnode->next=prevnode;
    prevnode=currentnode;
    currentnode=nextnode;
}
while(prevnode!=NULL)
{
    printf("%d",prevnode->data);
    prevnode=prevnode->next;
}



}
