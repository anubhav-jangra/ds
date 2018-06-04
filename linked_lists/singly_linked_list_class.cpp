// singly linked list
#include<bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int m_data;
        SinglyLinkedListNode *m_next;

        SinglyLinkedListNode(int node_data){
            this->m_data = node_data;
            this->m_next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *m_head;
        SinglyLinkedListNode *m_tail;

        SinglyLinkedList() {
            this->m_head = nullptr;
            this->m_tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode *node = SinglyLinkedListNode(node_data);

            if(!this->m_head) {
                this->m_head = node;
            } else {
                this->m_tail->m_next = node;
            }
            this->m_tail = node;
        }
        void printLinkedList(SinglyLinkedListNode* head) {
            while(head != nullptr)
            {
                cout<< head->m_data <<endl;
                head = head->m_next;
            }
        }

        void insert_at_front(int node_data) {
            SinglyLinkedListNode *node = SinglyLinkedListNode(node_data);
            node -> m_next = this -> m_head;
            m_head = node;
        }

        SinglyLinkedListNode* insertNodeAtPosition(int data, int position) {
            if(position == 0)
            {
                this->insert_at_front(data);
            }
            SinglyLinkedListNode *node = new SinglyLinkedListNode(data), *temp = m_head;
            int counter = 0;
            while(counter + 1 != position)
            {
                temp = temp -> next;
                counter++;
            }
            node -> next = temp -> next;
            temp -> next = node;
        }
        SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    SinglyLinkedListNode *temp = head;
    if(position == 0)
    {
        head = head -> next;
        free(temp);
        return head;
    }
    int counter = 0;
    while(counter + 1 != position)
    {
        temp = temp -> next;
        counter++;
    }
    SinglyLinkedListNode *temp1 = temp -> next;
    temp -> next = temp1 -> next;
    free(temp1);
    return head;
}
        void reversePrint(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *temp1, *temp2 = head;
    int counter = 1;
    while(temp2 -> next != nullptr){
        temp2 = temp2 -> next;
        counter++;
    }
    // cout<<"Counter is -> "<<counter<<endl;
    while(counter != 0)
    {
        temp1 = head;
        for(int i = 1; i < counter; i++)
            temp1 = temp1 -> next;
        cout<<temp1 -> data<<endl;
        counter--;
    }
        }

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *temp1 = head, *temp2 = head -> next;
    head = nullptr;
    while(temp2 != nullptr)
    {
        temp1 -> next = head;
        head = temp1;
        temp1 = temp2;
        temp2 = temp2 -> next;
    }
    temp1 -> next = head;
    head = temp1;
    return head;
}

bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    while(head1 != nullptr && head2 != nullptr)
    {
        if(head1 -> data != head2 -> data)
            return false;
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    if(head1 == nullptr && head2 != nullptr)
        return false;
    else if(head1 != nullptr && head2 == nullptr)
        return false;
    else 
        return true;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *head;
    if(head1 == nullptr)
        return head2;
    else if(head2 == nullptr)
        return head1;
    else {
        if(head1 -> data > head2 -> data) {
            head = head2;
            head2 = head2->next;
        } else {
            head = head1;
            head1 = head1->next;
        }
    }
    SinglyLinkedListNode *temp = head;
    while(head1 != nullptr && head2 != nullptr)
    {
        if(head1 -> data > head2 -> data) {
            temp -> next = head2;
            temp = temp -> next;
            head2 = head2 -> next;
        } else {
            temp -> next = head1;
            temp = temp -> next;
            head1 = head1 -> next;
        }
    }
    if(head1 == nullptr)
        temp -> next = head2;
    else
        temp -> next = head1;
    return head;
}

