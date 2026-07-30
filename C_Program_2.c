#include<stdio.h>
#include<stdlib.h>

struct student
{
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
        newnode->next=NULL;
        if(head==NULL)
            head=newnode;
        else
        {
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
        }
    }
}

void insertbefore()
{
    int key;
    struct student *newnode,*temp,*prev=NULL;
    printf("Insert before ID: ");
    scanf("%d",&key);
    newnode=(struct student *)malloc(sizeof(struct student));
    printf("Enter New ID: ");
    scanf("%d",&newnode->id);
    printf("Enter Maths Mark: ");
    scanf("%d",&newnode->Maths);
    printf("Enter Science Mark: ");
    scanf("%d",&newnode->Science);
    newnode->next=NULL;
    temp=head;
    while(temp!=NULL&&temp->id!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("ID Not Found\n");
        free(newnode);
        return;
    }
    if(prev==NULL)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        prev->next=newnode;
        newnode->next=temp;
    }
    printf("Inserted Successfully\n");
}

void insertafter()
{
    int key;
    struct student *newnode,*temp;
    printf("Insert after ID: ");
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
    temp->next=newnode;
    printf("Inserted Successfully\n");
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
        printf("\n2.Display List");
        printf("\n3.Exit");
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
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
