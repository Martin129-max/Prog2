#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int hrs;
    int min;
}Time;

Time createTime(int h, int m);
void displayMilitaryTime(Time m);
Time timeDifferenceM(Time t1, Time t2); //return minutes
Time timeDifferenceHM(Time t1, Time t2);; //return hrs and mins
int convertToMinutes(Time m);
Time timeStandard(Time t1);

int main(){
    int hour, min;
    int ch;
    printf("Enter current hour: "); scanf("%d", &hour);
    printf("Enter current minute: "); scanf("%d", &min);
    printf("[1]AM or [2]PM?: "); scanf("%d", &ch);
    if(ch == 2){
        hour += 12;
    }
    Time t1 = createTime(hour, min);
    displayMilitaryTime(t1);

    printf("Enter current hour: "); scanf("%d", &hour);
    printf("Enter current minute: "); scanf("%d", &min);
    printf("[1]AM or [2]PM?: "); scanf("%d", &ch);
    if(ch == 2){
        hour += 12;
    }
    Time t2 = createTime(hour, min);
    displayMilitaryTime(t2);

    printf("Time Difference in minutes:\n");
    displayMilitaryTime(timeDifferenceM(t1, t2));
    printf("Time Difference in hours and minutes:\n");
    displayMilitaryTime(timeDifferenceHM(t1,t2));
}

Time createTime(int h, int m){
    Time time;
    time.hrs = h;
    time.min = m;
    return time;
}

void displayMilitaryTime(Time m){
    if(m.hrs == 0){
        printf("%.2d minutes\n", m.min);
    }else{
        printf("%.2d : %.2d\n", m.hrs, m.min);
    }
}

Time timeDifferenceHM(Time t1, Time t2){
    Time timeDiff;
    if(convertToMinutes(t1) > convertToMinutes(t2)){
        timeDiff = timeDifferenceM(t1, t2);
    }else{
        timeDiff = timeDifferenceM(t2, t1);
    }
    timeDiff.hrs = timeDiff.min/60;
    timeDiff.min = timeDiff.min%60;
    return timeDiff;
}
// Time timeDifferenceHM(Time t1, Time t2){
//     Time timeDiff;
//     int diff;
//     diff = convertToMinutes(t1) - convertToMinutes(t2);
//     timeDiff.hrs = diff/60;
//     timeDiff.min = diff%60;
//     return timeDiff;
// }

Time timeDifferenceM(Time t1, Time t2){
    Time diff;
    diff.min = convertToMinutes(t1) - convertToMinutes(t2);
    diff.hrs = 0;
    return diff;
}

int convertToMinutes(Time m){
    int mins;
    mins = m.hrs * 60;
    return mins + m.min;
}

void displayTimeStandard(Time t1){
    if(t1.hrs > 12){
        printf("%.2d : %.2d PM\n", t1.hrs - 12, t1.min);
    }else{
        printf("%.2d : %.2d AM\n", t1.hrs, t1.min);
    }
}