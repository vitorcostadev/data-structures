#ifndef LIST_H

template<typename T>
struct Node{
    T value;
    Node *next;
};

template<typename T>
struct LinkedList{
    unsigned size;
    Node<T> *ini;
};

template<typename T>
void create(LinkedList<T> &list);

template<typename T>
void insert(LinkedList<T> &list, T value);

template<typename T>
void print(const LinkedList<T> &list);

template<typename T>
bool validateSize(const LinkedList<T> &list);

template<typename T>
void copy(LinkedList<T> &dest, LinkedList<T> &src);

template<typename T>
void destroy(LinkedList<T> &list);

template<typename T>
void remove(LinkedList<T> &list, int index);

template<typename T>
void removeFirst(LinkedList<T> &list);

template<typename T>
void removeLast(LinkedList<T> &list);

template<typename T>
int indexOf(const LinkedList<T> &list, const T &value);

template<typename T>
bool contains(const LinkedList<T> &list, const T &value);

template<typename T>
void insertAt(LinkedList<T> &list, const T &value, int index);

template<typename T>
T* getAt(LinkedList<T>& list, int index);

template<typename T>
void reverse(LinkedList<T>& list);

template<typename T>
bool hasCycle(const LinkedList<T>& list);

template<typename T>
void insertCircular(LinkedList<T>& list, const T& value);

template<typename T>
void removeCircular(LinkedList<T>& list, int index);

template<typename T>
void destroyCircular(LinkedList<T> &list);

template<typename T>
T* josephus(LinkedList<T>& list, unsigned k);
#endif