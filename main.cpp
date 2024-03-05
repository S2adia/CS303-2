#include<iostream>
using namespace std;
#include"A2.cpp"
int main(){
    SinglyLinkedList<int> *s = new SinglyLinkedList<int>();
    Node<int> *d = new Node<int>(10);
    Node<int> *d1 = new Node<int>(20);
    Node<int> *d3 = new Node<int>(30);
    Node<int> *d4 = new Node<int>(40);
    s->push_front(d1); //call function to add Node(d1) at the beginning of the list
    s->push_front(d); //call function to add Node(d) at the beginning of the list
    s->push_back(d3);//call function to add Node(d3) at the end of the list
    s->push_back(d4); //call function to add  Node(d4) at the end of the list
    s->pop_front(); //call function to remove the first node
    s->pop_back(); //call function to remove the first node
    s->front(); //call function to return the first item/head
    s->back(); //call function to return the last item/tail
    s->insert(0,40); //call function to insert an item (40) at an index (0)
    s->insert(1,50); //call function to insert an item(50) at an index (1)
    s->insert(24,60); //call function to insert an item(60) at an index (24)
    cout<<s->remove(0)<<endl; //call function to remove item at given index (0)
    cout<<s->remove(2)<<endl; //call function to remove item at given index (2)
    cout<<s->find(50)<<endl; //call function to find an item (50)
    cout<<s->find(70)<<endl; //call function to find an item (70)
    s->Print(); //call function to print the list
}
