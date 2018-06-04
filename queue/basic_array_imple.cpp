#include<iostream>
#include<stdint.h>
using namespace std;

#define MAX 10

class Queue
{
    //private by default
    int m_arr[MAX];
    int m_size;       //points to first unfilled member of the array
    
    bool is_full()
    {
        if(m_size == MAX)
            return true;
        return false;
    }

    void leftRotate()
    {
        //to convert a pointer type to simple int type
        //uintptr_t number = (uintptr_t)(end - arr[0]);
        for(int i = 0; i < m_size; i++)
            m_arr[i] = m_arr[i+1];
        m_arr[m_size] = 0;
    }

public:
    void reset()
    {
        for(int i = 0; i < MAX; i++)
            m_arr[i] = 0;
        m_size = -1;
    }
    void enqueue(int data)
    {
        if(is_full())
            return;
        m_arr[++m_size] = data;
    }

    int dequeue()
    {
        if(m_arr < 0)
            return -1;
        int temp = m_arr[0];
        leftRotate();
        m_size--;
        return temp;
    }

    int front()
    {
        return m_arr[0];
    }

    int rear()
    {
        return m_arr[m_size];
    }

    void print()
    {
        for(auto e : m_arr) cout<<e<<" ";
        cout<<"\n";
    }
};

int main()
{
    Queue queue;
    queue.reset();
    //cout<<"1";
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.print();
    //cout<<"2";
    cout<<"Front item is : "<<queue.front()<<'\n';
    cout<<"Rear item is : "<<queue.rear()<<'\n';
    
    return 0;
}
