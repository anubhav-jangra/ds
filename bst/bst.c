// to create a bst

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct S_NODE{
    int data;
    struct S_NODE *left;
    struct S_NODE *right;
} Node;


int h = 0;      // height of tree

Node *allocate(int data)
{
    Node *node = (Node *) malloc (sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}
/*
void insert_element(Node **head, int data, Node *temp)
{
    static int abc = 2;         // transversal height
    if(*head == NULL)
    {
        h = 1;
        *head = allocate(data);
        return;
    }
    if(data <= temp->data)
    {
        if(temp->left != NULL)
        {
            abc++;
            insert_element(head, data,temp->left);
        }
        else
        {
            if(abc > h)
                h = abc;
            Node *new = allocate(data);
            temp -> left = new;
        }
    }
    else
    {
        if(temp->right != NULL)
        {
            insert_element(head, data, temp->right);
        }
        else
        {
            if(abc > h)
                h = abc;
            Node *new = allocate(data);
            temp -> right = new;
        }
    }
}
*/

Node* insert(Node* node, int key)
{
    if (node == NULL) return allocate(key);
 
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);   
 
    return node;
}
/*
void display(Node *head, Node *temp, int path[])
{
    static int x = 0, path_length = 0, z = 0; // transversal height
    //static int *path = (int *)malloc(pow(2, h) * (sizeof(int)));
    int y = pow(2, x);
    printf("y = %d\n", y);
    
    if(path_length == x)
    {
        if(temp)
            printf("%d ", temp->data);
        z++;
        if(z == y && ++x != h)
        {
            int path_new[(int)pow(2, h)];
            path_length = 0;
            z = 0;
            display(head, head, path_new);
        }
        x = 0;
        path_length = 0;
        z = 0;
        return;
    }

    if(temp->left != NULL)
    {
        path[path_length++] = 0;
        display(head, temp->left, path);
    }
    if(temp->right != NULL)
    {
        path[path_length++] = 1;
        display(head, temp->right, path);
    }
}
*/

void inorder(Node *head)
{
    if (head != NULL)
    {
        inorder(head->left);
        printf("%d \n", head->data);
        inorder(head->right);
    }
}
int main()
{
    Node *head = NULL;
    int choice, i;
    int path[(int)pow(2, h)];
    while(1)
    {
        //printf("h is -> %d\n", h);
        //if(head)
        //    printf("data in head is currently -> %d\n\n", head->data);
        printf("\t OPTIONS : \n");
        printf(" 1. Insert an element\n");
        printf(" 2. Display tree\n");
        printf(" CHOICE : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf(" Gimme a value : ");
                int data;
                scanf("%d", &data);
                if(head)
                    head = insert(head, data);
                else
                    insert(head, data);
                break;
            case 2:
                printf(" Level order transversal of tree is : ");
                //for(i = 0; i < pow(2, h); i++)
                //    path[i] = 0;
                //display(head, head, path);
                inorder(head);
                printf("\n\n");
                break;
            default :
                printf("~~~WRONG INPUT~~~\n");
        }
    }
    printf("\n");
    return 0;
}
