#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int data;
    struct node *link;
};
//link list traversal
void linkdele(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->link;

    }
}
//deletion at begin
struct node *begin(struct node *head)
{
    struct node *ptr=head;
    
    head=head->link;
    free(ptr);
    return head;
}

//deletion at specific index
struct node*atindex(struct node *head,int index)
{
struct node *p=head;
struct node *q=head->link;
for(int i=0;i<index-1;i++)
{
    p=p->link;
    q=q->link;
}
p->link=q->link;

free(q);

return head;
}
//deletion at end
struct node *end(struct node *head)
{
    struct node *p=head;
    struct node *q=head->link;
    while(q->link!=NULL)
    {
        p=p->link;
        q=q->link;
    }
    p->link=NULL;
    free(q);
    return head;
    
}
//deletion atnode
struct node *atnode(struct node *head,int value)
{
    struct node *p=head;
    struct node *q=head->link;
    {
        while(q->data!=value && q->link!=NULL)
        {
            p=p->link;
            q=q->link;
        }
        if(q->data==value)
        {
            p->link=q->link;
            free(q);
        }
            return head;
        
    }
    
}
int main()
{
    int value;
struct node *head;
struct node *second;
struct node *third;
struct node *fourth;
struct node *fifth;
struct node *sixth;
head=(struct node *)malloc(sizeof(struct node));
second=(struct node *)malloc(sizeof(struct node));
third=(struct node *)malloc(sizeof(struct node));
fourth=(struct node *)malloc(sizeof(struct node));
fifth=(struct node *)malloc(sizeof(struct node));
sixth=(struct node *)malloc(sizeof(struct node));
head->data=587;
head->link=second;
second->data=869;
second->link=third;
third->data=5796;
third->link=fourth;
fourth->data=57657879;
fourth->link=fifth;
fifth->data=876;
fifth->link=sixth;
sixth->data=8654467;
sixth->link=NULL;
printf("link list before deletion is\n\n");
linkdele(head);
head=begin(head);
printf("ente the value");
scanf("%d",&value);
head=atindex(head,value);
head=end(head);
printf("\nthe link list is after deletion\n");
linkdele(head);
return 0;
}

