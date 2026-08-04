#include<stdio.h>
#include<stdlib.h>

struct student
{
    int id;
    int Maths;
    int Science;
    struct student *next;
};

struct student *front=NULL,*rear=NULL;

void add()
{
    struct student *newnode;
    newnode=(struct student *)malloc(sizeof(struct student));
    printf("Enter ID: ");
    scanf("%d",&newnode->id);
    printf("Enter Maths Mark: ");
    scanf("%d",&newnode->Maths);
    printf("Enter Science Mark: ");
    scanf("%d",&newnode->Science);
    newnode->next=NULL;
    if(front==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    printf("Added Successfully\n");
}

void removeentry()
{
    struct student *temp;
    if(front==NULL)
    {
        printf("Queue Empty\n");
        return;
    }
    temp=front;
    printf("\nRemoved Record\n");
    printf("ID      : %d\n",temp->id);
    printf("Maths   : %d\n",temp->Maths);
    printf("Science : %d\n",temp->Science);
    front=front->next;
    if(front==NULL)
        rear=NULL;
    free(temp);
}

void display()
{
    struct student *temp=front;
    if(temp==NULL)
    {
        printf("Queue Empty\n");
        return;
    }
    printf("\nQueue (Front to Rear)\n");
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
        printf("\n1.Add");
        printf("\n2.Remove");
        printf("\n3.Display Queue");
        printf("\n4.Exit");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                add();
                break;
            case 2:
                removeentry();
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