int getNode(SinglyLinkedListNode* head, int positionFromTail) {
SinglyLinkedListNode *temp1, *temp2 = head;
    int counter = 1;
    while(temp2 -> next != nullptr){
        temp2 = temp2 -> next;
        counter++;
    }
    temp1 = head;
    for(int i = 1; i < counter - positionFromTail; i++)
        temp1 = temp1 -> next;
    return temp1 -> data;
}
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    if(head == nullptr)
        return head;
    int counter1 = 0, counter2 = 0;
    SinglyLinkedListNode *temp1 = head, *temp2 = head;
    while(temp1 != nullptr)
    {
        // cout<<"temp1 -> data -->>"<<temp1 -> data<<endl;
        temp2 = temp1;
        counter2 = counter1 + 1;
        while(temp2 -> next != nullptr)
        {
            // cout<<"temp2 -> next -> data -->>"<<temp2 -> next -> data<<endl;
            if(temp2 -> next -> data == temp1 -> data)
            {
                // cout<<temp2 -> next -> data<<"===deleted==="<<endl;
                deleteNode(head, counter2);
                continue;
            }
            temp2 = temp2 -> next;
            counter2++;
        }
        temp1 = temp1 -> next;
        counter1++;
    }
    return head;
}
/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    Node *temp = headB;
    while(headA != nullptr)
    {
        headA = headA -> next;
        temp = headB;
        while(temp != nullptr)
        {
            if(temp == headA)
            {
                return temp -> data;
            }
        }
    }
}
};

void display_all_elements(Node *a_node)
{
    /*cout<<a_node -> data<<" ";
    if(a_node -> next == NULL)
        return;
    printList (a_node -> next);*/
    if(a_node == nullptr)
        cout<<"~~~~LIST IS EMPTY~~~~\n";
    else
    {
        while(a_node->next != NULL )
        {
            cout<<a_node->data<<" -> ";
            a_node = a_node->next;
        }
        cout<<a_node->data<<"\n";
    }
}

void insert_at_front(Node** head, int data)
{
    Node *ptr;
    ptr = new (nothrow) (Node);
    ptr->data = data;
    ptr->next = *head;
    *head = ptr;
}

void insert_at_end(Node* head, int data)
{
    Node *ptr;
    ptr = new (nothrow) (Node);
    ptr->next = NULL;
    ptr->data = data;
    while(head->next != NULL)
        head = head->next;
    head->next = ptr;
}

// finds the first element with value x and the enters a value just after that element
void insert_after(Node* head, int data, int x)
{
    while(head->data != x)
    {
        if(head->next != nullptr)
            head = head->next;
        else
        {
            printf("---Sorry dude, no such element in the list---\n");
            return;
        }
    }
    Node *ptr;
    ptr = new (nothrow) (Node);
    ptr->data = data;
    ptr->next = head->next;
    head->next = ptr;
}

// as the name suggests it deletes the first occurance of a node with vaue x
void delete_first(Node **head, int x)
{
    if((*head)->data == x)
    {
        *head = (*head)->next;
        return;
    }
    Node *temp_head = *head, *temp;
    while(temp_head->next->data != x)
    {
        if(temp_head->next != nullptr)
            temp_head = temp_head->next;
        else
        {
            cout<<"---Sorry dude, no such element in the list---\n";
            return;
        }
    }
    temp = temp_head->next;
    temp_head->next = temp->next;
    delete temp;
}

void delete_pos(Node **main_head, int pos)
{
    Node *head = *main_head, *temp;
    if(pos == 1)
    {
        *main_head = head->next;
        delete head;
        return;
    }

    for(int i = 1; i < pos - 1; i++)
    {
        if(head->next != nullptr)
            head = head->next;
        else
        {
            cout<<"---Oops, ya went out of bounds there brah---\n";
            return;
        }
    }
    temp = head->next;
    head->next = temp->next;
    delete temp;
}

int list_len(Node *head)
{
    // iterative method
    /*int count = 0;
    while(head != nullptr)
    {
        head = head->next;
        count++;
    }
    return count;*/

    // recursive method -1
    /*
    static int s_count;
    
    if(head == nullptr)
        return s_count;

    s_count++;

    return list_len(head->next);
    */

    // recursive method -2
    if(head == nullptr)
        return 0;

    return 1 + list_len(head->next);
}

void empty_list(Node *head)
{
    Node *current;

    while(head != nullptr)
    {
        current = head;
        head = head->next;
        delete current;
    }
}

