#include<stdio.h>
#include<stdlib.h>

struct student
{
    int id;
    int Maths;
    int Science;
    struct student *next;
};

struct student *top=NULL;

void push()
{
    struct student *newnode;
    newnode=(struct student *)malloc(sizeof(struct student));
    printf("Enter ID: ");
    scanf("%d",&newnode->id);
    printf("Enter Maths Mark: ");
    scanf("%d",&newnode->Maths);
    printf("Enter Science Mark: ");
    scanf("%d",&newnode->Science);
    newnode->next=top;
    top=newnode;
    printf("Pushed Successfully\n");
}

void pop()
{
    struct student *temp;
    if(top==NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    temp=top;
    printf("\nPopped Record\n");
    printf("ID      : %d\n",temp->id);
    printf("Maths   : %d\n",temp->Maths);
    printf("Science : %d\n",temp->Science);
    top=top->next;
    free(temp);
}

void display()
{
    struct student *temp=top;
    if(temp==NULL)
    {
        printf("Stack Empty\n");
        return;
    }
    printf("\nStack (Top to Bottom)\n");
    while(temp!=NULL)
    {
        printf("----------------------\n");
        printf("ID      : %d\n",temp->id);
        printf("Maths   : %d\n",temp->Maths);
        printf("Science : %d\n",temp->Science);
        temp=temp->next;
    }
    printf("----------------------\n");
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display Stack");
        printf("\n4.Exit");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
