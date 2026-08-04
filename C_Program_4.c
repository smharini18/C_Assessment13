#include<stdio.h>
#include<stdlib.h>

struct student
{
    struct student *prev;
    int id;
    int Maths;
    int Science;
    struct student *next;
};

struct student *head=NULL;

void create()
{
    int i;
    struct student *newnode,*temp;
    for(i=1;i<=5;i++)
    {
        newnode=(struct student *)malloc(sizeof(struct student));
        printf("\nStudent %d\n",i);
        printf("Enter ID: ");
        scanf("%d",&newnode->id);
        printf("Enter Maths Mark: ");
        scanf("%d",&newnode->Maths);
        printf("Enter Science Mark: ");
        scanf("%d",&newnode->Science);
        newnode->prev=NULL;
        newnode->next=NULL;
        if(head==NULL)
            head=newnode;
        else
        {
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
            newnode->prev=temp;
        }
    }
}

void insertbefore()
{
    int key;
    struct student *newnode,*temp;
    printf("Insert Before ID: ");
    scanf("%d",&key);
    temp=head;
    while(temp!=NULL&&temp->id!=key)
        temp=temp->next;
    if(temp==NULL)
    {
        printf("ID Not Found\n");
        return;
    }
    newnode=(struct student *)malloc(sizeof(struct student));
    printf("Enter New ID: ");
    scanf("%d",&newnode->id);
    printf("Enter Maths Mark: ");
    scanf("%d",&newnode->Maths);
    printf("Enter Science Mark: ");
    scanf("%d",&newnode->Science);
    newnode->prev=temp->prev;
    newnode->next=temp;
    if(temp->prev!=NULL)
        temp->prev->next=newnode;
    else
        head=newnode;
    temp->prev=newnode;
    printf("Inserted Successfully\n");
}

void insertafter()
{
    int key;
    struct student *newnode,*temp;
    printf("Insert After ID: ");
    scanf("%d",&key);
    temp=head;
    while(temp!=NULL&&temp->id!=key)
        temp=temp->next;
    if(temp==NULL)
    {
        printf("ID Not Found\n");
        return;
    }
    newnode=(struct student *)malloc(sizeof(struct student));
    printf("Enter New ID: ");
    scanf("%d",&newnode->id);
    printf("Enter Maths Mark: ");
    scanf("%d",&newnode->Maths);
    printf("Enter Science Mark: ");
    scanf("%d",&newnode->Science);
    newnode->next=temp->next;
    newnode->prev=temp;
    if(temp->next!=NULL)
        temp->next->prev=newnode;
    temp->next=newnode;
    printf("Inserted Successfully\n");
}

void deleteentry()
{
    int key;
    struct student *temp=head;
    printf("Enter ID to Delete: ");
    scanf("%d",&key);
    while(temp!=NULL&&temp->id!=key)
        temp=temp->next;
    if(temp==NULL)
    {
        printf("ID Not Found\n");
        return;
    }
    if(temp->prev!=NULL)
        temp->prev->next=temp->next;
    else
        head=temp->next;
    if(temp->next!=NULL)
        temp->next->prev=temp->prev;
    free(temp);
    printf("Deleted Successfully\n");
}

void display()
{
    struct student *temp=head;
    if(temp==NULL)
    {
        printf("List Empty\n");
        return;
    }
    printf("\nStudent List\n");
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
    int choice,type;
    create();
    while(1)
    {
        printf("\n1.Insert Entry");
        printf("\n2.Delete Entry");
        printf("\n3.Display List");
        printf("\n4.Exit");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\n1.Insert Before");
                printf("\n2.Insert After");
                printf("\nEnter Option: ");
                scanf("%d",&type);
                if(type==1)
                    insertbefore();
                else if(type==2)
                    insertafter();
                else
                    printf("Invalid Option\n");
                break;
            case 2:
                deleteentry();
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
