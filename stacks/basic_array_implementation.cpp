#include<iostream>
using namespace std;

class Stack
{
    //private by default in class
    //public by default in struct
    int m_array[10];
    int m_size;
public :
    void reset()        //resets the size and array as zero
    {
        m_size = -1;     //resetting size as zero
        for(int i = 0; i < 10; i++)         //resetting the array of elements as zero
            m_array[i] = 0;
    }

    bool push(int n)
    {
        if(++m_size == 10)
            return false;
        m_array[m_size] = n;
        return true;
    }

    int pop()
    {
        if(m_size == -1)
            return -1;
        int ret_value = m_array[m_size];
        m_array[m_size--] = 0;
        return ret_value;
    }

    void print()
    {
        int i = -1;
        cout<<"( ";
        while(i != m_size)
            cout<<m_array[++i]<<" ";
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
                                     
    stack.pop();
    stack.pop();
                                             
    stack.print();
                                                 
    return 0;
}
