#include<stdio.h>

struct date{
    int day;
    int month;
    int year;
};

int Leap(int year) {
    if(year%4==0 && (year%100!=0 || year%400==0)){
        return 1;
    }
    return 0;
}


int calculateDays(struct date d){
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = d.year*365 + d.year/4 - d.year/100 + d.year/400;
    if(Leap(d.year)){
        monthDays[1]=29;
    }
    for (int i=0; i<d.month-1; i++){
        days += monthDays[i];
    }
    days+=d.day;

    return days;
}


int main(){
    struct date d1, d2;
    printf("PLEASE ENTER CORRECT DAYS, ABSURD DATES WOULD GENERATE WRONG RESULTS\n");
    printf("ENTER THE STARTING DATE IN THE FORMAT (DD MM YYYY): ");
    scanf("%d %d %d", &d1.day, &d1.month, &d1.year);
    printf("ENTER THE ENDING DATE IN THE FORMAT (DD MM YYYY): ");
    scanf("%d %d %d", &d2.day, &d2.month, &d2.year);

    int days1 = calculateDays(d1);
    int days2 = calculateDays(d2);

    if(days1>days2){
        printf("ENDING DATE SHOULD BE AFTER STARTING DATE.");
    }
    else{
        printf("THE NUMBER OF DAYS BETWEEN THE GIVEN DATES ARE: %d", days2 - days1);
    }

    return 0;
}
