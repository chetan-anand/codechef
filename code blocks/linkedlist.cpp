#include<iostream>
#include<string>
#include<stdio.h>
struct node
{
    s;
    struct node *ptr;
};
struct node *cnode()
{
    temp=(struct node*)malloc(sizeof(struct node));
    return temp;
}
void freenode(struct node *node)
{
    free(node);
}
void printlist(struct node *start)
{
    struct node *temp;
    temp =start;
    while(temp!=NULL)
    {
        printf("%d\n",tmep->data);
        temp=temp->ptr;
    }
}
