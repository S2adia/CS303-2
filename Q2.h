#include<iostream>
using namespace std;

namespace KW
{
    template<typename T>
    class Vector
    {
        private:
            size_t current_capacity;
            size_t num_items;
            T * the_data;

            void reserve(const size_t &new_capacity);
        public:
            Vector<T>() ;

            void push_back(const T& val);
            void pop_back();

            T& back();
            size_t size();
            
            bool empty();
            
    };

};


template<typename T>
class Vector_based_stack
{
    private:
    KW::Vector<T> container;
    public:
    void push(T item);
    void pop();
    T& top();
    bool empty();
    size_t size();
};