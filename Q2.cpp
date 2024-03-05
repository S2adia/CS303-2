#include<iostream>
using namespace std;
#include"Q2.h"
template<typename T>
void KW:: Vector<T>::reserve(const size_t &new_capacity){
    current_capacity = new_capacity;
    T * new_data = new T[current_capacity];
    for(size_t i = 0; i<num_items;i++)
    {
        new_data[i] = the_data[i];
    }
    delete the_data;
    the_data = new_data;
}
template<typename T>
KW::Vector<T> :: Vector(){ //constructor
    current_capacity = 10;
    the_data = new T[10];
    num_items = 0;
    } 

template<typename T>
void KW:: Vector<T>:: push_back(const T& val){ //function to add element at the front 
    if(num_items == current_capacity) //check if the number of items equals the capacity of the vector
    {
        reserve(2*current_capacity); // if yes call reserve function to double the size
    } 
    the_data[num_items] = val;
    num_items++; //increment number of items 
}

template<typename T>
void KW:: Vector<T>:: pop_back(){ //function to add element at the end 
    if(num_items > 0) //check if the vector is not empty
    num_items--; //decrement number of items 
}

template<typename T>
T&  KW:: Vector<T>::back(){ //function to return the last element
    return the_data[num_items-1];
    }

template<typename T>
size_t  KW:: Vector<T>::size() //function to return the size of the vector
    {
    return num_items;
    }

template<typename T>
bool KW:: Vector<T>::empty(){ //function to check if the vector is empty
    return num_items == 0;
    }
//implementing stack using vector
template<typename T>
bool Vector_based_stack<T>::empty() //check if stack's empty
    {
        return container.empty();
    }

template<typename T>
void Vector_based_stack<T>:: push(T item) //add an element onto the stack
    {
        container.push_back(item); 
    }

template<typename T>
void Vector_based_stack<T>:: pop() //remove an element
    {
        container.pop_back(); 
    }

template<typename T>
T& Vector_based_stack<T>:: top() //find thr top of stack
    {
        return container.back(); 
    }

template<typename T>
    size_t Vector_based_stack<T>:: size() //return the size of the stack
    {
        return container.size();
    }


