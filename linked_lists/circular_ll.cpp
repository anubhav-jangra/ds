#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void insert_at_end(Node **head, int data)
{
    Node *temp = *head, *ptr;
    ptr = new (nothrow) (Node);
    ptr->data = data;
    ptr->next = (*head);
    if(*head == nullptr)
    {
	ptr->next = ptr;
	*head = ptr;
	return;
    }
    while(temp->next != *head)
	temp = temp->next;
    temp->next = ptr;
    //cout<<"\n"<<ptr->data<<"\n";
}

void display_elements(Node *head)
{
    if(head == nullptr)
    {
	cout<<"~~~LIST IS EMPTY~~~\n";
	return;
    }

    Node *temp = head; 
    do
    {
	cout<<temp->data<<" -> ";
	temp = temp->next;
    }while(temp != head);
    cout<<"\n";
}

int main()
{
    int choice;
    Node *head=nullptr;
    while(true)
    {
	cout<<"\tOPTIONS:\n";
	cout<<" 1. Insert an element\n";
	cout<<" 2. Display content\n";
	cout<<" CHOICE : ";
	cin>>choice;
	switch(choice)
        {
		case 1:
		    cout<<" Gimme a value : ";
		    int data;
		    cin>>data;
		    insert_at_end(&head, data);
		    break;
		case 2:
		    display_elements(head);
		    break;
		default:
		    cout<<"Wrong choice!! try again\n";
	}
    }
    cout<<"\n";
    return 0;
}
