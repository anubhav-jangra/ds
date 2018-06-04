#include<iostream>
#include<algorithm> //for swap
using namespace std;

//a basic node
struct StackNode
{
    int info;
    StackNode *next;
};

//to create a new node from dynamic memory
StackNode *NewNode(int data)
{
    StackNode *new_node;    //we create a new pointer to node rather than a node itself as it passes a lot thus 2byte for adress only
    new_node = new (nothrow) (StackNode);     //allocates some dynamic memory to new_node
    new_node -> info = data;
    new_node -> next = NULL;
    return new_node;
}

bool isEmpty(StackNode *temp)
{
    return (!temp);
}

void push(int data, StackNode *&head)
{
    StackNode *anode;
    anode = NewNode(data);
    anode -> next = head;
    head = anode;
}

int pop(StackNode *&head)
{
    int temp;
    temp = head -> info;
    delete head;
    head = head -> next;
    return temp;
}

int peek(StackNode *&head)
{
    cout<<'\n' <<head -> info<<'\n';
    return head->info;
}

void print(StackNode *&head)
{
    cout<<head -> info<<" ";
    if(head -> next == NULL)
        return;
    print(head -> next);
}

int main()
{
    StackNode *head = NULL;

    push(1,head);
    push(2,head);
    push(1,head);
    push(3,head);
    push(1,head);
    push(5,head);
    push(1,head);
    
    print(head);

    pop(head);
    peek(head);
    pop(head);
    print(head);

    cout<<endl;
    return 0;
}
