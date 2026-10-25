#ifndef DOUBLY_LINKED_LIST

template<typename T>
struct Node{
    T value;
    Node<T> *next;
    Node<T> *prev;
};

template<typename T>
struct DoublyLinkedList{
    unsigned size;
    Node<T> *ini;
};

template<typename T>
void create(DoublyLinkedList<T> &list);

template<typename T>
void insert(DoublyLinkedList<T>& list, const T& value);

template<typename T>
void destroy(DoublyLinkedList<T> &list);
#endif