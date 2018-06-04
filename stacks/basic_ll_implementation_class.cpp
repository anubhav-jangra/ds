#include<iostream>
using namespace std;

struct StackNode
{
    int info;
    StackNode *next;
};

StackNode *NewNode(int data)
{
    StackNode *new_node;
    new_node = new (nothrow) StackNode;
    new_node -> info = data;
    new_node -> next = NULL;
    return new_node;
};

class Stack
{
    // by default private
    StackNode *head;
    bool isEmpty(StackNode *head)
    {
        return (!head);
    }

public:
    void reset()
    {
        head = NULL;
    }

    void push(int n)
    {
        StackNode *a_node = NewNode(n);
        a_node -> next = head;
        head = a_node;
    }

    int pop()
    {
        int temp = head -> info;
        if(isEmpty(head))
            return temp;
        delete head;
        head = head -> next;
        return temp;
    }

    int peek()
    {
        cout<<'\n'<<head -> info<<'\n';
        return head -> info;
    }

    void print()
    {
        StackNode *temp = head;
        cout<<"( ";
        while(head != NULL)
        {
            cout<<head -> info<<" ";
            head = head -> next;
        }
        head = temp;
        cout<<")\n";
    }
};

int main()
{
    Stack stack;
    stack.reset();
    stack.print();
              
    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();
    //stack.peek();

    stack.pop();
    stack.print();

    stack.pop();
    
    stack.print();

    cout<<'\n';
    return 0;
}
