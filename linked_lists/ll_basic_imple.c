#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node* Allocate(int value)
{
        struct Node *node = NULL;
        node = (struct Node*)malloc(sizeof(struct Node));
        node->data = value;
        node->next = NULL;
        return node;
}

void Insert_At_End_iteratively(struct Node* head, struct Node *new)
{
        while(head->next != NULL)
                head = head->next;

        head->next = new;
}
void Insert_At_End_recursively(struct Node* head, struct Node *new)
{
        if(head->next != NULL)
                Insert_At_End_recursively(head->next, new);
        else
                head->next = new;
}
void Insert_after(struct Node* head, struct Node *new, int x)
{
  if(head==NULL)
      printf("\n List doesnt contain data value %d !!\n", x);
  else if(head->data==x)
  {
      new->next = head->next;
      head->next = new;
    }
  else Insert_after(head->next,new,x);
}

void Insert_At_Front(struct Node** head_ref, struct Node *new)
{
        new->next = Allocate(0);
        new->next = *head_ref;
        *head_ref = new;
}

void Delete_first_node(struct Node* head, int x)
{
        if(head->data==x)
        {
          if(head->next!=NULL)
            *head = *(head->next);
          else
            printf("\nYOU ARE TRYING TO EMPTY THE LIST\nWHICH IS NOT POSSIBLE IN PROVIDED PROTOTYPE!!\n");
        }
        else
        {
          while(head->next!= NULL && head->next->data != x)
          {
                head = head->next;
          }
          if(head->next == NULL)
          {
                printf("No such element found!!");
          //      goto here;
                return;
          }
          if((head->next)->data == x)
                head->next = head->next->next;
        }
}

void Display_neighbour(struct Node *head, int x)
{
        struct Node *temp1,*temp2;
        int flag=0;
        temp1 = (struct Node*)malloc(sizeof(struct Node));
        temp2 = (struct Node*)malloc(sizeof(struct Node));
        temp1 = head;
        temp2 = head;
        if(head->data!=x)
        {
        flag=1;
        while(temp1->next!=NULL)
        {
        if((temp1->next)->data==x)
        {
        temp2 = temp1;
        flag=2;
        break;
        }
        temp1 = temp1->next;
        }
        }
        if(flag==0)
        if(head->next!=NULL)
            printf("\n Previous node=NULL\n Next node=%d\n",((head->next)->data));
        else
            printf("\n Previous node=NULL\n Next node=NULL\n");
        else if(flag==2)
        if((temp2->next)->next!=NULL)
          printf("\n Previous node=%d\n Next node=%d\n", temp2->data, ((temp2->next)->next)->data);
        else
          printf("\n Previous node=%d\n Next node=NULL\n", temp2->data);
        else
          printf("\n List doesnt contain data value %d !!\n", x);
}

void Delete_last_node(struct Node* head,int x)
{
        struct Node *temp1,*temp2;
        int flag=0;
        temp1 = (struct Node*)malloc(sizeof(struct Node));
        temp2 = (struct Node*)malloc(sizeof(struct Node));
        temp1 = head;
        temp2 = head;
        if(temp1->data==x)
          flag=1;
                
        while(temp1->next!=NULL)
        {
          if((temp1->next)->data==x)
          {
            temp2 = temp1;
            flag=2;
          }
          temp1 = temp1->next;
        }
                  
        if(temp2==head && flag==0)
        printf("\n List doesnt contain data value %d !!\n", x);
        else if(flag==1)
        {
          if(head->next != NULL)
            *head = *(temp2->next);
          else
            printf("\nYOU ARE TRYING TO EMPTY THE LIST\nWHICH IS NOT POSSIBLE IN PROVIDED PROTOTYPE!!\n");
        }
        else
        {
        temp2->next = (temp2->next)->next;
        }
}
void Display_all_elements(struct Node *head)
{
        printf("CURRENTLY LIST : ");
        while(head->next != NULL)
        {
                printf("%d -> ", head->data);
                head = head->next;
        }
        printf("%d", head->data);
        printf("\n");
}


int main()
{
//        printf("IMPORTANT NOTE : To quit the program at any instance use the key combination \"Ctrl + C\"");
        struct Node *head = NULL;
        struct Node *new = NULL;
        int value = 0;
        int known_value;
while(1)
{
printf("\tOPTIONS: \n");
printf("\t1. Insert an element at front\n");
printf("\t2. Insert an element at end iteratively\n");
printf("\t3. Insert an element at end recursively\n");
printf("\t4. Insert an element after a known element\n");
printf("\t5. Delete the first element with known value\n");
printf("\t6. Delete the last element with know value\n");
printf("\t7. Display the neighbourhood of a known element\n");
printf("\tCHOICE : ");
int choice;
scanf("%d", &choice);
if(choice <= 4 && choice >= 0)
{
        printf("Enter the value of new node : ");
        scanf("%d", &value);
        if(head == NULL)
            head = Allocate(value);
        else
            new = Allocate(value);
}
switch(choice)
{
case 1: if(new!=NULL)
        Insert_At_Front(&head, new);
        break;

case 2: if(new!=NULL)
        Insert_At_End_iteratively(head, new);
        break;

case 3: if(new!=NULL)
        Insert_At_End_recursively(head, new);
        break;

case 4: if(new!=NULL)
        printf("Enter the known value : ");
        scanf("%d", &known_value);
        Insert_after(head, new, known_value);
        break;

case 5:
        printf("Enter the value to be deleted : ");
        scanf("%d", &known_value);
        Delete_first_node(head, known_value);
        break;

case 6:
        printf("Enter the value to be deleted : ");
        scanf("%d", &known_value);
        Delete_last_node(head, known_value);
        break;

case 7:
        printf("Enter the known value : ");
        scanf("%d", &known_value);
        Display_neighbour(head, known_value);
        break;

default:
        printf("Invalid input please try again...");
}
  Display_all_elements(head);
}
        printf("\n");
        return 0;
}


