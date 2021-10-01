#include <bits/stdc++.h>
using namespace std;

template<class T>
struct node{
   T data;
   struct node<T> *next;
};

template<class T>
class LinkedList{
    private:
    node<T> *first, *last;
    int count;
    public:
    //initialize list
    LinkedList()
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }

    //insert at the end
    void push_back(const T&val)
    {
        node<T> *newNode;
        newNode = new node<T>;
        newNode->data = val;
        newNode->next = nullptr;
        if(first == nullptr)
        {
            first  = newNode;
            last = newNode;
        }
        else
            {
            last->next = newNode;
            last = newNode;
        }
        count++;
    }
    //insert at beginning
    void push_front(const T&val)
    {
        node<T> *newNode;
        newNode = new node<T>;
        newNode->data = val;
        newNode->next = nullptr;
        if(first == nullptr)
        {
            first  = newNode;
            last = newNode;
        }
        else
            {
           newNode->next = first;
           first = newNode;
        }
        count++;
    }

    //getfirst elemwnt
    T getFirst(){
        if(first == nullptr)
        {
            cerr<<"The list is empty"<<endl;
        }
        return first->data;
    }
    //get last element
    T getLast(){
        if(last == nullptr)
        {
            cerr<<"The list is empty"<<endl;
        }
        return last->data;
    }

   //delete first node
    void deleteFirst()
    {
        if(first == nullptr)
        {
            cerr<<"can not delete from an empty list"<<endl;
        }
        node<T> *temp;
        temp = new node<T>;
        temp = first;
        first = first->next;
        delete temp;
        count--;
    }

    //delete last node
    void deleteLast()
    {
        if(first == nullptr)
        {
            cerr<<"can not delete from an empty list"<<endl;
        }
        if(first->next == nullptr)
        {
            delete first;
        }
        node<T> *beforeLast;
        beforeLast = new node<T>;
        beforeLast = first;
        while(beforeLast->next->next != nullptr)
        {
            beforeLast = beforeLast->next;
        }
        delete beforeLast->next;
        beforeLast->next = nullptr;
        count--;
    }
    //print list
    void print()
    {
        if(first == nullptr)
        {
            cerr<<"can not display an empty list"<<endl;
        }
        node<T> *currentNode;
        currentNode = new node<T>;
        currentNode = first;
        while(currentNode != nullptr){
            cout<<currentNode->data<<"\n";
            currentNode = currentNode->next;
        }
    }
    //get size of the list
    int size()
    {
        return count;
    }
    //clear the list
    void clear()
    {
        if(first == nullptr){
            return;
        }
        if(first->next == nullptr){
            node<T> *temp;
            temp = new node<T>;
            temp = first;
            first = nullptr;
            last = nullptr;
            delete temp;
        }
        node<T> *temp;
        temp = new node<T>;
        while (first != nullptr){
            temp = first->next;
            delete first;
            first = temp;
        }
        last = nullptr;
        count =0;
}

//initialize list
    LinkedList(int size, const T &val)
    {
        first = nullptr;
        last = nullptr;
        count  = size;
        for(int i = 0; i < size; ++i){
            this->push_back(val);
        }

}

//copy constructor to avoid shallow copy
    LinkedList(const LinkedList<T>&obj){
        first = nullptr;
        node<T> *newNode;
        node<T> *current;
        if(first != nullptr){
            clear();
        }
        if(obj.first == nullptr){
            first = nullptr;
            last = nullptr;
            count = 0;
        }
        else{
            current = obj.first;
            count = obj.count;
            first = new node<T>;
            first->data = current->data;
            first->next = nullptr;
            last =  first;
            current = current->next;
            while(current != nullptr){
                newNode = new node<T>;
                newNode->data = current->data;
                newNode->next = nullptr;
                last->next = newNode;
                last = newNode;
                current = current->next;
            }
        }

    }

//overloaded assignment operator to avoid shallow copy
    const LinkedList<T> & operator = (const LinkedList<T>&obj){
        if(this != &obj){
            first = nullptr;
            node<T> *newNode;
            node<T> *current;
            if(first != nullptr){
                clear();
            }
            if(obj.first == nullptr){
                first = nullptr;
                last = nullptr;
                count = 0;
            }
            else{
                current = obj.first;
                count = obj.count;
                first = new node<T>;
                first->data = current->data;
                first->next = nullptr;
                last =  first;
                current = current->next;
                while(current != nullptr){
                    newNode = new node<T>;
                    newNode->data = current->data;
                    newNode->next = nullptr;
                    last->next = newNode;
                    last = newNode;
                    current = current->next;
                }
            }
        }
        return *this;
    }
~LinkedList()
    {
        clear();
        first = nullptr;
        last = nullptr;
        count = 0;
    }

};

template<class T>
class Stack{
private:
  LinkedList<T>list;
    int stack_size;
public:
    Stack(){
        stack_size = 0;
        list.clear();
    }
    Stack(int intial_size, const T& val){
        LinkedList<T>lls(intial_size,val);
        list = lls;
        stack_size = intial_size;
    }
    ~Stack(){
        list.clear();
        stack_size = 0;
    }
    const T top(){
        return list.getFirst();
    }
    void pop(){
        list.deleteFirst();
        stack_size--;
    }
    void push(const T& value){
        list.push_front(value);
        stack_size++;
    }
    bool isEmpty(){
        return (stack_size == 0);
    }
    int size(){
        return stack_size;
    }

};
int main() {
    freopen("input.txt","r",stdin);
    int t ; cin>>t;
    while(t--){
        Stack<char>delimiter;
        Stack<char>comment;
        string bracket;
        cin>>bracket;
        bool flag = true;

        for(int i = 0; i < (int)bracket.size(); ++i){

            char c = bracket[i];
            if((c == '(' || c == '[' || c == '{')  && (comment.isEmpty()))
            {
                delimiter.push(c);
            }
            else if (c == '/')
            {
                if (comment.isEmpty())
                {
                    if(bracket[i+1] == '*')
                    {
                        comment.push(c);
                        comment.push(bracket[i+1]);
                        i++;
                    }
                }
                else
                    {
                        if(comment.top() == c)
                        {
                            comment.pop();
                        }
                    else
                        {
                            flag = false;
                        }
                }
            }
            else if(c == ')' || c == ']' || c == '}')
            {
                if(!comment.isEmpty())
                {
                    continue;
                }
                else if(delimiter.isEmpty())
                {
                    flag = false;
                }
                else
                  {
                    if( (c == ')') && (delimiter.top() == '('))
                    {
                        delimiter.pop();
                    }
                    else if((c == ']') && (delimiter.top() == '['))
                    {
                        delimiter.pop();
                    }
                    else if((c == '}') && (delimiter.top() == '{'))
                    {
                        delimiter.pop();
                    }
                }
            }
            else if(c == '*')
            {
                if(bracket[i+1] == '/')
                {
                    comment.pop();
                }
            }
        }


        if((delimiter.isEmpty()) && (comment.isEmpty()&&flag))
        {
            cout<<"Valid"<<endl;
        }
        else
            {
            cout<<"Invalid"<<endl;
        }
    }

    return 0;
}
