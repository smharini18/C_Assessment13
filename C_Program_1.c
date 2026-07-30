#include<stdio.h>
#include<stdlib.h>

struct student
{
    int id;
    int Maths;
    int Science;
    struct student *next;
};

void getdata(struct student **head)
{
    struct student *newnode,*temp;

    while(1)
    {
        newnode=(struct student *)malloc(sizeof(struct student));

        printf("Enter ID (-1 to Exit): ");
        scanf("%d",&newnode->id);

        if(newnode->id==-1)
        {
            free(newnode);
            break;
        }

        printf("Enter Maths Mark: ");
        scanf("%d",&newnode->Maths);

        printf("Enter Science Mark: ");
        scanf("%d",&newnode->Science);

        newnode->next=NULL;

        if(*head==NULL)
        {
            *head=newnode;
        }
        else
        {
            temp=*head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
        }
    }
}

void display(struct student *head)
{
    if(head==NULL)
    {
        printf("\nNo Records Found.\n");
        return;
    }

    printf("\nStudent Records\n");
    printf("------------------------------\n");

    while(head!=NULL)
    {
        printf("ID      : %d\n",head->id);
        printf("Maths   : %d\n",head->Maths);
        printf("Science : %d\n",head->Science);
        printf("------------------------------\n");
        head=head->next;
    }
}

int main()
{
    struct student *head=NULL;

    getdata(&head);

    display(head);

    return 0;
}
