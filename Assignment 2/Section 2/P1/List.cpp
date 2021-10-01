//
// Created by oessa on 6/4/2021.
//

#include "List.h"

template<class type>
List<type>::List()
{
    head=NULL;
    tail=NULL;
}

template<class type>
List<type>::List(type value, int initial_size)
{

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
template<class type>
List<type>::~List(){

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
template<class type>
int List<type>::size()
{
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


template<class type>
void List<type>::insert(type value, List::Iterator position)
{
    node<type> *current=new node<type>;
    node<type> *previous=new node<type>;
    node<type> *tmp=new node<type>;
    tmp->data=value;
    current=this->head;
    // this loop will make current node and iterartor pointer to the same node
    while (current != position.nod)
    {
        previous=current;
        current=current->next;
    }
    previous->next=tmp;
    tmp->next=current;
}

template<class type>
List<type> &List<type>::operator=(List<type> another_list) {
    Iterator itr =another_list.begin( );
    while(itr != another_list.end())
    {
        this->insert(*itr , itr);
        itr++;
    }
    return *this;
}



