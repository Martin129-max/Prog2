#include <stdio.h>
#include <stdlib.h>
#include "myheader.h"

void display(int arr[], int count){
    printf("{");
    for(int i=0;i<count;i++){
        printf("%d", arr[i]);
        if(i<count-1){
            printf(", ");
        }
    }
    printf("}\n");
}

bool insertFront(int arr[], int *count, int item){
    if(*count>=LENGTH){
        return false;
    }
    for(int i=*count;i>0;i--){
        arr[i] = arr[i-1];
    }
    arr[0]= item;
    (*count)++;
    return true;
}
bool insertRear(int arr[], int *count, int item){

    if(*count > LENGTH){
        return false;
    }

    arr[(*count)++] = item;

    return true;
}
bool insertAt(int arr[], int *count, int item, int pos){
    if(pos > *count){
        return false;
    }
    for(int i=*count;i>pos-1;i--){
            arr[i] = arr[i-1];
        }
    arr[pos - 1] = item;
    (*count)++;
    
    return true;
}
bool insertSorted(int arr[], int *count, int item){
    if(*count >= LENGTH){
        return false;
    }
    int i;
    for(i=*count;i>0 && arr[i-1] > item;i--){
        arr[i] = arr[i-1];
    }
    arr[i] = item;
    (*count)++;
    return true;
}
bool deleteFront(int arr[], int *count){
    for(int i=0;i<*count;++i){
        arr[i] = arr[i+1];
    }
    (*count)--;
    return true;
}
bool deleteRear(int arr[], int *count){
    if(*count > 0){
        (*count)--;
        return true;
    }
    return false;
}
bool deleteItem(int arr[], int *count, int item){
    if(*count >= LENGTH){
        return false;
    }
    for(int i=0;i<*count;i++){
        if(arr[i] == item){
            for(int j=i;j<*count-1;j++){
                arr[j]=arr[j+1];
            }
            (*count)--;
            return true;
        }
    }
    return false;
    
}
// bool deleteAllItem(int arr[], int *count, int item);
// bool isFound(int arr[], int count, int item);
