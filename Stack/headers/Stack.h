#pragma once 

template<typename T>
struct NodeStack{
    T value;
    NodeStack<T>* back;
};

template<typename T>
struct Stack{
    unsigned size;
    NodeStack<T> *top;
};

template<typename T>
void create(Stack<T> &stack);

template<typename T>
void push(Stack<T> &stack, const T& value);

template<typename T>
void pop(Stack<T> &stack);

template<typename T>
void destroy(Stack<T> &stack);