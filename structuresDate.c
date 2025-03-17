#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int day;
    int month;
    int year;
} Date;

Date createDate(int d, int m, int y);
void displayDate(Date d);
Date dateDifference(Date d1, Date d2);

int main(){
    int day, month, year;
    printf("Enter date 1 (dd/mm/yyyy):" ); scanf("%d/%d/%d", &day, &month, &year);
    Date d1 = createDate(day, month, year);
    displayDate(d1);
    return 0;
}

Date createDate(int day, int month, int year){
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    return date;
}

void displayDate(Date d){
    if(d.month == 0 && d.year == 0){
        printf("%d", d.day);
    }else{
    printf("%d/%d/%d", d.day, d.month, d.year);
    }
}

// Date dateDifference(Date d1, Date d2){
//     Date diff;
//     diff.day = d1.day - d2.day;
//     diff.month = d1.month - d2.month;
//     diff.year = d1.year - d2.year;
//     return diff;
// }

Date dateDifferenceInDays(Date d1, Date d2){
    Date diff;
    int days = 0;
    days += (d1.year - d2.year) * 365;
    days += (d1.month - d2.month) * 30;
    days += d1.day - d2.day;
    diff.day = days;
    return diff;
}