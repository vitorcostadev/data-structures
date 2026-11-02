#include <iostream>
#include "../headers/Stack.h"

using namespace std;

template<typename T>
void create(Stack<T> &stack){
    stack.size = 0;
    stack.top = NULL;
}

template<typename T>
bool isEmpty(Stack<T> stack) {return stack.size == 0;}

template<typename T>
void push(Stack<T> &stack, const T& value)
{
    NodeStack<T>* node = new NodeStack<T>();
    node->value = value;
    node->back = stack.top;
    stack.top = node;

    stack.size++;
}

template<typename T>
void pop(Stack<T> &stack){
    if(isEmpty(stack)) return;

    auto *tmp = stack.top;
    stack.top = stack.top->back;

    delete(tmp);

    stack.size--;
}

template<typename T>
void destroy(Stack<T> &stack){
    while(stack.top != NULL){
        auto *tmp = stack.top;
        stack.top = stack.top->back;
        delete(tmp);
    }
    stack.size = 0;
    stack.top = NULL;
}

template<typename T>
T* get(Stack<T> stack, int index){
    if(isEmpty(stack)) return NULL;
    if(index < 0 || index >= stack.size) return NULL;

    auto *aux = stack.top;
    unsigned i = 0;
    while(aux != NULL && i != index){
        aux = aux->back;
        i++;
    }

    return &aux->value;
}