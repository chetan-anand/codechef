#include<stdio.h>
#include<string.h>
struct node
{
    int line;
    int fileno;
    char* word[20];
    struct node *ptrnext;
    struct node *ptrprev;
}

struct node *createnode()
{
    temp=(struct node *)malloc(sizeof(struct node));
    return temp;
}

void freenode(struct node* node)
{
    free(node);
}

int main()
{
    int *pointers[100000]={NULL};
    int i,j,k;
    for(i=0;i<=10;i++)
    {
        pointers
    }
}
