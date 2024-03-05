#include<iostream>
using namespace std;
#include"A2.h"

template<typename T>
//constructor for the Node structure
 Node<T> :: Node(T _val){ 
        val = _val; 
        next = nullptr; 
}
template<typename S>
//constructor for the singly linked list class
SinglyLinkedList<S> :: SinglyLinkedList(){
        head = nullptr; 
        tail = nullptr;
        num_items = 0; 
    }
    //function to add an element at the beginning of the linked list 
    template<typename S>
    void SinglyLinkedList<S> :: push_front(Node<S> *v){
        Node<S> *cur = head; 
        if(head==nullptr){ //check if the linked list is empty
            head = v; // set head and tail to the new Node(v)
            tail = v;
        }
        else{ // the linked list is not empty
            v->next = cur; //set the next pointer of v to the current head
            head = v; // v is the new head

        }
        num_items++; //incrementing the number of items 
        cout<<v->val<<" added at the beginning"<<endl;
    }
    //function to add element at the end of the linked list
    template<typename S>
    void SinglyLinkedList<S>:: push_back(Node<int> *v){
        if(head == nullptr){ //check if the linked list is empty
            head = v; // set head and tail to the new Node(v)
            tail = v;
            num_items++;
            return;
        }
        tail->next = v; // if not empty then the next pointer of current tail pointing to v
        tail = v; // new Node (v) is the current tail
        num_items++;
        cout<<v->val<<" added at the end"<<endl;
    }
    //function to delete the last element
    template<typename S>
    void SinglyLinkedList<S> :: pop_front(){
        if(head == nullptr){ //check if the linked list is empty
            return;
        }
        else{
            Node<S> *temp = head; 
            head = head->next; // new head is the next node of the previous head
            cout<<temp->val<<" popped from front"<<endl;
            delete temp; // deleting the variable storing previous head
            num_items--; //decrementing the number of items
            return;
        }
    }
     //function to delete from the end of the linked list
    template<typename S>
    void SinglyLinkedList<S> :: pop_back(){
        Node<S> *cur = head;
        if(head==nullptr){ //check if the linked list is empty
            return;
        }
        else if(head->next == nullptr){ // check if there's only one element in the linked list
            Node<S> *temp = head;
            head = nullptr;
            cout<<temp->val<<" popped"<<endl;
            delete temp;
            num_items--;
            return;
        }
        else{
            while(cur!=nullptr){
                if(cur->next->next == nullptr){
                    Node<S> *temp = cur->next;
                    tail = cur;
                    cout<<temp->val<<" popped from back"<<endl;
                    delete temp;
                    cur->next = nullptr;
                    num_items--;
                    return;
                }
                cur = cur->next;
                
            }
        }
    }
    //function to return the first element of the linked list
    template<typename S>
    S SinglyLinkedList<S> :: front(){
        if(head==nullptr){ //check if the linked list is empty
            return 0;
        }
        return head->val; //if not empty return the value of the head
    }
   
    //function to return the last element of the linked list
    template<typename S>
    S SinglyLinkedList<S> :: back(){
        if(tail==nullptr){ //check if the linked list is empty
            return 0;
        }
        return tail->val; //if not empty return the value of the tail
    }
    //function to check if the linked list is empty
    template<typename S>
    bool SinglyLinkedList<S> :: Empty(){
        if(num_items == 0){ 
            return true;
        }
        else{
            return false;
        }
    }
    //function to insert an item at a given index
    template<typename S>
    void SinglyLinkedList<S> :: insert(size_t index, const S& item){
        if(index>=num_items){ //check if the given index is beyond the end of the list
            Node<S> *temp = new Node<S>(item);
            tail->next = temp;
            tail = temp;
            num_items++;
            cout<<temp->val<<" added at index "<<num_items<<endl;

        }
        else{
            Node<S> *cur = head;
            size_t cnt = 0;
            Node<S> *temp = new Node<S>(item);
            if(index==0){ 
                push_front(temp); //call the push_front function to remove the first item of the list
                return;
            }
            while(cur!=nullptr){
                if(index == cnt+1){
                    temp->next = cur->next;
                    cur->next = temp;
                    num_items++;
                    cout<<temp->val<<" added at index "<<index<<endl;
                    return;
                }
                cur = cur->next;
                cnt++;
            }
        }
    }
    //function to remove the item of a given index 
    template<typename S>
    bool SinglyLinkedList<S> :: remove(size_t index){
       if(index>=num_items){  //check if the given index is beyond the end of the list
        return false; 
       }
       else if(index == 0){ // check if given index is 0, then remove the first item of the list
        Node<S> *temp = head;
        head = head->next;
        delete temp;
        num_items--;
        return true;
       }
       else{
        size_t cnt = 0;
        Node<S> *cur = head;
        while(cur!=nullptr){
                if(index == cnt+1){
                    Node<S> *temp = cur->next;
                    if(temp==tail){
                        tail = cur;
                    }
                    cur->next = temp->next;
                    delete temp;
                    num_items--;
                    return true;
                }
                cur = cur->next;
                cnt++;
            }
       }
       return true;
    }
    //function to find an item in the linked list
    template<typename S>
    size_t SinglyLinkedList<S> :: find(const S& item){
        Node<S> *cur = head;
        size_t cnt = 0;
        while(cur!=nullptr){
            if(cur->val == item){ //check if the given item matches with the current value of the list
                cout<<item<<" found at index ";
                return cnt; //if matches return the index number of the item
                cout<<endl;
            }
            cur = cur->next;
            cnt++;
        }
        cout<<item<<" cannot be found"<<endl;
        cout<<"Number of items: ";
        return num_items; //if the given item is not found return the number of items of the list
        cout<<endl;
    }
    //function to print the linked list
    template<typename S>
    void SinglyLinkedList<S> :: Print(){
        Node<S> *cur = head;
        cout<<"Final linked list: ";
        while(cur!=nullptr){
            cout<<cur->val<<" "; //printing the current value
            cur = cur->next; //set the current value to the next value of current value
        }
        cout<<endl;
    }
