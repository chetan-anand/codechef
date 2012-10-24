#include<stdio.h>
#include<stdlib.h>


//defining the structure of node
struct node
{
    char a[20];
    int fileno;
    int lineno;
    int data;  //type of data in the node
    struct node *ptr;   //pointer data in the node
};


//  defining the createnode function which returns the node type adress
struct node *createnode()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->ptr=NULL;
    return temp;
};

void display(struct node *start)
{
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->ptr;
    }
}

void insert(struct node* temp)
{
    struct node* temp1;
    scanf("%d",&(temp->data));
}

void addnext(struct node* temp)
{
    temp->ptr=createnode();
    temp=temp->ptr;
    insert(temp);
}

/*void addhead(struct node* temp)
{
    struct node*temp1;
    temp1=createnode();
    temp1->ptr=temp;
    insert("%d",&)
}*/

int main()
{
    int n;
    struct node *start,*end,*temp,*temp1;
    char ch='y';
    start=createnode();
    temp=start;
    while(ch=='y')
    {
        printf("insert a new number=");
        scanf("%d",&n);
        temp->data=n;
        temp->ptr=NULL;
        printf("do u wanna contineue y/n:");
        getchar();
        scanf("%c",&ch);
        if(ch=='y')
        {
            temp->ptr=createnode();
            temp=temp->ptr;
        }
    }
    display(start);
    return 0;
}
