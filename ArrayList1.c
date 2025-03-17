#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LEN 10

typedef struct{
    int arr[LEN];
    int count;

}List;

void initList(List *list);
List createList();
void displayList(List list);
bool addItem(List *list, int item);
int removeItem(List *list, int item);
List getAllPrime(List *list);

int main(){
    List list = createList();

    List list2;
    initList(&list2);
    
    int length;
    printf("Enter length: "); scanf("%d", &length);
    
    for(int i=0 ; i<length; i++){
        int item;
        printf("\nEnter value: "); scanf("%d", &item);
        addItem(&list2, item);
        displayList(list2);
    }
    int item;
    printf("\nEnter item to be removed: "); scanf("%d", &item);

    int checker = removeItem(&list2, item);
    if(checker != -1){
        printf("Item found at index %d and is removed from list.\n", checker + 1);
        displayList(list2);
    }else{
        printf("Item not found in list");
    }

    List primeList = getAllPrime(&list2);
    printf("\nList of all prime numbers in list:\n");
    displayList(primeList);

    return 0;
}

void initList(List *list){
    list->count = 0;
}

List createList(){
    List x;
    x.count=0;
    return x;
}

void displayList(List list){
    printf("{");
    for(int i=0;i<list.count;i++){
        printf("%d", list.arr[i]);
        if(i != list.count - 1){
            printf(", ");
        }
    }
    printf("}");
}

bool addItem(List *list, int item){
    if(list->count >= LEN){
        return false;
    }
    int i;
    for(i = list->count;i>0 && list->arr[i - 1]>item;i--){
        list->arr[i] = list->arr[i-1];
    }
    list->arr[i] = item;
    list->count++;
    return true;
}

int removeItem(List *list, int item){
    for(int i=0;i<list->count;i++){
        if(list->arr[i] == item){
            for(int j=i;j<list->count-1;j++){
                list->arr[j]=list->arr[j+1];
            }
            list->count--;
            return i;
        }
    }
    return -1;
}

List getAllPrime(List *list){
    List x;
    x = createList();
   
    for(int i=0; i<list->count ; i++){
        int num = list->arr[i];
        int isPrime = 1;
        if(num<=1){
            continue;
        }

        for(int j=2; j*j <= num; j++){
            if(num%j == 0){
                isPrime = 0;
                break;
            }
        }
        if(isPrime){
            x.arr[x.count++] = num;
        }
    }
    return x;
}
