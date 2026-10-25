#include <iostream>
#include "../headers/DoublyLinkedList.h"

using namespace std;

template<typename T>
void create(DoublyLinkedList<T> &list){
    list.ini = NULL;
    list.size = 0;
}

template<typename T>
void insert(DoublyLinkedList<T>& list, const T& value)
{
    Node<T> *newNode = new Node<T>();
    newNode->value = value;
    newNode->prev = NULL;

    if(list.size == 0){
        list.ini = newNode;
        newNode->next = NULL;
    }else{
        list.ini->prev = newNode;
        newNode->next = list.ini;
        list.ini = newNode;
    }

    list.size++;
};

template<typename T>
void insertLast(DoublyLinkedList<T>& list, const T& value){
    Node<T> *newNode = new Node<T>();
    newNode->value = value;
    newNode->next = NULL;

    if(list.size == 0){
        list.ini = newNode;
        newNode->prev = NULL;
    }else{
        auto *tmp = list.ini;

        while(tmp->next != NULL){
            tmp = tmp->next;
        }

        tmp->next = newNode;
        newNode->prev = tmp;
    }

    list.size++;
}

template<typename T>
void destroy(DoublyLinkedList<T> &list){
    if(list.size == 0) return;

    while(list.ini != NULL){
        auto *tmp = list.ini;
        list.ini = list.ini->next;

        delete(tmp->prev);
        delete(tmp->next);
    }

    list.size = 0;
}