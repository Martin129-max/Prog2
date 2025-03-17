int *getFactors(int arr[], int size, int item, int *factorSize){
    int count = 0;
    int *newArr = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        if(item % arr[i] == 0){
            newArr[count] = arr[i];
            count++;
        }
    }
    *factorSize = count;
    return newArr;
}

int countPrimeNumbers(int arr[], int size){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] < 2){
            continue;
        }
        int isPrime = 1;
        for(int j = 2; j*j <= arr[i]; j++){
            if(arr[i] % j == 0){
                isPrime = 0;
                break;
            }
        }
        if(isPrime){
            count++;
        }
    }   
    return count;
}

int oddCounter(int arr[], int size){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 != 0){
            count++;
        }
    }
    return count;
}

int *allAboveAverage(int arr[], int size, int *count){
    int sum=0;
    int counter = 0;
    int *arrNew = (int*)malloc(sizeof(int) * size);
    for(int i=0;i<size;i++){
        sum += arr[i];
    }
    float avg = (float)sum/size;
    for(int i=0;i<size;i++){
        if(arr[i] > avg){
            arrNew[counter] = arr[i];
            counter++;
        }
    }
    *count = counter;
    return arrNew;
}

int *arrReverser(int arr[], int size){
    int *arrNew = (int*)malloc(sizeof(int) * size);
    for(int i=0;i<size;i++){
        arrNew[i] = arr[size-i-1];
    }
    return arrNew;
}

