#include <stdio.h>

int isArraySorted(int[], int);

int main(){
    int size;
    printf("Enter the size of the array: "); scanf("%d", &size);
    int arr[size];
    int i;
    printf("Enter the elements of the array:\n");
    for(i=0;i<size;i++){
        scanf("%d", &arr[i]);
    }
    // printf("%d", isArraySorted(arr, size));
    if(isArraySorted(arr,size)){
        printf("Sorted");
    }else{
        printf("Not Sorted");
    }
    
    return 0;
}

int isArraySorted(int arr[], int size){
 	int i;
    for(i=0;i<size;i++){
    	if(arr[i] == arr[i + 1]){
    		continue;
		}
        else if(arr[i] > arr[i + 1]){
            return 0;
        }
    }
    return 1;
}
