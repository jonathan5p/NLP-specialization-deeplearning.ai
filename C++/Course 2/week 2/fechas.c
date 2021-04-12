
#include <stdio.h>

typedef enum month
{jan,feb, march, apr, may,jun,jul,aug,sep,oct,nov,dec} month;
typedef struct date {month m;int d;} date;


void printdate(date d){

    switch (d.m)
    {
    case jan: 
        printf("the date is January %d \n",d.d); 
    break;
    case feb:
        printf("the date is February %d \n", d.d);
        break;
    case march:
        printf("the date is March %d \n", d.d);
        break;
    case apr:
        printf("the date is April %d \n", d.d);
        break;
    case may:
        printf("the date is May %d \n", d.d);
        break;
    case jun:
        printf("the date is June %d \n", d.d);
        break;
    case jul:
        printf("the date is July %d \n", d.d);
        break;
    case aug:
        printf("the date is August %d \n", d.d);
        break;
    case sep:
        printf("the date is September %d \n", d.d);
        break;
    case oct:
        printf("the date is October %d \n", d.d);
        break;
    case nov:
        printf("the date is November %d \n", d.d);
        break;
    case dec:
        printf("the date is December %d \n", d.d);
        break;
    default:
        printf("Please enter a valid month \n");
        break;
    }

}

date nextday(date d, int n[]){
    date f; 
    if ((d.d)==n[d.m]){
        f.d = 1;
        f.m = (d.m + 1) % 12;
    }
    else{
        f.d = d.d+1;
        f.m = d.m;
    }
    return f;
}

void main(){

int long_months[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
int i=0;
date f1 = {oct, 31}, f2;
printf("Current day: \n");
printdate(f1);
f2 = nextday(f1,long_months);
printf("Next day: \n");
printdate(f2);
}