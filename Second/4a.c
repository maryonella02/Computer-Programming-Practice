/*
Design, Develop and Implement a menu driven Program in C for the following
operations on Binary Search Tree (BST) of Integers
*/
//tree gol

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node NODE;


NODE *insert(int item, NODE *root)
{
    NODE *temp,*current,*prev;
    temp=(NODE *)malloc(sizeof(NODE));
    temp->info=item;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(root==NULL)
        return temp;
    prev=NULL;
    current=root;
    while(current!=NULL)
        {//gaseste ultimul element
            prev=current;
            if(current->info < item )
                current=current->rlink;
            else
                current=current->llink;

        }
        //insereaza dupa valoare
        if(item < prev->info)
            prev->llink=temp;
        else
            prev->rlink=temp;
        return root;
}
NODE *construct_BST(NODE *root)
{
    int a,n,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements to be inserted in the tree\n");
    for (i=0;i<n;i++)
        {
            scanf("%d",&a);
            root=insert(a,root);
        }
        printf("Tree Constructed Successfully!!!!!!\n");
        return root;
}
void pre_order(NODE *root)
{
    if(root!=NULL)
        {
            printf("%d\t",root->info);
            pre_order(root->llink);
            pre_order(root->rlink);
        }
}

void inorder(NODE *root)
{
    if(root!=NULL)
        {
            inorder(root->llink);
            printf("%d\t",root->info);
            inorder(root->rlink);
        }
}

void post_order(NODE *root)
{
        if(root!=NULL)
            {
                post_order(root->llink);
                post_order(root->rlink);
                printf("%d\t",root->info);
            }
}
int search_element(NODE *root,int key)
{
    NODE *current;
    int n=0;
    current=root;
    if (current!=NULL)
        {
            if (key==current->info)
                return n=1;
            else if (key<current->info)
                return search_element(current->llink, key);
            else
                return search_element(current->rlink,key);
        }
        else
            return n;
}

NODE *minValueNode(NODE* node)
{
    NODE *current = node;
    while (current->llink != NULL)
            current = current->llink;
    return current;
}


NODE *delete_element(NODE *root,int key)
{// cauta node-ul
        if (root == NULL)
            return root;
        if (key < root->info)
            root->llink = delete_element(root->llink, key);
        else if (key > root->info)
            root->rlink = delete_element(root->rlink, key);
        else
            {
// node with only one child or no child
                if (root->llink == NULL)
                    {
                        NODE *temp = root->rlink;
                        free(root);
                        return temp;
                    }
                else if (root->rlink == NULL)
                    {
                        NODE *temp = root->llink;
                        free(root);
                        return temp;
                    }
// node with two children: Get the inorder successor (smallest
// in the right subtree)

                else
                {
                NODE *temp = minValueNode(root->rlink);
                root->info = temp->info;
                root->rlink = delete_element(root->rlink, temp->info);
                }
            }
        return root;
}

void main()
{
    int item,ch,key,n;
    NODE *root;
    root=NULL;
        while (1)
        {
            printf("\nEnter the choice\n1.ConstructBST\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search an Element\n6.Delete an Element\n7:Exit\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1: root=construct_BST(root);
                        break;
                case 2: pre_order(root);
                        break;
                case 3: inorder(root);
                        break;
                case 4: post_order(root);
                        break;
                case 5: if (root==NULL)
                            printf("List Empty\n");
                        else
                        {

                            printf("Enter the element\n");
                            scanf("%d",&key);
                            n=search_element(root,key);
                            if(n)
                                printf("Key found\n");
                            else
                                printf("Not found\n");
                        }
                        break;
                case 6:
                    if (root==NULL)
                        printf("List Empty\n");
                    else
                    {
                        printf("Enter the element\n");
                        scanf("%d",&key);
                        n=search_element(root,key);
                    if(n)
                        root=delete_element(root,key);
                    else
                        printf("Not found\n");
                    }
                    break;
                    case 7: exit(0);
                    default: printf("Wrong Choice\n");
            }
        }
}

/*
*/
