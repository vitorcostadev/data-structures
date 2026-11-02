
#include <cassert>
#include <iostream>
#include "List/include/DoublyLinkedList.cpp"
#include "Stack/include/Stack.cpp"
#include <vector>

using namespace std;

int soma(vector<int> &v, int i){
    if(i >= v.size()) return 0;
    return v[i] + soma(v, i + 1);
}

int binaryFind(vector<int> &v, int i, int ini, int end){
    if(ini > end) return -1;

    int medium = ini + (end - ini) / 2;
    if(v.at(medium) == i) return medium;
    if(v.at(medium) > i) return binaryFind(v, i, ini, medium - 1);
    return binaryFind(v, i, medium + 1, end);
}

int pesquisaBinaria(vector<int>  &v, int index){
    return binaryFind(v, index, 0, v.size() - 1);
}

int main(){
    vector<int> v;
    for(int i = 0; i<100; i++) v.push_back(i);
    cout << pesquisaBinaria(v, 99) << endl;

    return 0;
}