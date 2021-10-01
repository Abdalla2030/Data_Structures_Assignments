#include <iostream>
#include <string>
//#include "List.h"

using namespace std;
// Created by Ahmed Essam Eldin 20190050 on 5/6/2021.

template<class type>
struct node
{
    type data;
    node* next;
};

template<class type>
class List {
private:
    node<type> * head , *tail;
public:
    List(){
        head=NULL;
        tail=NULL;
    }

    List(type value, int initial_size){

        // all we need is to make head and tail in memory pointer to a node that has
        // its value to be "value" and next to be null
        node<type> *newNode=new node<type>;
        newNode->data=value;
        newNode->next=NULL;
        head=newNode;
        tail=newNode;
        newNode=NULL;       // make this node pointer to nothing
        for(int i=1; i<initial_size; i++){
            node<type> *tmp=new node<type>;
            tmp->data=value;
            tmp->next=NULL;
            tail->next=tmp;
            tail=tmp;
        }   // now head pointer to the first element and tail pointer to the last element
    }
    ~List(){

        while(head != tail){
            node<type> *cur=new node<type>;
            node<type> *pre=new node<type>;
            cur=head;
            while(cur->next!=NULL)
            {
                pre=cur;
                cur=cur->next;
            }
            delete cur;
            tail=pre;
            pre->next=NULL;
        }
        delete head;
        delete tail;

    }
    int size(){
        node<type> *tmp=new node<type>;
        tmp=head;
        int number=0;
        while(tmp!=NULL)
        {
            tmp=tmp->next;
            number++;
        }
        return number;
    }


    class Iterator {
    public:
        node<type> *nod;
        node<type> *head;
        Iterator(){
            nod=nullptr;
            head=nullptr;
        }
        Iterator(node<type> *Ptrnode,node<type> *h){
            nod=Ptrnode;
            head=h;
        }

        void operator++(int) {
            if (this->nod->next == NULL) {
                cout<< "error: this is the last element"<<endl ;
                return;
            }
            this->nod = nod->next;
        }
        void operator -- (){
            List<type>:: Iterator i;
            i.nod=this->head;
            i.head=this->head;
            if (this->head == this->nod ){
                cout<< "error: this is the first element"<<endl ;
                return;
            }
            else {
                while (i.nod->next != NULL ){
                    if(i.nod->next == this->nod){
                        this->nod = i.nod;
                        return;
                    }
                    i++;
                }
            }
        }
        type& operator*() const {
            return nod->data;
        }
        bool operator==(const Iterator& itr) const {
            return nod== itr.nod;
        }

        bool operator!=(const Iterator& itr) const {
            return nod != itr.nod;
        }

    };
    void insert(type value, Iterator position){
        node<type> *current=new node<type>;
        node<type> *previous=new node<type>;
        node<type> *tmp=new node<type>;
        tmp->data=value;
        current=this->head;
        previous= this->head;
        // this loop will make current node and iterartor pointer to the same node
        while (current != position.nod)
        {
            previous=current;
            current=current->next;
        }
        previous->next=tmp;
        tmp->next=current;
    }

    Iterator erase(Iterator position)
    {
        node<type> *previous=new node<type>;
        previous=this->head;
        while (previous->next != position.nod)
        {
            previous=previous->next;
        }
        if (previous->next==NULL){
            cout<< "position isn't valid";
            return --position;
        }
        previous->next=position.nod->next;
        position.nod->next=NULL;
        position.nod=previous->next;
        return position;
    }
    List<type>& operator = (List<type> another_list){
        Iterator itr =another_list.begin( );
        while(itr != another_list.end())
        {
            this->insert(*itr , itr);
            itr++;
        }
        return *this;
    }

    Iterator begin() {
        return Iterator(this->head,this->head);
    }

    Iterator end() {
        return Iterator(this->tail,this->head);
    }
    void push_back(type value)
    {
        node<type> *tmp=new node<type>;
        tmp->data=value;
        tmp->next=NULL;
        if(this->head==NULL)
        {
            this->head=tmp;
            this->tail=tmp;
            tmp=NULL;
        }
        else
        {
            this->tail->next=tmp;
            this->tail=tmp;
        }
    }

};


int main()
{

    List<int> l1(6,3);
    List<int> l2(5,4);

    List<int> ::Iterator itr2=l2.begin();
    l1.push_back(*itr2);
    do{
        itr2++;
        l1.push_back(*itr2);
    }while(itr2 != l2.end());
    List<int> ::Iterator itr1=l1.begin();
    cout<<*itr1<< " ";
    do
    {
        itr1++;
        cout<<*itr1<< " ";
    } while (itr1 != l1.end());
    cout<<endl;
    cout<<l1.size()<<endl;
    return 0;
}



