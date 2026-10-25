#include <iostream>
#include "../headers/List.h"

template<typename T>
void create(LinkedList<T> &list)
{
    list.ini = NULL;
    list.size = 0;
};

template<typename T>
void insert(LinkedList<T> &list, T value)
{
    Node<T> *node = new Node<T>();
    node->next = NULL;
    node->value = value;

    if(list.ini == NULL) list.ini = node;
    else{
        Node<T> *aux = list.ini;
        while (aux->next != NULL){
            aux = aux->next;
        }

        aux->next = node;
    }

    list.size++;
}

template<typename T>
void print(const LinkedList<T> &list)
{
    for(const Node<T> *aux = list.ini; aux != NULL; aux = aux->next)
    {
        std::cout << aux->value << " ";
    }
}

template<typename T>
bool validateSize(const LinkedList<T> &list)
{
    size_t i = 0;
    Node<T> *aux = list.ini;

    while(aux != NULL) {
        aux=aux->next;
        i++;
    }
    
    return i == list.size;
}

template<typename T>
void copy(LinkedList<T> &dest, LinkedList<T> &src)
{
    if(&dest == &src) return;
    
    for(Node<T> *aux = src.ini; aux != NULL; aux = aux->next)
    {
        insert(dest, aux->value);
    }
}

template<typename T>
void destroy(LinkedList<T> &list)
{
    if(list.ini != NULL)
    {
        while(list.ini != NULL)
        {
            Node<T> *tmp = list.ini;
            list.ini = list.ini->next;
            delete(tmp);
        }
        list.ini = NULL;
        list.size = 0;
    }
}

template<typename T>
void remove(LinkedList<T> &list, int index)
{
    if(index < 0 || index >= list.size) return;

    if(index == 0)
    {
        auto tmp = list.ini;
        list.ini = tmp->next;
        delete(tmp);

        list.size--;
    }else{
        auto *aux = list.ini;
        Node<T> *prev = NULL;
        size_t i = 0;

        while (aux->next != NULL && i != index){
            prev = aux;
            aux = aux->next; i++;
        }

        if(aux != NULL && validateSize(list))
        {
            auto tmp = aux;
            prev->next = aux->next;
            delete(tmp);

            list.size--;
        }
    }
}

template<typename T>
void removeFirst(LinkedList<T> &list)
{
    remove(list, 0);
}

template<typename T>
void removeLast(LinkedList<T> &list)
{
    remove(list, list.size-1);
}

template<typename T>
int indexOf(const LinkedList<T> &list, const T &value)
{
    const auto *aux = list.ini;
    int i = 0;

    while(aux != NULL){
        if(value == aux->value) return i;
        i++;
        aux = aux->next;
    }

    return -1;
}

template<typename T>
bool contains(const LinkedList<T> &list, const T &value){
    return indexOf(list, value) != -1;
}

template<typename T>
void insertAt(LinkedList<T> &list, const T &value, int index){
    if(index < 0 || index > list.size) return;

    Node<T> *newNode = new Node<T>();
    newNode->value = value;

    if(index == 0)
    {
        newNode->next = list.ini;
        list.ini = newNode;
    }else{
        auto *aux = list.ini;
        Node<T> *prev = NULL;
        int i = 0;

        while(aux != NULL && i != index)
        {
            i++;
            prev = aux;
            aux = aux->next;
        }

        prev->next = newNode;
        newNode->next = aux;
    }

    list.size++;
}

template<typename T>
T* getAt(LinkedList<T>& list, int index)
{
    if(index < 0 || index >= list.size) return NULL;

    auto *aux = list.ini;
    int i = 0;
    while(aux != NULL && i != index){
        i++;
        aux = aux->next;
    }

    return &aux->value;
}

template<typename T>
void reverse(LinkedList<T>& list)
{
    Node<T> *prev = NULL;
    Node<T> *current = list.ini;
    while(current != NULL)
    {
        Node<T> *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list.ini = prev;
}

template<typename T>
bool hasCycle(const LinkedList<T>& list)
{
    const Node<T> *slow = list.ini, *fast = list.ini;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }

    return false;

}

template<typename T>
void insertCircular(LinkedList<T>& list, const T& value)
{
    Node<T> *newNode = new Node<T>();
    newNode->value = value;

    if(list.size == 0){
        list.ini = newNode;
        newNode->next = list.ini;
    }else{
        Node<T> *aux = list.ini;

        do{
            aux = aux->next;
        }while(aux->next != list.ini);

        
        aux->next = newNode;
        newNode->next = list.ini;
        
    }

    list.size++;
    
}

template<typename T>
void removeCircular(LinkedList<T>& list, int index)
{
    if(list.size == 0) return;
    if(index < 0 || index >= list.size) return;

    if(list.size == 1){
        delete(list.ini);
        list.ini = NULL;
    }else if(index == 0){
        auto *tmp = list.ini;
        
        while(tmp->next != list.ini){
            tmp = tmp->next;
        }

        tmp->next = list.ini->next;
        tmp = list.ini;
        list.ini = tmp->next;

        delete(tmp);
    }else if(index == list.size - 1){
        auto *last = list.ini;
        Node<T> *prev = NULL;

        while(last->next != list.ini){
            prev = last;
            last = last->next;
        }

        prev->next = list.ini;
        delete(last);
    }else{
        auto *tmp = list.ini;
        Node<T> *prev = NULL;

        int i = 0;
        while(i != index){
            prev = tmp;
            tmp = tmp->next;
            i++;
        }

        prev->next = tmp->next;
        delete(tmp);
    }

    list.size--;
}

template<typename T>
void destroyCircular(LinkedList<T> &list){
    if(list.size == 0) return;

    if(list.size == 1){
        delete(list.ini);
    }else{
        auto *tmp = list.ini;

        for(int i = 0; i < list.size; i++){
            auto *prev = tmp;
            tmp = tmp->next;

            delete(prev);
        }
    }

    list.ini = NULL; list.size = 0;
}

template<typename T>
T* josephus(LinkedList<T>& list, unsigned k){
    if(k < 1) return nullptr;
    if(list.size == 0) return nullptr;

    Node<T> *current = list.ini, *prev = list.ini;

    do{
        prev = prev->next;
    }while(prev->next != list.ini);

    while(list.size != 1)
    {
        for(auto i = 0; i<k-1; i++){
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        
        if(current == list.ini)
            list.ini = prev->next;

        delete(current);

        current = prev->next;
        list.size--;
        
    }

    return &current->value;
}