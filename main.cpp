
#include <cassert>
#include <iostream>
#include "List/include/DoublyLinkedList.cpp"


int main(){
    DoublyLinkedList<int> list; create(list);

    insert(list, 1);
    cout << "Size of list: " << list.size << endl;
    destroy(list);

    return 0;
}