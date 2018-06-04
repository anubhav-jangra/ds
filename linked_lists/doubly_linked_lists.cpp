#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
};

void insert_at_front(Node **head)
{
    Node *node;
    node = new (nothrow) (Node);
    node->next = nullptr;
    node->prev = nullptr;
    cout<<"Gimme a value : ";
    cin>>node->data;
    node->next = *head;
    (*head)->prev = node;
    *head = node;
}

void insert_after(Node *head)
{
    cout<<" Enter a known element : ";
    int x;
    cin>>x;
    while(head->data != x)
    {
	if(head->next != nullptr)
	    head = head->next;
    }
    if(head->next == nullptr && head->data != x)
    {
	cout<<" Sorry dude, no such element found.\n";
	return;
    }
    Node *ptr, *temp = head->next;
    ptr = new (nothrow) (Node);
    if(head->next == nullptr && head->data == x)
    {
	cout<<" Gimme the element value : ";
	cin>>ptr->data;
	head->next = ptr;
	ptr->prev = head;
	return;
    }
    cout<<" Gimme the element value : ";
    cin>>ptr->data;
    head->next = ptr;
    ptr->prev = head;
    temp->prev = ptr;
    ptr->next = temp;
}

void insert_at_end(Node *head)
{
    while(head->next != nullptr)
	head = head->next;
    cout<<" Gimme the element value : ";
    Node *ptr;
    ptr = new (nothrow) (Node);
    ptr->next = nullptr;
    cin>>ptr->data;
    head->next = ptr;
    ptr->prev = head;
}

void insert_before(Node **main_head)
{
    Node *head = *main_head, *ptr;
    ptr = new (nothrow) (Node);
    cout<<" Enter a known element : ";
    int x;
    cin>>x;
    if(head->data == x)
    {
	cout<<" Gimme the element value : ";
	cin>>ptr->data;
	ptr->next = head;
	(*main_head)->prev = ptr;
	*main_head = ptr;
	return;
    }
    while(head->data != x)
    {
	if(head->next != nullptr)
	    head = head->next;
    }
    if(head->next == nullptr && head->data != x)
    {
	cout<<" Sorry dude, no such element found.\n";
	return;
    }
    
    Node *temp = head->prev;
    cout<<" Gimme the element value : ";
    cin>>ptr->data;
    temp->next = ptr;
    ptr->prev = temp;
    head->prev = ptr;
    ptr->next = head;
}

void display_elements(Node *head)
{
    while(head->next != nullptr)
    {
	cout<<head->data<<" <-> ";
	head = head->next;
    }
    cout<<head->data<<"\n";
}

int main()
{
    Node *head=nullptr, *ptr;
    ptr = new (nothrow) (Node);
    int choice, cho;
    while(1)
    {
	cout<<"\t\tOPTIONS:\n\t1. Insert element.\n";
	cout<<"\t2. Display list.\n";
	cout<<"\t0. Quit.\n";
	cout<<" Choice : ";
	cin>>choice;

	switch(choice)
	{
	    case 1:
		if(head == nullptr)
		{
		    cout<<"Gimme a head value : ";
		    cin>>ptr->data;
		    head = ptr;
		}
		else
		{
		    cout<<" Where do you wanna enter the element?\n";
		    cout<<" 1. At front.\n";
		    cout<<" 2. After a known element.\n";
		    cout<<" 3. At end of list.\n";
		    cout<<" 4. Before a known element.\n";
		    cout<<" Choice : ";
		    cin>>cho;
		    switch(cho)
			{
			    case 1:
				insert_at_front(&head);
				break;
			    case 2:
			        insert_after(head);
				break;
			    case 3:
				insert_at_end(head);
				break;
			    case 4:
				insert_before(&head);
				break;
			}
		}
		break;
	    case 2:
		display_elements(head);
		break;
	    case 0:
		goto end;
		break;
	    default:
		cout<<" INVALID INPUT!!\n";
	}
    }
    end:
    cout<<"\n";
    return 0;
}
