#include<iostream>
#include<stdint.h>
using namespace std;

#define MAX 10

class PriorityQueue
{
    //private by default
    int m_arr[MAX][2];
    int m_size;       //points to first unfilled member of the array
    int priority;
    
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
        for(int i = 0; i < m_size; i++){
            m_arr[i][0] = m_arr[i+1][0];
            m_arr[i][1] = m_arr[i+1][1];
	}
        m_arr[m_size][0] = 0;
        m_arr[m_size][1] = 0;
    }

public:
    void reset()
    {
        for(int i = 0; i < MAX; i++){
            m_arr[i][0] = 0;
            m_arr[i][1] = 0;
	}
        m_size = -1;
    }
    void enqueue(int data, int priority)
    {
        if(is_full())
            return;
        m_arr[++m_size][0] = data;
        m_arr[m_size][1] = priority;
    }

    int *dequeue()
    {
        if(m_arr < 0)
            return nullptr;
        static int temp[2] = {m_arr[0][0], m_arr[0][1]};
        leftRotate();
        m_size--;
        return temp;
    }

    int *front()
    {
        return m_arr[0];
    }

    int *rear()
    {
        return m_arr[m_size];
    }

    void print()
    {
	cout<<"( ";
        for(int i = 0; i <= m_size; i++)
	{
	    cout<<m_arr[i][0]<<" : "<<m_arr[i][1]<<",";
	}
        cout<<")\n";
    }
};

int main()
{
    PriorityQueue queue;
    queue.reset();
    //cout<<"1";
    queue.enqueue(10,0);
    queue.enqueue(20,2);
    queue.enqueue(30,1);
    queue.enqueue(40,0);
    queue.print();
    //cout<<"2";
    cout<<"Front item is : "<<*(queue.front())<<":"<<*(queue.front() + 1)<<'\n';
    cout<<"Rear item is : "<<*(queue.rear())<<":"<<*(queue.rear() + 1)<<'\n';
    
    return 0;
}
