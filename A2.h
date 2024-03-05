#include<iostream>
using namespace std;

template<typename T>
struct Node{
    T val;
    Node *next;
    Node(T _val);
};
template<typename S>
class SinglyLinkedList{
    private:
    //data members
    Node<S> *head;
    Node<S> *tail;
    size_t num_items;
    public:
    SinglyLinkedList(); 
    void push_front(Node<S> *v); 
    void push_back(Node<int> *v); 
    void pop_front();
    void pop_back();
    S front();
    S back();
    bool Empty();
    void insert(size_t index, const S& item);
    bool remove(size_t index);
    size_t find(const S& item);
    void Print();
};