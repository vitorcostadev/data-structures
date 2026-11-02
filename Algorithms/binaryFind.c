#include <stdio.h>

int binaryFind(int values[], int index, int ini, int end){
    if(ini > end) return -1;

    int medium = ini + (end - ini) / 2;
    if(values[medium] == index) return medium;
    if(values[medium] < index) return binaryFind(values, index, medium - 1, end);
    return binaryFind(values, index, ini, medium + 1);
}

int binarySearch(int values[], int index, int size){
    return binaryFind(values, index, 0, size - 1);
}

int main(void){
    int v[] = {1,2,3,4,5,6,7,8,9};
    int b = binarySearch(v, 5, 9);
    printf("%d", b);
    return 0;
}