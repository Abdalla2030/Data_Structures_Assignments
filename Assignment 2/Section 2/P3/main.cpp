#include <bits/stdc++.h>
using namespace std;

template<class T>
struct node{
   T data;
   struct node<T> *next;
};

template<class T>
class Queue
{
private:
    node<T> *Front;
    node<T> *Rear;
    int Size;
public:
    Queue()
    {
        Front = NULL;
        Rear = NULL;
        Size = 0;
    }
    Queue(T value, int initial_size)
    {
        Front = NULL;
        Rear = NULL;
        Size = initial_size;
        for (int i=0 ; i < initial_size-1; i++)
        {
            node<T> *new_node;
            new_node = new node<T>;
            new_node->data = value;
            new_node->next = NULL;
            if (Front == NULL)
                Front = Rear = new_node;
            else
            {
                    Rear->next = new_node;
                    Rear = new_node;
            }
        }
    }
    bool isEmpty(){return (Front == NULL);}
    ~Queue()
    {
        node<T> *temp;
        temp = Front;
        while(temp != NULL)
        {
            node<T> *D = temp->next;
            delete temp;
            temp = D;
        }
        Front = Rear = NULL;
    }
    T& frontE()
    {
        return Front->data;
    }
    void pop()
    {
        if (isEmpty())
            return;
        node<T> *temp = Front;
        if (Front == Rear)
            Front = Rear = NULL;
        else
            Front = Front->next;
        delete temp;
        Size--;
    }
    void push (T value)
    {
        node<T> *new_node;
        new_node = new node<T>;
        new_node->data = value;
        new_node->next = NULL;
        if (isEmpty())
            Front = Rear = new_node;
        else
        {
            Rear->next = new_node;
            Rear = new_node;
        }
        Size++;
    }
    int getSize(){return Size;}
};

class QStack
{
Queue<int> q;
public:
    int top()
    {
        if (q.isEmpty())
            return -1;
        else
            return q.frontE();
    }
    void pop()
    {
        if (q.isEmpty())
            cout << "Stack is Empty.";
        else
            q.pop();
    }
    void push(int x)
    {
        int qsize = q.getSize();
        q.push(x);
        for (int i = 0; i<qsize; i++)
        {
            q.push(q.frontE());
            q.pop();
        }
    }
};
int main ()
{
    QStack qs;
    qs.push(50);
    qs.push(25);
    qs.push(80);
    qs.push(5);
    qs.push(20);
    cout << "Top of the QStack is: " << qs.top() << endl;
    qs.pop();
    qs.push(40);
    cout << "Top of the QStack is: "<< qs.top() << endl;
    return 0;
}
