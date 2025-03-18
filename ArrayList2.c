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
    ArrayList list = createList(10);

    int length;
    printf("Enter length: "); scanf("%d", &length);
    
    for(int i=0 ; i<length; i++){
        int item;
        printf("\nEnter value: "); scanf("%d", &item);
        addElement(&list, item);
        displayList(&list);
    }
    while(1){
        int choice;
        printf("\n\nEnter Choice: \n1. Add Element \n2. Delete Element \n3. Get All Prime Factors\n0. Exit\n"); scanf("%d", &choice);
        if(choice == 1){
            int item;
            printf("\nEnter value to be added: "); scanf("%d", &item);
            addElement(&list, item);
            displayList(&list);
        }else if(choice == 2){
            int item1;
            printf("\nEnter item to be removed (first occurence only): "); scanf("%d", &item1);
            int checker = deleteElement(&list, item1);
            if(checker != -1){
                printf("Item found at index %d and is removed from list.\n", checker);
                displayList(&list);
            }else{
                printf("Item not found in list");
            }
        }else if(choice == 3){
            int elem;
            printf("\nEnter element to get all prime factors (in the list): "); scanf("%d", &elem);
            ArrayList primeList = getAllPrimeFactors(&list, elem);
            printf("\nList of all prime factors of %d in list:\n", elem);
            displayList(&primeList);
            printf("Updated list:\n");
            displayList(&list);
        }
        else if(choice == 0){
            break;
        }
    }
    return 0;
}

void initList(ArrayList *list, int init_length){
    list->arr = (int *)malloc(init_length * sizeof(int));
    list->count = 0;
    list->length = init_length;
}

ArrayList createList(int init_length){
    ArrayList list;
    initList(&list, init_length);
    return list;
}

void displayList(const ArrayList *list){
    printf("{");
    for(int i = 0; i < list->count; i++){
        printf("%d", list->arr[i]);
        if(i < list->count - 1){
            printf(", ");
        }
    }
    printf("}\n");
}

bool isEmpyt(const ArrayList *list){
    if(list->count == 0){
        return true;
    }
    return false;
}

bool isFull(const ArrayList *list){
    if(list->count == list->length){
        return true;
    }
    return false;
}

// bool addElement(ArrayList *list, int item){
//     if(isFull(list)){
//         return false;
//     }
//     list->arr[list->count++] = item;
//     return true;
// }
bool addElement(ArrayList *list, int item) {
    if (isFull(&list)) {
        int newLength = list->length * 2; 
        int *newArr = (int *)realloc(list->arr, newLength * sizeof(int));
        
        if (!newArr) {
            printf("Memory allocation failed!\n");
            return false;
        }

        list->arr = newArr;
        list->length = newLength;
    }
    int i;
    for(i = list->count;i>0 && list->arr[i - 1]>item;i--){
        list->arr[i] = list->arr[i-1];
    }
    list->arr[i] = item;
    list->count++;
    return true;
}
// int deleteElement(ArrayList *list, int index){
//     if(isEmpyt(list) || index < 0 || index >= list->count){
//         return -1;
//     }
//     int i;
//     int item = list->arr[index];
//     for(i=0; i < list->count - 1; i++){
//         list->arr[i] = list->arr[i + 1];
//     }
//     return i;
// }

int deleteElement(ArrayList *list, int elem) {
    for (int i = 0; i < list->count; i++) {
        if (list->arr[i] == elem) {
            for (int j = i; j < list->count - 1; j++) {
                list->arr[j] = list->arr[j + 1];
            }
            list->count--;
            return i;
        }
    }
    return -1;
}

// ArrayList getAllPrimeFactors(ArrayList *list, int elem) {
//     ArrayList primeFactors = createList(10);

//     for (int factor = 2; factor <= elem; factor++) {
//         while (elem % factor == 0) { 
//             elem /= factor;  
//             int index = deleteElement(list, factor);
//             if (index != -1) { 
//                 addElement(&primeFactors, factor);
//             }
//         }
//     }
//     return primeFactors; 
// }

ArrayList getAllPrimeFactors(ArrayList *list, int elem) {
    ArrayList primeFactors = createList(10);
    for (int factor = 2; factor <= elem; factor++) {
        while (elem % factor == 0) { 
            elem /= factor; 
            while (deleteElement(list, factor) != -1) { 
                addElement(&primeFactors, factor);
            }
        }
    }
    return primeFactors; 
}