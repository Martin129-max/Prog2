#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define DELI -101

void display(int arr[]);
int *getPositive(int original[]);
int *addedArray(int a1[], int a2[]);
int getCount(int arr[]);
int *getPositiveWithCount(int arr[], int n, int *count);

int main(){
int myArray[MAX] = {-1, 4, 5, 2, -7, DELI};
int *pos;
int *add;
printf("Original: ");
display(myArray);
printf("Positive: ");
pos = getPositive(myArray);
display(pos);
printf("Added: ");
add = addedArray(myArray, pos);
display(add);
free(pos);
return 0;
}

void display(int arr[]){
int i;
printf("{");
for(i=0; arr[i] != DELI; ++i){
printf("%d", arr[i]);
if(arr[i+1] != DELI){
printf(", ");
}
}
printf("}\n");
}

int *getPositive(int original[]){
int i;
int temp[MAX];
int count = 0;
for(i=0; original[i] != DELI; ++i){
if(original[i] > 0){
temp[count++] = original[i];
}
}
temp[count++] = DELI;

int *positive = (int*)malloc(sizeof(int) * count);

memcpy(positive, temp, sizeof(int) * count);

return positive;
}

//int *addedArray(int a1[], int a2[]){
// int i, count=0;
// int temp[MAX];
//
// for(i=0; a1[i] != DELI; ++i){
// temp[count++] = a1[i];
// }
//
// for(i=0; a2[i] != DELI; ++i){
// temp[count++] = a2[i];
// }
// temp[count++] = DELI;
// int *positive = (int*)malloc(sizeof(int) * count);
//
// memcpy(positive, temp, sizeof(int) * count);
//
// return positive;
//
//}

int getCount(int arr[]){
int i, count=0;
for(i=0;arr[i] != DELI; ++i){
count++;
}
return count;
}

int *addedArray(int a1[], int a2[]){
int count = getCount(a1) + getCount(a2);
int *positive = (int*)malloc(sizeof(int) * (count + 1));
memcpy(positive, a1, sizeof(int) * getCount(a1));
memcpy(positive + getCount(a1), a2, sizeof(int) * getCount(a2));
positive[count++] = DELI;
return positive;
}

// int getPositionWithCount(int original[], int *count){
// int i;
// int temp[MAX];
// int count = 0;
// for(i=0; original[i] != DELI; ++i){
// if(original[i] > 0){
// temp[count++] = original[i];
// }
// }
// temp[count++] = DELI;
// *count = count;
// int *positive = (int*)malloc(sizeof(int) * count);
// memcpy(positive, temp, sizeof(int) * count);
// return positive;
// }

// int *getPositiveWithCount(int arr[], int n, int *count) {
//     int temp[n];
//     int count = 0;

//     for(int i = 0; i < n; ++i) {
//         if(arr[i] > 0) {
//             temp[count++] = arr[i];
//         }
//     }

//     int *posNum = malloc(sizeof(int) * count);

//     if(posNum != NULL) {
//         memcpy(posNum, temp, sizeof(int) * count);
//     }
//     *size = count;

//     return posNum;
// }

int *getPositiveWithCount(int arr[], int n, int *count) {
    int temp[n];
    int localCount = 0;

    for(int i = 0; i < n; ++i) {
        if(arr[i] > 0) {
            temp[localCount++] = arr[i];
        }
    }

    int *posNum = malloc(sizeof(int) * localCount);

    if(posNum != NULL) {
        memcpy(posNum, temp, sizeof(int) * localCount);
    } else {
        // Handle memory allocation failure
        *count = 0;
        return NULL;
    }

    *count = localCount;

    return posNum;
}