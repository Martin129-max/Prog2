#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define DELI -101

void display(int arr[]);
int *getPositive(int original[]);
int *addedArray(int a1[], int a2[]);
int getCount(int arr[]);

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
	
int count1 = getCount(a1);
int count2 = getCount(a2);
int temp[count1 + count2];

// printf("%d %d", count1, count2);   TEST

temp[count1+count2] = DELI;

int *positive = (int*)malloc(sizeof(int) * (count1));
int *positive2 = (int*)malloc(sizeof(int) * (count2+count1));
memcpy(positive, a1, sizeof(int) * count1);
memcpy((int*)positive2[count1], positive, sizeof(int) * (count1+count2));
// memcpy(positive, temp, sizeof(int) * count2);

return positive;

}

