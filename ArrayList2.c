#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int *arr;
    int count;
    int length;
}ArrayList;

void initList(ArrayList *list, int init_length);
ArrayList createList(int init_length);
void displayList(const ArrayList *list);
bool isEmpyt(const ArrayList *list);
bool isFull(const ArrayList *list);
bool addElement(ArrayList *list, int item);
int deleteElement(ArrayList *list, int index);
ArrayList getAllPrimeFactors(ArrayList *list, int elem);

int main(){

}

void initList(ArrayList *list, int init_length){
    list->arr = (int *)malloc(init_length * sizeof(int));
    list->count = 0;
    list->length = init_length;
}

ArrayList createList(int init_length){
    ArrayList list;
    list.arr = (int *)malloc(init_length * sizeof(int));
    list.count = 0;
    list.length = init_length;
    return list;
}

void displayList(const ArrayList *list){
    printf("{");
    for(int i = 0; i < list->count; i++){
        printf("%d ", list->arr[i]);
        if(i < list->count - 1){
            printf(", ");
        }
    }
    printf("}\n");
}

bool isEmpyt(const ArrayList *list){
    return list->count == 0;
}

bool isFull(const ArrayList *list){
    return list->count == list->length;
}

bool addElement(ArrayList *list, int item){
    if(isFull(list)){
        return false;
    }
    list->arr[list->count++] = item;
    return true;
}

int deleteElement(ArrayList *list, int index){
    if(isEmpyt(list) || index < 0 || index >= list->count){
        return -1;
    }
    int i;
    int item = list->arr[index];
    for(i=0; i < list->count - 1; i++){
        list->arr[i] = list->arr[i + 1];
    }
    return i;
}

ArrayList getAllPrimeFactors(ArrayList *list, int elem){
    ArrayList primeFactors = createList(10);
    for(int i = 2; i <= elem; i++){
        while(elem % i == 0){
            addElement(&primeFactors, i);
            elem /= i;
        }
    }
    return primeFactors;
}