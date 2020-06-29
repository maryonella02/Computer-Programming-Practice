//empty linked list

#include<stdlib.h>
#include <stdio.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();


struct node
{
        int info;
        struct node *next;
};
struct node *start=NULL;
int main()
{
        int choice;
        while(1){

                printf("\n                MENU                             \n");
                printf("\n 1.Create     \n");
                printf("\n 2.Display    \n");
                printf("\n 3.Insert at the beginning    \n");
                printf("\n 4.Insert at the end  \n");
                printf("\n 5.Insert at specified position       \n");
                printf("\n 6.Delete from beginning      \n");
                printf("\n 7.Delete from the end        \n");
                printf("\n 8.Delete from specified position     \n");
                printf("\n 9.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3:
                                        insert_begin();
                                        break;
                        case 4:
                                        insert_end();
                                        break;
                        case 5:
                                        insert_pos();
                                        break;
                        case 6:
                                        delete_begin();
                                        break;
                        case 7:
                                        delete_end();
                                        break;
                        case 8:
                                        delete_pos();
                                        break;

                        case 9:
                                        exit(0);
                                        break;

                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}
void create()
{
        struct node *temp,*current;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                exit(0);
        }
        printf("\nEnter the data value for the node:\t");
        scanf("%d",&temp->info);
        temp->next=NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                current=start;
                while(current->next!=NULL)
                {
                        current=current->next;
                }
                current->next=temp;
        }
}
void display()
{
        struct node *current;
        if(start==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
                current=start;
                printf("\nThe List elements are:\n");
                while(current!=NULL)
                {
                        printf("%d\t",current->info );
                        current=current->next ;
                }
        }
}
void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->info);
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}
void insert_end()
{
        struct node *temp,*current;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\n Enter the data value for the node:\t" );
        scanf("%d",&temp->info );
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                current=start;
                while(current->next !=NULL)
                {
                        current=current->next ;
                }
                current->next =temp;
        }
}
void insert_pos()
{
        struct node *current,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
        printf("\nEnter the data value of the node:\t");
        scanf("%d",&temp->info) ;

        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,current=start;i<pos-1;i++) {
                        current=current->next;
                        if(current==NULL)
                        {
                                printf("\nPosition not found:[Handle with care]\n");
                                return;
                        }
                }
                temp->next =current->next ;
                current->next=temp;
        }
}
void delete_begin()
{
        struct node *current;
        if(current==NULL)
        {
                printf("\nList is Empty:\n");
                return;
        }
        else
        {
                current=start;
                start=start->next ;
                printf("\nThe deleted element is :%d\t",current->info);
                free(current);
        }
}
void delete_end()
{
        struct node *temp,*current;
        if(start==NULL)
        {
                printf("\nList is Empty:");
                exit(0);
        }
        else if(start->next ==NULL)
        {
                current=start;
                start=NULL;
                printf("\nThe deleted element is:%d\t",current->info);
                free(current);
        }
        else
        {
                current=start;
                while(current->next!=NULL)
                {
                        temp=current;
                        current=current->next;
                }
                temp->next=NULL;
                printf("\nThe deleted element is:%d\t",current->info);
                free(current);
        }
}
void delete_pos()
{
        int i,pos;
        struct node *temp,*current;
        if(start==NULL)
        {
                printf("\nThe List is Empty:\n");
                exit(0);
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:\t");
                scanf("%d",&pos);
                if(pos==0)
                {
                        current=start;
                        start=start->next ;
                        printf("\nThe deleted element is:%d\t",current->info  );
                        free(current);
                }
                else
                {
                        current=start;
                        for(i=0;i<pos;i++) {
                                temp=current;
                                current=current->next ;
                                if(current==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =current->next ;
                        printf("\nThe deleted element is:%d\t",current->info );
                        free(current);
                }
        }
}
