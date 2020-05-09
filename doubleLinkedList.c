#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *beg;
    struct node *next;
};
void create();
void _insertbegin();
void _insertend();
void _insertposafter();
void display();
void _insertposbefore();
void _deletebegin();
void _deleteend();
void _deletepos();
struct node *head,*temp,*newnode,*tail;
int main()
{
    while(1)
    {
printf("\n1.create\n2.insert_begin\n3.insert_end\n4.insert_pos_after\n5.display\n6.insert_pos_before\n7._deletebegin\n8._deleteend\n9._deletepos\nenter you choice:");
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
    case 4:_insertposafter();
    break;
    case 5:display();
    break;
    case 6:_insertposbefore();
    break;
    case 7:_deletebegin();
    break;
    case 8:_deleteend();
    break;
    case 9:_deletepos();
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
newnode->beg=NULL;
if(head==NULL)
head=temp=newnode;
else
newnode->beg=temp;
temp->next=newnode;
temp=newnode;
tail=newnode;
//printf("do you want to enter the data again:(0,1)");
//scanf("%d",&ch);
   // }

}
void display()
{
     temp=head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
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
head->beg=newnode;
 newnode->beg=NULL;
 head=newnode;
}
void _insertend()
{
    temp=head;
    newnode=(struct node *)malloc(sizeof(struct node));
 printf("enter data at end:");
 scanf("%d",&newnode->data);
 newnode->beg=NULL;
 newnode->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
     newnode->beg=temp;
    temp->next=newnode;
    tail=newnode;
}
void _insertposafter()
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
        newnode->beg=NULL;
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        newnode->beg=temp;
             temp->next->beg=newnode;

        temp->next=newnode;
    }
}
void _insertposbefore()
{
    int pos,count=0;
    temp=head;
    int i=1;
    printf("enter the position:");
    scanf("%d",&pos);
    while(temp!=NULL)
    {
       count++;
       temp=temp->next;
    }
    if(pos>count)
    {
        printf("invalid position\n");
    }
    else
        newnode=(struct node *)malloc(sizeof(struct node));
    newnode->beg=0;
    newnode->next=0;
    printf("enter the data:");
    scanf("%d",&newnode->data);
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
           temp->beg->next=newnode;
           newnode->beg=temp->beg;
           newnode->next=temp;
           temp->beg=newnode;
}
void _deletebegin()
{
    if(head==0)
    {
        printf("no nodes bro!");
    }
    temp=head;
    head=head->next;
    free(temp);
}
void _deleteend()
{
 temp=head;
 while(temp->next!=NULL)
 {
     temp=temp->next;
 }
             temp->beg->next=NULL;
             free(temp);
}
void _deletepos()
{
    int count=0;;
    temp=head;
    int i=1;
    int pos;
    printf("enter the position:");
    scanf("%d",&pos);
     while(temp!=NULL)
    {
       count++;
       temp=temp->next;
    }
    if(pos>count)
    {
        printf("invalid position\n");
    }
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
                  temp->next->beg=temp->beg;
                  temp->beg->next=temp->next;
                  free(temp);


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

