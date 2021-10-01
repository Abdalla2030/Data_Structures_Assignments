//
// Created by Ahmed Essam Eldin on 6/4/2021.
//

#include <iostream>
#include <string>
using namespace std;
#ifndef ASSIGNMENT_2_LIST_H
#define ASSIGNMENT_2_LIST_H
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
    List();
    List(type value, int initial_size);
    ~List();
    int size();


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

        void operator++() {
            if (this->nod->next == NULL) {
                throw "error: this is the last element" ;
                return;
            }
            this->nod = nod->next;
        }
        void operator -- (){
            List<type>:: Iterator i;
            i.nod=this->head;
            i.head=this->head;
            if (this->head == this->nod ){
                cout<< "error: this is the first element" ;
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
    void insert(type value, Iterator position);
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
    List<type>& operator = (List<type> another_list);

    Iterator begin() {
        return Iterator(this->head,this->head);
    }

    Iterator end() {
        return Iterator(this->tail,this->head);
    }

};

#endif //ASSIGNMENT_2_MYLIST_H