bool detect_loop(Node *main_head)
{
    // my approch
    /*
    Node *head = main_head, *temp;
    int count1 = 0, count2 = 0;
    while(head != nullptr)
    {
        count2 = 0;
        temp = main_head;
        while(temp != head)
        {
            temp = temp->next;
            count2++;
        }

        if(count2 < count1)
            return true;

        head = head->next;
        count1++;
    }
    return false;
    */

    // floyd's cycle-finding algorithm
    Node *slow_p, *fast_p;
    fast_p = main_head;
    slow_p = main_head;

    while(slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        
        if(slow_p == fast_p)
            return 1;
    }
    return 0;

}

// better soln
static void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
/*
// my soln
Node *reverse_list(Node* head)
{
    Node *new_head = nullptr, *temp1, *temp2;
    if(head == nullptr)
        return new_head;
    if(head->next == nullptr)
        return head;
    while(head->next != nullptr) //yahan se dekhio
    {
        temp1 = head;
        
        while(temp1->next->next != nullptr)
        {
            temp1 = temp1->next;
        }
        if(new_head == nullptr)
        {
            new_head = temp1->next;
        }
        else
        {
            temp2 = new_head;
            while(temp2->next)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp1->next;
        }
        temp1->next = nullptr;
    }
    if(head)
    {
        temp2 = new_head;
        while(temp2->next)
        {
            temp2 = temp2->next;
        }
        temp2->next = head;
        head = nullptr;
    }
    return new_head;
}
*/

int main()
{
    Node *head = NULL, *ptr = NULL;
    int choice, data, cho, x;

    //uncomment the code below to get a looped list
    /*
    head = new (nothrow) (Node);
    head->data = 0;
    head->next = nullptr;

    for(int i = 0; i < 5; i++)
    {
        ptr = new (nothrow) (Node);
        ptr->data = i+1;
        ptr->next = head;
        head = ptr;
    }
    
    while(ptr->next != nullptr)
        ptr = ptr->next;
    ptr->next = head->next->next;
    */
    while(true)
    {
        cout<<"\t\tMENU : \n";
        cout<<"\t1. Enter an element\n";
        cout<<"\t2. Display all elements\n";
        cout<<"\t3. Delete first occurance\n";
        cout<<"\t4. Delete an element at given position\n";
        cout<<"\t5. Length of list\n";
        cout<<"\t6. Empty list\n";
        cout<<"\t7. Check looping\n";
        cout<<"\t8. Reverse List\n";
        cout<<"\t0. Quit\n";
        cout<<"Choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                if(head == NULL)
                {
                    cout<<"Gimme a head value : ";
                    ptr = new (nothrow) (Node);
                    ptr->next = NULL;
                    cin>>ptr->data;
                    head = ptr;
                    //head->next = NULL;
                }
                else
                {
                    cout<<"Gimme a value : ";
                    cin>>data;
                    here:
                    cout<<" Where would you wanna insert it!\n";
                    cout<<" 1. At front of list\n";
                    cout<<" 2. At end of list\n";
                    cout<<" 3. After a known element\n";
                    cout<<" CHOICE : ";
                    cin>>cho;
                    switch(cho)
                    {
                        case 1:
                            insert_at_front(&head, data);
                            break;
                        case 2:
                            insert_at_end(head, data);
                            break;
                        case 3:
                            printf(" Enter element after which you wanna enter : ");
                            cin>>x;
                            insert_after(head, data, x);
                            break;
                        default:
                            cout<<" Wrong Choice!!\n Try again!!";
                            goto here;
                    }
                }
                break;
            case 2:
                display_all_elements(head);
                break;
            case 3:
                cout<<" Enter the element you wanna delete : ";
                cin>>x;
                delete_first(&head, x);
                break;
            case 4:
                cout<<" Enter the position which you wanna delete (first index is 1): ";
                cin>>x;
                delete_pos(&head, x);
                break;
            case 5:
                cout<<"+++Length of list is -> "<<list_len(head)<<"+++\n";
                break;
            case 6:
                empty_list(head);
                head = nullptr;
                break;
            case 7:
                if(detect_loop(head))
                    cout<<"+++Yes there is a loopin' in the list+++\n";
                else
                    cout<<"+++No loopin' detected+++\n";
                break;
            case 8:
                //head = reverse_list(head);
                reverse(&head);
                break;
            case 0:
                goto end;
            default:
                cout<<"Wrong input!!\n";
        }
    }

    end:
    cout<<'\n';
    return 0;
}
